#include <stdio.h>
#include <stdlib.h>
#include "GenerationCode.h"

void erase_fichier()
{
    FILE *pointeur;
    pointeur = fopen("C:/Users/Mokka003/Desktop/Projet/Module2/Clignotement/param.h","w+");
    fclose(pointeur);
}

void ecrire_choix(int param)
{


    FILE *pointeur;
    pointeur = fopen("C:/Users/Mokka003/Desktop/Projet/Module2/Clignotement/param.h", "a+");
    if (pointeur == NULL)
    {
        printf("erreur \n");
        exit(-1);
    }
    fprintf(pointeur, "%s %d", "#define param", param);
    if (param == 2)
    {
        int a;
        printf("une LED sur combien doit etre allume (ne doit pas exceder 10 et ne pas etre egale a 0) ?\n");
        scanf("%d", &a);
        if ((a > 10))
        {
            exit(-1);
        }
        if ((a==0))
        {
            printf("0 impossible, la valeur sera defini par defaut sur 1\n");
            a=1;
        }
        if (pointeur == NULL)
        {
            printf("erreur \n");
            exit(-1);
        }


        fprintf(pointeur, "%s %d\n", "#define param2", a);

    }
        if (param == 4)
        {
            int a;
            printf("Entrer la valeur de la LED a faire clignoter) ?\n");
            scanf("%d", &a);
            if ((a > 10))
            {
                exit(-1);
            }
            if ((a==0))
            {
                printf("0 impossible, la valeur sera defini par defaut sur 1\n");
                a=1;
            }
            else
            {
                fprintf(pointeur, "\n%s %d", "#define param2", a);



            }
        }
        else
        {
            fprintf(pointeur, "\n%s 0", "#define param2");

        }




    fclose(pointeur);
}






