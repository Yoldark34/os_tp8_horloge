/*
 * File:   DESCRIPTEUR.h
 * Author: JLV
 * TP EMA OS 2011
 *
 */
#ifndef PLAN_MEMOIRE_H
#define	PLAN_MEMOIRE_H

//##############################################################################
// PLAN MEMOIRE
//     GDT en                              0x00000000
// ==> IDT en                              0x00000800
//     le code est chargé par le grub à    0x00100000  (1 Mo)
//     les data sont stockées en           0x00200000  (2Mo)
//     la pile débute en                   0x02000000  (32 Mo)
//##############################################################################



//##############################################################################
//      Descripteurs de segments de 0x0000 à 0x7F8  ( 256 descripteur de 8 Octets)
//##############################################################################
#define ADRESSE_BASE_DESCRIPTEUR_SEGMENT    0x00000000  //A partir de 0
#define LIMITE_DESCRIPTEURS_SEGMENT         0xFF         // jusqu'à 2040  (2Ko - 8)


//##############################################################################
//      Descripteurs de guichet de 0x800 à 0xFF8 (256 descripteurs de 8 Octets)
//##############################################################################
#define ADRESSE_BASE_DESCRIPTEUR_GUICHET    0x00000800   // A partir de 2048 (2k)
#define LIMITE_DESCRIPTEURS_GUICHET         0xFF         // jusqu'à 4088 (4ko - 8)



//-----------------------------------------------------------------------------------
#define INDEX_DESCRIPTEUR_CODE_NOYAU     1
#define SELECTEUR_CODE_NOYAU            (INDEX_DESCRIPTEUR_CODE_NOYAU <<3)
#define BASE_CODE_NOYAU                 0x00000000
#define LIMITE_CODE_NOYAU               0xFFFFF     // de 0 à 0xFFFFF = 0x100000  0x100000* 4 Ko => 4Go


//-----------------------------------------------------------------------------------
#define INDEX_DESCRIPTEUR_DATA_NOYAU   2
#define SELECTEUR_DATA_NOYAU           (INDEX_DESCRIPTEUR_DATA_NOYAU<<3)
#define BASE_DATA_NOYAU         0x00000000
#define LIMITE_DATA_NOYAU       0xFFFFF     // de 0 à 0xFFFFF = 0x100000  0x100000* 4 Ko => 4Go

//-----------------------------------------------------------------------------------
#define INDEX_DESCRIPTEUR_STACK_NOYAU 3
#define SELECTEUR_STACK_NOYAU       (INDEX_DESCRIPTEUR_STACK_NOYAU <<3)
#define BASE_STACK_NOYAU           0x00         // 0 car dans un segment de pile, cete valeur n'est pas exploitée (le bit D sera à 0 donc 
                                  // début du haut de la pile à 4Go maxi. Sera réglée par ESP
#define LIMITE_STACK_NOYAU      0x0000000      // autoriser de descendre jusqu'à 0 Mo
#define DEBUT_STACK_NOYAU       0x2000000      // A partir de 32 mo 
//-----------------------------------------------------------------------------------



#endif	/* PLAN_MEMOIRE_H */

