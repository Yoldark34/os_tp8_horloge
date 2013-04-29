#include "PLAN_MEMOIRE.h"
#include "Ecran.h"
#include "Outils.h"
#include "MACRO.h"
#include "CallBack_IRQ.h"
#include "HARD_8042_Clavier.h"


//##############################################################################
// QUAND CES ROUTINES S'EXECUTENT, NOUS SOMMES DANS LE RING 0
//  CS= SELECTEUR_CODE_NOYAU
//
// les autres selecteurs (DS) n'ont pas changé !
//##############################################################################

//==============================================================================
// IRQ 0 : Horloge
//==============================================================================
void CallBack_IRQ0()
{
  INITIALISER_DS(SELECTEUR_DATA_NOYAU);
  static UINT16  L_Compteur=0;
  static UINT32  L_Top=0;
    L_Compteur++;
    if (L_Compteur>=1000) {
        BYTE L_X=Donne_Curseur_X();
        BYTE L_Y=Donne_Curseur_Y();
        Positionne_Curseur(57,0);
        Regle_Couleur(FOND_BLEU|FOND_ROUGE|FOND_VERT | BLEU);
        Affiche_Chaine("[IRQ0] Top Timer : ");
        Affiche_Chaine(Entier_Vers_Chaine((UINT32)L_Top));

        Positionne_Curseur(L_X, L_Y);
        L_Compteur=0;
        L_Top++;
   }



}
//------------------------------------------------------------------------------
void CallBack_IRQ1()
{
 UINT16 L_Touche;

   INITIALISER_DS(SELECTEUR_DATA_NOYAU);
//  Affiche_Chaine("IRQ1\n");

 L_Touche=Lecture_Scan_Code();

 Affiche_Chaine(Entier_Vers_Chaine(L_Touche));
 Affiche_Caractere(' ');

}
//------------------------------------------------------------------------------
void CallBack_IRQ3()
{
  INITIALISER_DS(SELECTEUR_DATA_NOYAU);
  Affiche_Chaine("IRQ3\n");

}
//------------------------------------------------------------------------------
void CallBack_IRQ4()
{
  INITIALISER_DS(SELECTEUR_DATA_NOYAU);
  Affiche_Chaine("IRQ4\n");


}
//------------------------------------------------------------------------------
void CallBack_IRQ5()
{
  INITIALISER_DS(SELECTEUR_DATA_NOYAU);
  Affiche_Chaine("IRQ5\n");


}
//------------------------------------------------------------------------------
void CallBack_IRQ6()
{
   INITIALISER_DS(SELECTEUR_DATA_NOYAU);
   Affiche_Chaine("IRQ6\n");


}
//------------------------------------------------------------------------------
void CallBack_IRQ7()
{
   INITIALISER_DS(SELECTEUR_DATA_NOYAU);
  Affiche_Chaine("IRQ7\n");


}
//------------------------------------------------------------------------------
void CallBack_IRQ8()
{
  INITIALISER_DS(SELECTEUR_DATA_NOYAU);
  Affiche_Chaine("IRQ8\n");


}
//------------------------------------------------------------------------------
void CallBack_IRQ9()
{
   INITIALISER_DS(SELECTEUR_DATA_NOYAU);
   Affiche_Chaine("IRQ9\n");


}
//------------------------------------------------------------------------------
void CallBack_IRQ10()
{
                       // Sauvergader tous les registres
  INITIALISER_DS(SELECTEUR_DATA_NOYAU);
  Affiche_Chaine("IRQ10\n");


}
//------------------------------------------------------------------------------
void CallBack_IRQ11()
{
  INITIALISER_DS(SELECTEUR_DATA_NOYAU);
  Affiche_Chaine("IRQ11\n");


}
//------------------------------------------------------------------------------
void CallBack_IRQ12()
{
  INITIALISER_DS(SELECTEUR_DATA_NOYAU);
  Affiche_Chaine("IRQ12\n");


}
//------------------------------------------------------------------------------
void CallBack_IRQ13()
{
   INITIALISER_DS(SELECTEUR_DATA_NOYAU);
  Affiche_Chaine("IRQ13\n");


}
//------------------------------------------------------------------------------
void CallBack_IRQ14()
{
   INITIALISER_DS(SELECTEUR_DATA_NOYAU);
   Affiche_Chaine("IRQ14\n");


}
//------------------------------------------------------------------------------
void CallBack_IRQ15()
{
  INITIALISER_DS(SELECTEUR_DATA_NOYAU);
  Affiche_Chaine("IRQ15\n");


}
//------------------------------------------------------------------------------

void CallBack_Defaut()
{
                        // Sauvergader tous les registres
  INITIALISER_DS(SELECTEUR_DATA_NOYAU);
  Affiche_Chaine("Interruption \n");


}
//------------------------------------------------------------------------------


