#define analog_in 0
unsigned long temps1;
unsigned long temps2;
float periode;          //initialisation des variables 
long analogue;
short condition = 750;    
#include <Arduino.h>
#include "cardio.h"
#include "coeur.h"
#include "param.h"
byte n;
byte LED = 3;

void setup()
{
  for (n = 3; n <= 12; n++)  //initialisations des LEDs en sortie 
  {
    pinMode(n, OUTPUT);
  }
  Serial.begin(19200);
  temps2 = 0;
}

void loop()
{
  temps1 = millis();                  
  analogue = analogRead(analog_in);   //je lis le signal de la broche A0

  if (condition >= analogue)          //je compare pour détecter un signal, condition corresspond a notre seuil de détection
  {
    switch(param)
    {
      case 1: case 2:
        allumer_les_LED(3, param2); 
        break;
      case 3:
        fonction_chenille(LED) ;    
        
        LED = LED + 1;
        if (LED == 13)
        {
          LED = 3;
        }
        break;
      case 4:
        fonction_pilotage();
        break;
    }

    float BPM = pouls(temps1, temps2); //appel de la fonction pour calculer le BPM(pulsation par minute)
    temps2 = temps1;

    Serial.print(millis());         
    Serial.print(';');                //affichage des données sur le moniteur série en mode CSV.
    Serial.println((int)BPM);

    while (condition + 100 >= analogue)   //Ce whille sert a bloquer le programme jusqu'à que ce qu'analogue soit inférieur à ma condtion.
                                          //Le +100 sert à empécher que le calcul du pouls soit fait deux fois de suite. 
    {
      analogue = analogRead(analog_in);
    }
  }
  
  for (n = 3; n <= 12; n = n + 1)        // permet d'éteindre toutes les LEDs lorsqu'il n'y à pas de pouls 
  {
    digitalWrite(n, LOW);
  }
}
