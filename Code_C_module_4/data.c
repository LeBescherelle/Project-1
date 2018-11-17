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


FILE* open_file(char* path, char* openingMode)
{
	FILE* file = fopen(path, openingMode);

	if (file == NULL)	//On vérifie que l'ouverture s'est effectuée sans problèmes.
		exit(EXIT_FAILURE);

	return file;
}


static void uptade_tab_memory(void** tab, size_t size)
{
	void *buffer = realloc(*tab, size);	//Réallocation de *tab dans un pointeur void.

	if (buffer != NULL)	//On vérifie que la réallocation s'est effectué sans erreurs.
		*tab = buffer;	//On applique la réallocation que si elle a fonctionné. On évite ainsi les fuites de mémoire.
	else
		exit(EXIT_FAILURE);
}


void split_save_line(char *toSplit, int *first, int *second)
{
	char *token = strtok(toSplit, ";");	//Récupère la partie gauche de la chaine à partir du ";".
	int i = 0;

	while (token != NULL)
	{
		if (!i)	//Si c'est le premier élement.
			*first = atoi(token);	//Converti une chaine de caractère en int (grâce à atoi) et l'enregistre.
		else
			*second = atoi(token);

		token = strtok(NULL, ";");	//Récupère la partie suivante après le ";".
		i++;
	}
}


int get_tab_size(Data_Line *tab)
{
	int i = 0;

	while (1) {

		if (tab[i].time == 0) //Le dernier élement du tableau a un time de 0;
			return i;

		i++;
	}
}


Data_Line* tab_fill_data()
{
	Data_Line *tab =  malloc(sizeof(Data_Line));

	FILE* dataFile = open_file("sketch_181116a/Battements.csv", "r");
	char lineContent[100] = "";
	int i = 0;
	int firstLine = 1; //variable qui permet de ne pas enregistrer la première ligne du fichier.

	while (fgets(lineContent, 100, dataFile) != NULL) //Tant que fgets n'est pas arrivé à la fin du fichier.
	{
		if (!firstLine) //On enregistre pas la première ligne qui est souvent perturbée.
		{
			split_save_line(lineContent, &(tab[i].time), &(tab[i].heartRate)); //On enregistre les deux valeurs de la chaine lue dans notre tableau de données.
			i++;
			uptade_tab_memory(&tab, (i + 1) * sizeof(Data_Line)); //On alloue dynamiquement une nouvelle case à notre tableau.
			
		}
		else
			firstLine = 0;
	}

	//Le dernier élement de notre tableau a un temps de 0 (on peut ainsi calculer la taille du tableau facilement).
	uptade_tab_memory(&tab, (i + 1) * sizeof(Data_Line));
	tab[i].time = 0;

	fclose(dataFile);

	return tab;
}
