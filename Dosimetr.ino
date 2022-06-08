#ifdef ESP32
#include "freertos/FreeRTOS.h" // because i cant include freertos for 8266 :/
#include "freertos/task.h"
#include "esp_system.h"
#include <Preferences.h> // not used yet
#endif

#include "TFT_eSPI.h"

#include "DosimetrController.h"

#ifdef ESP8266
  #define MOSFET_PIN    D2 //4
  #define ADC_PIN       A0
  #define DEVICE_SOUND  D1 //5

  #define BTN_REBOOT               0 // need set pins
  #define BTN_SET_DEFAULT_SETTINGS 0
  #define SW_WIFI_ON               0
  #define SW_WIFI_OFF              0
#elif defined ESP32
  #define MOSFET_PIN    27
  #define ADC_PIN       35
  #define DEVICE_SOUND  36

  #define BTN_REBOOT               0 // need set pins
  #define BTN_SET_DEFAULT_SETTINGS 0
  #define SW_WIFI_ON               0
  #define SW_WIFI_OFF              0
#endif


TFT_eSPI tft     = TFT_eSPI();
HV_Controller      hv_controller(MOSFET_PIN, ADC_PIN);
SoundNotification  soundDevice(DEVICE_SOUND);
GUI                ui(&tft);
DosimetrController dosimetrController(&hv_controller, &ui, &soundDevice);

void setup()
{
  Serial.begin(115200);

  hv_controller.set_isWork(false);
  hv_controller.set_targetVoltage(400);
  hv_controller.set_frequency(20000); // hz
  hv_controller.set_dutycycle(1); // range 0-100
  hv_controller.set_threshold(15); // volt +- possible deviation voltage

  soundDevice.set_volume(70); // percent
  soundDevice.set_frequency(10000); // hz

  #ifdef DEBUG_MODE
  hv_controller.test();
  soundDevice.test();
  ui.test();
  #endif
}

void loop()
{
#ifdef ESP8266

#elif defined ESP32
// freeRTOS base code
#endif
}
