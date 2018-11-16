/**
	Project Cardiac_Frequency
	author Antonin
	version 1.0
	date 12 novembre 2018

	Programme de traitement des données du cardiofréquencemètre.
*/

#include "data.h"
#include "menu.h"

int main(int argc, char *argv[])
{
	Data_Line* dataTab = tab_fill_data();

	display_menu(dataTab, get_tab_size(dataTab));

	getchar();

	return 0;
}