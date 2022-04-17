#include <stdint.h>
#include "utils.h"

class SoundNotification
{
public:
  SoundNotification() = delete;
  SoundNotification(const uint8_t devicePin):m_devicePin(devicePin)
  {
    CLEAN(&m_volume);
    CLEAN(&m_frequency);
  }

  void play_s(const    uint8_t duration_play) const;
  void play_ms(const  uint16_t duration_play) const;
  void play_mcs(const uint32_t duration_play) const;
  void play_ns(const  uint64_t duration_play) const;

  CLASS_PROPERTY(uint8_t, devicePin)
  CLASS_PROPERTY(uint8_t, volume)
  CLASS_PROPERTY(uint16_t, frequency)

  #ifdef DEBUG_MODE
  void test()
  {
    play_s(1);
  }
  #endif
};