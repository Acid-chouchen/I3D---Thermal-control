#include <stdlib.h>
#include <stdio.h>
#include <Arduino.h>
#include "fonctions.h"



void affiche(short int a,long b,short int c, short int d,short int e,short int f){
Serial.print(a);Serial.print("  ");Serial.print(b);Serial.print("  ");Serial.print(c);Serial.print("  ");Serial.print(d);Serial.print("  ");Serial.print(e);Serial.print("  "),Serial.println(f);
}


void alim(short int set_duty, float Te, char pin_base){
  for (int i=0;i<100;i++){
  if(i<set_duty){
    digitalWrite(pin_base, LOW) ;
    delay(Te);
  }
  else
  digitalWrite(pin_base, HIGH) ;
  delay(Te);
  }
}

short int regler_rp(short int val_bouton, short int duty,short int a,short int set_duty){
  //Réglage du rapport cyclique par appuye sur le bouton
  if (val_bouton==1){
    a=duty;
  }
  else
  a=set_duty;
  return(a);  
}

short int commande(short int e){
  int Co=0;
  float Kc=0.909, Ti=3000;
  float  E=Co;
  Co=Kc*e+Kc/Ti*E;
  return(Co);
}


