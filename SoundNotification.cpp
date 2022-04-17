#include "SoundNotification.h"

void SoundNotification::play_s(const uint8_t duration_play) const
{
  tone(m_devicePin, m_frequency, duration_play/1000); // temp impl, no adjast volume
  // tone, but with PWM adjast
}

void SoundNotification::play_ms(const uint16_t duration_play) const
{
  tone(m_devicePin, m_frequency, duration_play); // temp impl, no adjast volume
  // tone, but with PWM adjast
}

void SoundNotification::play_mcs(const uint32_t duration_play) const
{
  tone(m_devicePin, m_frequency, duration_play*1000); // temp impl, no adjast volume
  // tone, but with PWM adjast
}

void SoundNotification::play_ns(const uint64_t duration_play) const
{
  tone(m_devicePin, m_frequency, duration_play*1000000); // temp impl, no adjast volume
  // tone, but with PWM adjast
}