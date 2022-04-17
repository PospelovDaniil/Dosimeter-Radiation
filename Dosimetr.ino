#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"

#include <Preferences.h>
#include "TFT_eSPI.h"

#include "SoundNotification.h"
#include "HighVoltageController.h"
#include "GUI.h"
#include "DosimetrController.h"

#ifdef ESP8266
  #define MOSFET_PIN    D2 //4
  #define DEVICE_SOUND  D1 //5
#elif defined ESP32
  #define MOSFET_PIN    27
  #define DEVICE_SOUND  36
#endif

TFT_eSPI tft     = TFT_eSPI();
HV_Controller      hv_controller(MOSFET_PIN);
SoundNotification  soundDevice(DEVICE_SOUND);
GUI                GUI(&tft);
DosimetrController DosimetrController();

void setup()
{
  Serial.begin(115200);

  hv_controller.set_isWork(false);
  hv_controller.set_targetVoltage(400);
  hv_controller.set_frequency(20000);

  soundDevice.set_volume(70); // percent
  soundDevice.set_frequency(10000); // hz
}

void loop()
{

}
