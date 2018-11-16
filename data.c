/**
	*@file data.c
	*@brief Implémentation des fonctions de gestion des données.
	*@author Antonin
	*@version 1.0
	*@date 12 novembre 2018
	*
	*Extrait les données du fichier csv et contrôle la structure de données.
*/

#include "data.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


FILE* open_file(char* path, char* openingMode)
{
	FILE* file = fopen(path, openingMode);

	if (file == NULL)
		exit(EXIT_FAILURE);

	return file;
}


static void uptade_tab_memory(void** tab, size_t size)
{
	/*
		Réallocation de l'espace mémoire dans un buffer 
		puis vérifie que l'allocation a fonctionné.
		Si l'allocation a fonctionné on l'attribut à notre tableau.
	*/
	void *buffer = realloc(*tab, size);

	if (buffer != NULL)
		*tab = buffer;
	else
		exit(EXIT_FAILURE);
}


void replace_char(char *toChange, char toFind, char toReplace)
{
	/*
		Utilise la fonction strchr de string.h pour
		rechercher un caractère dans la chaine.
		Puis le remplace par un autre.
	*/
	char *finded = strchr(toChange, toFind);
	while (finded)
	{
		*finded = toReplace;
		finded = strchr(finded, toFind);
	}	
}


void split_save_line(char *toSplit, int *first, float *second)
{
	/*
		Sépare la chaine de caractère grâce à la fonction
		strtok de string.h dès quelle rencontre
		un point virgule, puis enregistre les deux parties
		dans deux variables.
	*/
	char *token = strtok(toSplit, ";");
	int i = 0;

	while (token != NULL)
	{
		if (!i)
			*first = atof(token);
		else
			*second = atoi(token);

		token = strtok(NULL, ";");
		i++;
	}
}


static void delete_specials_characters(char *toChange)
{
	/*
		Supprime les caractère spéciaux si il y en a.
	*/
	char lineBuffer[20];
	int i = 0, j = 0;

	while (1)
	{
		if (isdigit(toChange[i])) {
			lineBuffer[j] = toChange[i];
			j++;
		}

		if (toChange[i] == '\0') {
			for (int y = 0; y <= j; y++)
			{
				toChange[y] = lineBuffer[y];
			}
			break;
		}
		i++;
	}
}


int get_tab_size(Data_Line *tab)
{
	int i = 0;

	while (1) {

		if (tab[i].time == 0)
			return i;

		i++;
	}
}


static void tab_write(Data_Line* tab, char* toWrite, int pos)
{
	if (pos == 1 && !isdigit(toWrite[1]))
		delete_specials_characters(toWrite);

	replace_char(toWrite, ',', '.');
	split_save_line(toWrite, &(tab[pos - 1].time), &(tab[pos - 1].heartRate));
}


Data_Line* tab_fill_data()
{
	Data_Line *tab = malloc(sizeof(Data_Line));

	FILE* dataFile = open_file("C:/Users/Antonin/Desktop/Capteur/capteur_de_pouls/sketch_181116a/Battements.csv", "r");
	char lineContent[100] = "";
	int count = 1;
	int i = 0;

	while (fgets(lineContent, 100, dataFile) != NULL)
	{
		if (i != 0) {
			tab_write(tab, lineContent, count);
			count++;
			uptade_tab_memory(&tab, count * sizeof(Data_Line));
		}
		else
			i++;
	}

	tab[count - 1].time = 0;

	fclose(dataFile);

	return tab;
}
