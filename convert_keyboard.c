#include "type.h"
#include "convert_keyboard.h"
#include "Ecran.h"
#include "Outils.h"

UCHAR convert_keyboard(UINT32 P_Valeur) {
	UCHAR layout[80] = "azertyuiopqsdfghjklmwxcvbn";
	if (P_Valeur >= 16 && P_Valeur <= 25) {
		return layout[P_Valeur - 16];
	} else if (P_Valeur >= 30 && P_Valeur <= 39) {
		return layout[P_Valeur - 20];
	} else if (P_Valeur >= 44 && P_Valeur <= 49) {
		return layout[P_Valeur - 24];
	}
	//Affiche_Chaine(Entier_Vers_Chaine(P_Valeur));
	return '\0';
}
