#include "coeur.h"
#include "param.h"
#include <Arduino.h>

// Le programmme allume les 10LED en commençant par la LED réferencé par le premier paramètre et décale l'allumage des LED en fonction du deuxième paramètre
void allumer_les_LED(int a, int b)
{
  for (int n = a; n <= a + 9; n = n + 1 + b)
    digitalWrite(n, HIGH);
}

void fonction_chenille(int n)
{
  digitalWrite(n, HIGH);   //j'allume la LED concernée
}

void fonction_pilotage()
{
  digitalWrite(param2 + 2, HIGH); // j'allume la LED choisie 
}
