#include "cardio.h"

float pouls(unsigned long temps1, unsigned long temps2)
{
  float periode = temps1 - temps2;  //je calcul la période entre de pics de signal
  return (60 / (periode * 0.001));  //ma période me permet de calculer le pouls de manière instantané 
}
