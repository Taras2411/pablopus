#include <Arduino.h>

// MAX7219 < 4, 1, D6, D7, D8 > mtrx;
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
#include "Fonts/FontsRus/Bahamas6.h"
#include "Fonts/Org_01.h"
// #include <Fonts/>

int pinCS = D1; // Attach CS to this pin, DIN to MOSI and CLK to SCK (cf http://arduino.cc/en/Reference/SPI )
int numberOfHorizontalDisplays = 4;
int numberOfVerticalDisplays = 1;

Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

String tape = "? ???? ??? ?????? qwertyuiop";
int wait = 25; // In milliseconds

int spacer = 1;
int width = 5 + spacer; // The font width is 5 pixels

void setup()
{

  matrix.setIntensity(7); // Use a value between 0 and 15 for brightness

  // Adjust to your own needs
  matrix.setPosition(0, 0, 0); // The first display is at <0, 0>
  matrix.setPosition(1, 1, 0); // The second display is at <1, 0>
  matrix.setPosition(2, 2, 0); // The third display is at <2, 0>
  matrix.setPosition(3, 3, 0); // And the last display is at <3, 0>
  matrix.setPosition(4, 4, 0);
  matrix.setPosition(5, 5, 0);
  matrix.setPosition(6, 6, 0);
  matrix.setPosition(7, 7, 0);

  matrix.setRotation(0, 1);    // The first display is position upside down
  matrix.setRotation(1, 1);    // The first display is position upside down
  matrix.setRotation(2, 1);    // The first display is position upside down
  matrix.setRotation(3, 1);    // The first display is position upside down
  matrix.setRotation(4, 1);    // The first display is position upside down
  matrix.setRotation(5, 1);    // The first display is position upside down
  matrix.setRotation(6, 1);    // The first display is position upside down
  matrix.setRotation(7, 1);    // The first display is position upside down

  // matrix.setFont(&Org_01);
  //  matrix.setRotation(3, 2);    // The same hold for the last display
}

void loop()
{
  // matrix.drawChar(0, 0, '2', HIGH, LOW, 1);
  // matrix.drawChar(6, 0, '0', HIGH, LOW, 1);
  // matrix.drawChar(12, 0, '7', HIGH, LOW, 1);
  // matrix.drawChar(18, 0, '7', HIGH, LOW, 1);
  matrix.drawLine(0,0,7,63,1);
  matrix.write();
  // for (int i = 0; i < width * tape.length() + matrix.width() - 1 - spacer; i++)
  // {

  //   matrix.fillScreen(LOW);

  //   int letter = i / width;
  //   int x = (matrix.width() - 1) - i % width;
  //   int y = (matrix.height() - 8) / 2; // center the text vertically

  //   while (x + width - spacer >= 0 && letter >= 0)
  //   {
  //     if (letter < tape.length())
  //     {
  //       matrix.drawChar(x, y, tape[letter], HIGH, LOW, 1);
  //     }

  //     letter--;
  //     x -= width;
  //   }

  //   matrix.write(); // Send bitmap to display

  //   delay(wait);
  // }
}
