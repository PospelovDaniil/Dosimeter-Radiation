#include <stdint.h>
#include "utils.h"
#include "HighVoltageController.h"
#include "SoundNotification.h"
#include "GUI.h"

class DosimetrController
{
public:
  DosimetrController() = delete;
  DosimetrController(HV_Controller *pHV_controller, GUI *pUI = nullptr, SoundNotification *pSoundDevice = nullptr):hv(pHV_controller), ui(pUI), sound(pSoundDevice) {}

private:
  HV_Controller     *hv    = nullptr;
  GUI               *ui    = nullptr;
  SoundNotification *sound = nullptr;
};