// UTFT_Rotate_Bitmap 
// Copyright (C)2015 Rinky-Dink Electronics, Henning Karlsen. All right reserved
// web: http://www.RinkyDinkElectronics.com/
//
// This program is a demo of the drawBitmap()-function.
//
// This program requires the UTFT library.
//

#include <UTFT.h>

// Remember to change the model parameter to suit your display module!
UTFT myGLCD(HX8352A, 12, 14, 27, 26, 25);

extern unsigned short biohazard[0x1000];

void setup()
{
  myGLCD.InitLCD(LANDSCAPE);
  myGLCD.fillScr(255, 255, 255);
  myGLCD.setColor(0, 0, 0);
}

void loop()
{
    for (int i=0; i<360; i+=5)
    {
      myGLCD.drawBitmap (10, 10, 64, 64, biohazard, i, 32, 32);
    }
}

