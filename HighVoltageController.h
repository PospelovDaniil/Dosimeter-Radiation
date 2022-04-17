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
  }

  void task_work() noexcept;

  CLASS_PROPERTY(bool, isWork)
  // generate hv
  CLASS_PROPERTY(uint8_t,  mosfetPin)
  CLASS_PROPERTY(uint16_t, targetVoltage)
  CLASS_PROPERTY(uint16_t, frequency)
  CLASS_PROPERTY(double,   dutycycle)
  
  // control voltage
  CLASS_PROPERTY(uint8_t, ADCPin)
  CLASS_PROPERTY(uint8_t, threshold)
  inline uint16_t get_ADCValue() const noexcept;

  #ifdef DEBUG_MODE
  void test()
  {
    // generate HV
  }
  #endif
};