/**
	*@file menu.c
	*@brief Fichier d'affichage du menu et d'éxecution des traitements.
	*@author Antonin
	*@version 1.0
	*@date 14 novembre 2018
	*
	*Contrôle l'affichage du menu et l'éxecution des choix.
*/
#include "menu.h"
#include "treatment.h"

void display_menu(Data_Line* tab, size_t size)
{
	do
	{
		SCREEN_CLEAR();

		printf("-------------------------------------\n");
		printf("	CardioFrequencemetre	\n");
		printf("-------------------------------------\n\n");

		printf("1- Afficher les donnees dans l'ordre du fichier csv\n");
		printf("2- Afficher les donnees par ordre croissant\n");
		printf("3- Afficher les donnes par ordre decroissant\n");
		printf("4- Rechercher le pouls pour un temps particulier\n");
		printf("5- Moyenne de pouls dans une plage de temps donnee\n");
		printf("6- Afficher le nombre de ligne de donnees actuellement en memoire\n");
		printf("7- Rechercher et afficher le max/min de pouls\n");
		printf("8- Quitter l'application\n");

		choice_execution(tab, size, get_menu_choice()); //Execute le choix demandé par l'utilisateur.
	} while (1);
}


static int get_menu_choice()
{
	int toReturn;

	while (1)
	{
		printf("\nChoix : ");

		toReturn = check_input_int();

		if (toReturn < 1 || toReturn > 8)
			printf("Le choix doit etre comprit entre 1 et 8");
		else
			return toReturn;
	}
}


static int check_input_int()
{
	int returned;

	if (scanf("%d", &returned) != 1) //Si la valeur écrite par l'utilisateur n'est pas un nombre on ferme le programme.
		exit(EXIT_FAILURE);

	return returned;
}

static void display_sort_menu()
{
	printf("1- Trier en fonction du temps\n");
	printf("2- Trier en fonction des bpm\n");
}


static void choice_execution(Data_Line* tab, size_t size, int choice)
{
	SCREEN_CLEAR()

	//Les fonctions sont executées en fonction du choix de l'utilisateur.
	switch (choice)
	{
		case 1:	
			display_all_file();
			break;
		case 2:	
			display_sort_menu(); //Affiche sous menu de tri.
			sort_exec(tab, size, get_menu_choice(), 1); //execute le tri choisi par l'utilisateur.
			break;
		case 3:	
			display_sort_menu(); //Affiche sous menu de tri.
			sort_exec(tab, size, get_menu_choice(), 0); //execute le tri choisi par l'utilisateur.
			break;
		case 4: 
			sub_menu_research(tab, size);
			break;
		case 5:
			sub_menu_average(tab, size);
			break;
		case 6: 
			printf("Il y a actuellement %d lignes de donnees en memoire", size);
			break;
		case 7:
			display_max_min_pulse(tab, size);
			break;
		case 8: 
			exit(EXIT_SUCCESS);
			break;
	}

	LINE_BREAK();
	PAUSE();
}


static void sort_exec(Data_Line* tab, size_t size, int choice, int ascending)
{
	switch (choice)
	{
		case 1: tab_sort(tab, size, compare_time, ascending); //tri les données en fonction du temps.
				break;
		case 2: tab_sort(tab, size, compare_bpm, ascending); //Tri les données en fonction des bpm.
				break;
	}

	SCREEN_CLEAR()

	display_all_data(tab, size); //Affiche toutes les données une fois triées.
}


static void sub_menu_research(Data_Line* tab, size_t size)
{	
	printf("Temps a partir duquel rechercher le pouls (en ms)\n");

	printf("\ntemps : ");

	int time = check_input_int(); //Sauvegarde du temps choisi par l'utilisateur (qui n'est pas autre chose qu'un nombre).

	Data_Line finded = search_bpm(tab, size, time); //La ligne de données est trouvée.

	SCREEN_CLEAR();

	if(time == finded.time) //Si le temps choisi par l'utilisateur était exactement le même qu'un temps enregistré dans les données on l'affiche.
		printf("A %d ms la frequence cardiaque etait de :  bpm", time, finded.heartRate);
	else //Si le temps choisi n'était pas dans les données on lui affiche le dernier bpm enregistré par rapport au temps demandé.
		printf("A %d ms la derniere mesure avait eu lieu a %d ms\nLa frequence cardiaque etait de : %d bpm", time, finded.time, finded.heartRate);
}


static void sub_menu_average(Data_Line* tab, size_t size)
{
	printf("Plage de temps ou calculer la moyenne de pouls :");

	LINE_BREAK();

	printf("premiere borne : ");
	int first = check_input_int(); //Sauvegarde du temps choisi par l'utilisateur (qui n'est pas autre chose qu'un nombre).
	printf("\nDeuxieme borne : ");
	int second = check_input_int();

	SCREEN_CLEAR();

	printf("Entre %d et %d ms la moyenne de pouls etait de : %g bpm", first, second, get_average_pulse(tab, size, first, second));
}