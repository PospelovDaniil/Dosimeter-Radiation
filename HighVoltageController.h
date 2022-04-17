#include <stdint.h>
#include "utils.h"

class HV_Controller
{
public:
  HV_Controller() = delete;
  HV_Controller(uint8_t mosfetPin):m_mosfetPin(mosfetPin) {}

  CLASS_PROPERTY(uint8_t, mosfetPin)
  CLASS_PROPERTY(uint16_t, targetVoltage)
  CLASS_PROPERTY(uint16_t, frequency)
  CLASS_PROPERTY(bool, isWork)
};