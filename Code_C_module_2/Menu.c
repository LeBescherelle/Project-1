#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"

int afficher_menu(){
    int a, choix2;
printf("---------------------------------------------\n");
printf("    Choissisez votre schema de commande \n---------------------------------------------\n");
printf("\n\n1 ------------------------- Mode Standard \n\n");
printf("2 ------------------------- Mode Alterne\n\n");
printf("3 ------------------------- Mode Chenillard\n\n");
printf("4 ------------------------- Mode Personalise\n\n");
printf("Votre choix : ");
scanf("%d", &a);
if (a > 4){
    printf("erreur \n");
    exit(-1);
    }else {
        return a;

}
}



void demander_localisation(){
printf("fait \n");
}


