#include <stdint.h>
#include "utils.h"
#include "HighVoltageController.h"
#include "SoundNotification.h"
#include "GUI.h"

enum class GeigerCounter:uint8_t
{
  SBM_20 = 0,
  SBM_20_1,
  BETA_1,
  BETA_1_1,
  BETA_2,
  BETA_2_1
};

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

