#include <stdint.h>
#include "utils.h"
#include "TFT_eSPI.h"

class GUI
{
public:
  GUI() = delete;
  GUI(TFT_eSPI *tft):m_pTFT(tft) {}

  #ifdef DEBUG_MODE
  void test()
  {
    // ui
  }
  #endif

private:
  TFT_eSPI *m_pTFT = nullptr;
};