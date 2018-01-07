#include <Arduino.h>
#include "SimpleTimer.h"
#include "fonctions.h"
#include "pin_table.h"

//Déclaration de pins de la carte utilisées
//char pin_L3=13;
char pin_potar=A7;
char pin_bouton=4;
char pin_base=6;
char pin_thermistance=A5;

//Déclaration des valeurs manipulées
short int val_potar=0;
short int duty=10;
short int val_bouton=0;
short int set_duty=0;
float     T_cycle=0;
float     Te=500;
int       iteration=0;
short int val_thermistance=0;
short int a=0;
long temps=0;
float frequence_echantillonnage=50;
int Set_point=900;
int somme_erreur=0;
SimpleTimer timer; 
  
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pin_potar,INPUT);
pinMode(pin_bouton,INPUT);
pinMode(pin_base,OUTPUT);
digitalWrite(pin_base, HIGH) ;
T_cycle=500;
Te=T_cycle/100;
Serial.println("iteration,temps,duty,set_duty,val_thermistance,val_bouton");
timer.setInterval(1000/frequence_echantillonnage, asservissement);  // Interruption pour calcul du PID et asservissement
}

void loop() {
///Lecture des entrées de la carte
timer.run();
iteration++;

set_duty=regler_rp(val_bouton,duty,a,set_duty);  //Permet de régler le rapport cyclique lors de l'appuie sur un bouton
temps=millis();

// FUCKING C !!!
set_duty=a;
alim(set_duty, Te, pin_base);         //Permet d'alimenter le corps de chauffe avec le rapport cyclique indiqué
//delay(1000);
}

/* Interruption pour calcul du PID */
void asservissement()
{ 
// FUCKING B !!!
affiche(iteration,temps,duty,set_duty,val_thermistance,val_bouton);

val_potar=analogRead(pin_potar);
val_bouton=digitalRead(pin_bouton);
val_thermistance=analogRead(pin_thermistance);
//Conversion des valeurs analogiques issues du potentiomètre en % du rapport cyclique
duty=map(val_potar,0,1023,0,100);

  float Kp=1, Kc=0.909;
  short int Ti=270;
  float erreur=Set_point-val_thermistance;
  somme_erreur=somme_erreur+erreur*1/frequence_echantillonnage;
  float cmd=Kp*erreur+Kp/Ti*somme_erreur;
  
  if (cmd>100){
    cmd=100;
  }
  else
  ;
  a=cmd;
  Serial.println(cmd);
}

