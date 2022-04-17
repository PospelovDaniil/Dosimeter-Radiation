#include <stdint.h>
#include "utils.h"

class SoundNotification
{
public:
  SoundNotification() = delete;
  SoundNotification(const uint8_t devicePin):m_devicePin(devicePin) {}

  void play_s(  uint8_t duration_play) const;
  void play_ms(uint16_t duration_play) const;
  void play_ns(uint32_t duration_play) const;

  CLASS_PROPERTY(uint8_t, devicePin)
  CLASS_PROPERTY(uint8_t, volume)
  CLASS_PROPERTY(uint16_t, frequency)
};