#include "HighVoltageController.h"

void HV_Controller::task_work() noexcept
{
  if(m_isWork)
  {
      // generate HV
  }
}

inline uint16_t HV_Controller::get_ADCValue() const noexcept
{
  #ifdef ESP8266
  return analogRead(m_ADCPin);
  #elif defined ESP32
  // adc1_config_channel_atten
  #error not impl
  adc_power_on();
  int res = adc1_get_raw();
  adc_power_off();
  return res;
  #endif
}