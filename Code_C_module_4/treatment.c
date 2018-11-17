/**
	*@file treatment.c
	*@brief Implémentation des fonctions de traitement des données.
	*@author Antonin
	*@version 1.0
	*@date 15 novembre 2018
	*
	*Effectue des traitements sur les données.
*/

#include "treatment.h"


void display_all_data(Data_Line* data, size_t size)
{
	printf("Donnees : \n\n");

	for (int i = 0; i < size; i++) //On parcourt le tableau et on affiche chaque ligne de données.
		printf("%d ms -> %d bpm\n", data[i].time, data[i].heartRate);
}


void display_all_file()
{
	FILE* file = open_file("sketch_181116a/Battements.csv", "r");
	char lineContent[100];
	int ms;
	int bpm;
	int firstLine = 1; //variable qui permet de ne pas lire la première ligne du fichier.

	while (fgets(lineContent, 100, file)) //Tant que fgets n'est pas arrivé à la fin du fichier.
	{
		if (!firstLine) //On ne lit pas la première ligne qui est souvent perturbée.
		{
			split_save_line(lineContent, &ms, &bpm); //On enregistre les deux valeurs de la ligne lu dans deux les deux variables à afficher. 
			printf("%dms -> %d bpm\n", ms, bpm);
		}
		else firstLine = 0;
	}

	fclose(file);
}


int compare_time(Data_Line first, Data_Line second)
{
	return first.time - second.time;
}


int compare_bpm(Data_Line first, Data_Line second)
{
	return first.heartRate - second.heartRate;
}


void tab_sort(Data_Line* tab, size_t size, int(*compareFunction)(Data_Line, Data_Line), int ascending)
{
	int min;
	Data_Line buffer;

	for (int i = 0; i < size; i++) //Le tableau est parcouru en entier.
	{
		min = i; //La nouvelle position dans le tableau est affecté a la valeur minimum.

		for (int j = i; j < size; j++) //Le tableau est de nouveau parcouru en partant de la valeur de i, chaque valeur est comparée pour trouver la plus petite.
		{
			if (ascending) //Tri par ordre croissant.
			{
				if ((*compareFunction)(tab[j], tab[min]) < 0) //Fonction de comparaison entre j et la valeur minimum.
					min = j; //La nouvelle valeur la plus petite est affecté a la valeur minimum.
			}
			else 
			{
				if ((*compareFunction)(tab[j], tab[min]) > 0)
					min = j;
			}
		}

		//La valeur de i est échangé avec la valeur la plus petite qui a été trouvé dans la suite du tableau.
		buffer = tab[i];
		tab[i] = tab[min];
		tab[min] = buffer;
	}
}


Data_Line search_bpm(Data_Line* tab, size_t size, int time)
{
	int timeFinded = 0;
	Data_Line dataFinded = tab[0];

	for (int i = 0; i < size; i++)	//Le tableau est entièrement parcouru.
	{	
		if (tab[i].time <= time && (time - tab[i].time) < (time - timeFinded)) //On vérifie si la valeur peut correspondre à la recherche.
		{
			timeFinded = tab[i].time;
			dataFinded = tab[i];
		}
	}

	return dataFinded;
}


double get_average_pulse(Data_Line* tab, size_t size, int firstTime, int secondTime)
{
	double totalBpm = 0, number = 0;

	for (int i = 0; i < size; i++) //Le tableau est entièrement parcouru.
	{
		if (tab[i].time >= firstTime && tab[i].time <= secondTime) //On vérifie si la valeur se situe dans l'intervalle de temps demandée.
		{
			totalBpm += tab[i].heartRate;
			number++;
		}
	}

	return totalBpm / number; //La moyenne est retournée.
}


void display_max_min_pulse(Data_Line* tab, size_t size)
{
	int min = 0, max = 0;

	for (int i = 0; i < size; i++) //le tableau est entièrement parcouru.
	{
		if (tab[i].heartRate < tab[min].heartRate) //Le minimum de pouls est recherché.
			min = i;
		else if (tab[i].heartRate > tab[max].heartRate) //Le maximum de pouls est recherché.
			max = i;
	}

	printf("Le minimun de pouls etait de %d bpm a %d ms\n", tab[min].heartRate, tab[min].time);
	printf("Le maximum de pouls etait de %d bpm a %d ms", tab[max].heartRate, tab[max].time);
}