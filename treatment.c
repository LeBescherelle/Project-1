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

	for (int i = 0; i < size; i++)
		printf("%dms -> %g bpm\n", data[i].time, data[i].heartRate);
}

void display_all_file()
{
	FILE* file = open_file("C:/Users/Antonin/Desktop/Capteur/capteur_de_pouls/sketch_181116a/Battements.csv", "r");
	char lineContent[100];
	int ms;
	float bpm;
	int i = 0;

	while (fgets(lineContent, 100, file))
	{
		if (i != 0)
		{
			replace_char(lineContent, ',', '.');
			split_save_line(lineContent, &ms, &bpm);
			printf("%dms -> %g bpm\n", ms, bpm);
		}
		else i++;
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

	for (int i = 0; i < size; i++)
	{
		min = i;

		for (int j = i; j < size; j++)
		{
			if (ascending)
			{
				if ((*compareFunction)(tab[j], tab[min]) < 0)
					min = j;
			}
			else {
				if ((*compareFunction)(tab[j], tab[min]) > 0)
					min = j;
			}
		}

		buffer = tab[i];
		tab[i] = tab[min];
		tab[min] = buffer;
	}
}

Data_Line search_bpm(Data_Line* tab, size_t size, int time)
{
	int timeFinded = 0;
	Data_Line dataFinded = tab[0];

	for (int i = 0; i < size; i++) {
		if (tab[i].time <= time && (time - tab[i].time) < (time - timeFinded)) 
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

	for (int i = 0; i < size; i++)
	{
		if (tab[i].time >= firstTime && tab[i].time <= secondTime)
		{
			totalBpm += tab[i].heartRate;
			number++;
		}
	}

	return totalBpm / number;
}

void display_max_min_pulse(Data_Line* tab, size_t size)
{
	int min = 0, max = 0;

	for (int i = 0; i < size; i++)
	{
		if (tab[i].heartRate < tab[min].heartRate)
			min = i;
		else if (tab[i].heartRate > tab[max].heartRate)
			max = i;
	}

	printf("Le minimun de pouls etait de %g bpm a %d ms\n", tab[min].heartRate, tab[min].time);
	printf("Le maximum de pouls etait de %g bpm a %d ms", tab[max].heartRate, tab[max].time);
}