#include "fonctions.h"
#include <SeeedOLED.h>

void affiche_menu(int i){
  SeeedOled.setTextXY(0,0); 
  SeeedOled.putString("0- Menu 0");
  SeeedOled.setTextXY(1,0);
  SeeedOled.putString("1- Menu 1");
  SeeedOled.setTextXY(2,0);
  SeeedOled.putString("2- Menu 2");
  SeeedOled.setTextXY(3,0);
  SeeedOled.putString("3- Menu 3");
  SeeedOled.setTextXY(6,0);
  SeeedOled.putNumber(i);
  SeeedOled.setTextXY(7,0);
  SeeedOled.putNumber(i+1);  
}

bool affiche_curseur(short int ligne,bool K){

  bool J=false;
  for (int i=0;i<8;i++){
  if(i==ligne){
    SeeedOled.setTextXY(i,14);
    SeeedOled.putString("<-");
  }
  else{
    SeeedOled.setTextXY(i,14);
    SeeedOled.putString("  ");    
  }
  K=K^1;    
  }

  Serial.println(ligne);
  return(K);
}



