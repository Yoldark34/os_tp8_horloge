#include "type.h"
#include "Ecran.h"
#include "INIT_IDT.h"
#include "Info_Boot.h"
#include "Alien.h"
#include "Init_GDT.h"
#include "MACRO.h"
#include "PLAN_MEMOIRE.h"
#include "HARD_8042_Clavier.h"
#include "Outils.h"
#include "convert_keyboard.h"
#include "PIC_8259A.h"

void Affiche_Message(UCHAR* P_Message, UCHAR* P_Etat) {
	Regle_Couleur(BLANC);
	Affiche_Chaine(P_Message);
	Positionne_Curseur(78 - Taille_Chaine(P_Etat), Donne_Curseur_Y());
	Regle_Couleur(VERT | LUMINEUX);
	Affiche_Chaine(P_Etat);
	Affiche_Caractere('\n');
}

void Affiche_Informations_BOOT(T_BOOT_INFO* P_Info) {
	if ((P_Info->Flags & BOOT_INFO_MEMOIRE) == BOOT_INFO_MEMOIRE) {
		Regle_Couleur(BLANC);
		Affiche_Message(">>>Memoire detectee : ", "OK");
		UINT32 L_Taille_Memoire = P_Info->Adresse_Basse + P_Info->Adresse_Haute + 1024;
		Regle_Couleur(BLEU | LUMINEUX);
		Affiche_Chaine(Entier_Vers_Chaine(L_Taille_Memoire / 1024));
		Affiche_Chaine(" Mo\n");
	}
}

void OS_Main() {
	Affiche_Message(">>>Initialisation de la Pile (ESP) : ", "OK");
	Initialisation_IDT();
	Affiche_Message(">>>Initialisation de la IDT : ", "OK");

	Inititialisation_8259A();
	Affiche_Message(">>>Initialisation du pic 8259A : ", "OK");
	AUTORISE_INTERRUPTION;

	while (1);
	/*while (1) {

		int i = 0;
		long boucle = 5000000L;

		Affiche_Alien_1(VERT);
		for (i = 0; i < boucle; i++) {
			asm("NOP");
		}


		Affiche_Alien_2(VERT);
		for (i = 0; i < boucle / 2; i++) {
			asm("NOP");
		}

	}*/
}

void OS_Start(T_BOOT_INFO* P_Info) {
	Efface_Ecran();
	//Affiche_Alien_2(VERT);
	Affiche_Informations_BOOT(P_Info);
	//BYTE prevColor = Donne_Couleur();

	if ((P_Info->Flags & BOOT_INFO_MEMOIRE) == BOOT_INFO_MEMOIRE) {
		Affiche_Chaine("\n Adresse Basse (640ko maxi) : ");
		Affiche_Chaine(Entier_Vers_Chaine_Hexa(P_Info->Adresse_Basse, 4));

		Affiche_Chaine("\n Adresse Haute (Au dessus des 1 Mo) : ");
		Affiche_Chaine(Entier_Vers_Chaine_Hexa(P_Info->Adresse_Haute, 4));
		Affiche_Chaine("\n\tIl y a donc : ");

		UINT32 L_Taille_Memoire = P_Info->Adresse_Basse + P_Info->Adresse_Haute + 1024;
		Affiche_Chaine(Entier_Vers_Chaine(L_Taille_Memoire));
		Affiche_Chaine(" Ko de memmoire --> ");
		Affiche_Chaine(Entier_Vers_Chaine(L_Taille_Memoire / 1024));
		Affiche_Chaine(" Mo ");
	}

	if ((P_Info->Flags & BOOT_LIGNE_COMMANDE) == BOOT_LIGNE_COMMANDE) {
		Affiche_Chaine("\n Ligne de commenda passée au noyau : ");
		Affiche_Chaine((UCHAR*) P_Info->Ligne_De_Commande);
	}

	if ((P_Info->Flags & BOOT_INFO_BOOTLOADER) == BOOT_INFO_BOOTLOADER) {
		Affiche_Chaine("\n Nom du bootloader: ");
		Affiche_Chaine((UCHAR*) P_Info->Nom_BootLoader);
		Affiche_Chaine("\n");
	}

	Initialisation_GDT();

	INITIALISE_SS_ESP(SELECTEUR_STACK_NOYAU, DEBUT_STACK_NOYAU);
	OS_Main();
	asm("NOP");
}

