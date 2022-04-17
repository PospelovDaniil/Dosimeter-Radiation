#include "HighVoltageController.h"

void HV_Controller::task_generate() noexcept
{
  for(;;)
  {
    generate();
  }
}

void HV_Controller::generate() noexcept
{
  if(m_isWork)
  {
      uint16_t currentVoltage = get_ADCValue() * m_multiplayADC;

      uint16_t low_range = m_targetVoltage - m_threshold;
      uint16_t up_range  = m_targetVoltage + m_threshold; // need optimization, move to setter, temp impl
      if((currentVoltage >= low_range)&&(currentVoltage <= up_range)) return;

      m_dutycycle = (currentVoltage < m_targetVoltage)? m_dutycycle + 1: m_dutycycle - 1;
      analogWrite(m_mosfetPin, m_dutycycle);
  }
}

inline uint16_t HV_Controller::get_ADCValue() const noexcept
{
  #ifdef ESP8266
  return analogRead(m_ADCPin);
  #elif defined ESP32
  // adc1_config_channel_atten
  #error not impl HV_Controller::get_ADCValue() esp32
  adc_power_on();
  int res = adc1_get_raw();
  adc_power_off();
  return res;
  #endif
}