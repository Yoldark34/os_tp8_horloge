#include "type.h"
#include "convert_keyboard.h"
#include "Ecran.h"

void convert_keyboard(UINT32 P_Valeur) {
	switch (P_Valeur) {
		case 16: Affiche_Caractere('a');
			break;
		case 17: Affiche_Caractere('z');
			break;
		case 18: Affiche_Caractere('e');
			break;
		case 19: Affiche_Caractere('r');
			break;
		case 20: Affiche_Caractere('t');
			break;
		case 21: Affiche_Caractere('y');
			break;
		case 22: Affiche_Caractere('u');
			break;
		case 23: Affiche_Caractere('i');
			break;
		case 24: Affiche_Caractere('o');
			break;
		case 25: Affiche_Caractere('p');
			break;
		default: Affiche_Chaine('not implemented');
			break;
	}
}
