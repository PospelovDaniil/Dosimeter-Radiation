#include <stdint.h>
#include "utils.h"

class HV_Controller
{
public:
  HV_Controller() = delete;
  HV_Controller(const uint8_t mosfetPin, const uint8_t ADCPin):m_mosfetPin(mosfetPin), m_ADCPin(ADCPin)
  {
    CLEAN(&m_targetVoltage);
    CLEAN(&m_frequency);
    CLEAN(&m_dutycycle);
    CLEAN(&m_threshold);
    CLEAN(&m_multiplayADC);
  }

  void task_generate() noexcept; //esp32
  void generate() noexcept;
  void set_dutycycle(const uint8_t dutycycle) noexcept
  {
    #ifdef ESP8266
    m_dutycycle = map(dutycycle, 0, 100, 0, 1023); // its no std::map, arduino spec foo
    #elif defined ESP32
    #endif
  }

  CLASS_PROPERTY(bool, isWork)
  // generate hv
  CLASS_PROPERTY(uint8_t,  mosfetPin)
  CLASS_PROPERTY(uint16_t, targetVoltage)
  CLASS_PROPERTY(uint16_t, frequency)
private:
  uint16_t m_dutycycle;

  // control voltage
  CLASS_PROPERTY(uint8_t, ADCPin)
  CLASS_PROPERTY(uint8_t, threshold)
  CLASS_PROPERTY(uint8_t, multiplayADC)
  inline uint16_t get_ADCValue() const noexcept;

  #ifdef DEBUG_MODE
  void test()
  {
    // generate HV
    // measure
    uint16_t adcValue = get_ADCValue();
    uint16_t currentVoltage = adcValue * m_multiplayADC;
    Serial.println("Measured voltage: %d, multiplay: %d, adc value: %d", currentVoltage, m_multiplayADC, adcValue);
  }
  #endif
};