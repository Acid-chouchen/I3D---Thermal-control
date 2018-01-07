#include <Wire.h>
#include <SeeedOLED.h>
#include "fonctions.h"

bool K=0;
short int ligne=2; //compris entre 0 et 7
int i=0;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  SeeedOled.init();                  //initialze SEEED OLED display
  SeeedOled.clearDisplay();          //clear the screen and set start position to top left corner
  SeeedOled.setNormalDisplay();      //Set display to normal mode (i.e non-inverse mode)
  SeeedOled.setPageMode();           //Set addressing mode to Page Mode
  SeeedOled.setTextXY(0,0);          //Set the cursor to Xth Page, Yth Column  
}

void loop()
{
  i++;
 // SeeedOled.clearDisplay(); 
  affiche_menu(i);  
  K=affiche_curseur(ligne, K);
  ligne++;
  if(ligne>7){
    ligne=0;
  }
  //Serial.println(K);
  delay(1000);
}

