#include "Ecran.h"
#include "Alien.h"

void Affiche_Alien_1(BYTE color) {
	//BYTE prevColor = Donne_Couleur();
	Regle_Couleur(color);
	//BYTE X = Get_Cursor_Pos_X();
	//BYTE Y = Get_Cursor_Pos_X();
	BYTE Alien_X = 62;
	BYTE Alien_Y = 0;
	Positionne_Curseur(Alien_X, Alien_Y);
	Affiche_Chaine("       .-''''-.\n");
	Alien_Y++;
	Positionne_Curseur(Alien_X, Alien_Y);
	Affiche_Chaine("      /        \\\n");
	Alien_Y++;
	Positionne_Curseur(Alien_X, Alien_Y);
	Affiche_Chaine("     /_        _\\\n");
	Alien_Y++;
	Positionne_Curseur(Alien_X, Alien_Y);
	Affiche_Chaine("    // \\      / \\\\\n");
	Alien_Y++;
	Positionne_Curseur(Alien_X, Alien_Y);
	Affiche_Chaine("    |\\__\\    /__/|\n");
	Alien_Y++;
	Positionne_Curseur(Alien_X, Alien_Y);
	Affiche_Chaine("     \\    ||    /\n");
	Alien_Y++;
	Positionne_Curseur(Alien_X, Alien_Y);
	Affiche_Chaine("      \\        /\n");
	Alien_Y++;
	Positionne_Curseur(Alien_X, Alien_Y);
	Affiche_Chaine("       \\  __  /\n");
	Alien_Y++;
	Positionne_Curseur(Alien_X, Alien_Y);
	Affiche_Chaine("        '.__.'\n");
	Alien_Y++;
	Positionne_Curseur(Alien_X, Alien_Y);
	Affiche_Chaine("         |  |\n");
	//Positionne_Curseur(X, Y);
	//Regle_Couleur(prevColor);
}

void Affiche_Alien_2(BYTE color) {
	//BYTE prevColor = Donne_Couleur();
	Regle_Couleur(color);
	//BYTE X = Get_Cursor_Pos_X();
	//BYTE Y = Get_Cursor_Pos_X();
	BYTE Alien_X = 62;
	BYTE Alien_Y = 0;
	Positionne_Curseur(Alien_X, Alien_Y);
	Affiche_Chaine("       .-''''-.\n");
	Alien_Y++;
	Positionne_Curseur(Alien_X, Alien_Y);
	Affiche_Chaine("      /  _____ \\\n");
	Alien_Y++;
	Positionne_Curseur(Alien_X, Alien_Y);
	Affiche_Chaine("     /_   ___  _\\\n");
	Alien_Y++;
	Positionne_Curseur(Alien_X, Alien_Y);
	Affiche_Chaine("    // \\      / \\\\\n");
	Alien_Y++;
	Positionne_Curseur(Alien_X, Alien_Y);
	Affiche_Chaine("    |\\_ \\    /_ /|\n");
	Regle_Couleur(ROUGE);
	Positionne_Curseur(Alien_X + 7, Alien_Y);
	Affiche_Chaine("O");
	Positionne_Curseur(Alien_X + 15, Alien_Y);
	Affiche_Chaine("O");
	Regle_Couleur(color);
	Alien_Y++;
	Positionne_Curseur(Alien_X, Alien_Y);
	Affiche_Chaine("     \\    ||    /\n");
	Alien_Y++;
	Positionne_Curseur(Alien_X, Alien_Y);
	Affiche_Chaine("      \\   __   /\n");
	Alien_Y++;
	Positionne_Curseur(Alien_X, Alien_Y);
	Affiche_Chaine("       \\ |__| /\n");
	Alien_Y++;
	Positionne_Curseur(Alien_X, Alien_Y);
	Affiche_Chaine("        '.__.'\n");
	Alien_Y++;
	Positionne_Curseur(Alien_X, Alien_Y);
	Affiche_Chaine("         |  |\n");
	Alien_Y++;
	Positionne_Curseur(Alien_X, Alien_Y);
	//Positionne_Curseur(X, Y);
	//Regle_Couleur(prevColor);
}

void copyright() {
	//BYTE prevColor = Donne_Couleur();
	Regle_Couleur(ROUGE);
	Affiche_Chaine("Ceci est un os GPL v.2\n");
	//Regle_Couleur(prevColor);
}
