/*
 * File:   MACRO.h
 * Author: JLV
 * TP EMA OS 2011
 *
 */
#ifndef MACRO_H
#define	MACRO_H

#define VALEUR_DE(P_Valeur) #P_Valeur

#define SAUT_ALIGNE(Selecteur) asm (".intel_syntax noprefix "); \
                               asm ("jmp "VALEUR_DE(Selecteur)":Suivant"); \
                               asm ( "Suivant: "); \
                               asm (".att_syntax noprefix \n");
 
#define INITIALISER_REGISTRE_GDTR(ADRESSE_GDT) \
                               asm(".intel_syntax noprefix "); \
                               asm("lgdt "VALEUR_DE(ADRESSE_GDT));\
                               asm(".att_syntax noprefix \n");

#define INITIALISER_REGISTRE_IDTR(ADRESSE_IDT) asm (".intel_syntax noprefix"); \
                                               asm ("lidt "VALEUR_DE(ADRESSE_IDT));\
                                               asm (".att_syntax noprefix");

#define INITIALISER_REGISTRES_SEGMENTS_DATA(Selecteur) \
                                 asm (".intel_syntax noprefix "); \
                                 asm (" mov AX,"VALEUR_DE(Selecteur));    \
                                 asm (" mov DS,AX"); \
                                 asm (" mov ES,AX"); \
                                 asm (" mov FS,AX"); \
                                 asm (" mov GS,AX"); \
                                 asm (".att_syntax noprefix \n");

#define INITIALISE_SS_ESP(Selecteur, Limite) \
                                 asm (".intel_syntax noprefix"); \
                                 asm ("push AX"); \
                                 asm (" mov AX,"VALEUR_DE(Selecteur));    \
                                 asm (" mov SS,AX");     \
                                 asm (" mov ESP,"VALEUR_DE(Limite)); \
                                 asm ("pop AX"); \
                                 asm (".att_syntax noprefix");

#define INITIALISER_DS(Selecteur) asm (".intel_syntax noprefix "); \
                                  asm (" mov AX,"VALEUR_DE(Selecteur));    \
                                  asm (" mov DS,AX"); \
                                  asm (".att_syntax noprefix \n");

#define MOV(Registre, Valeur)  asm (".intel_syntax noprefix "); \
                               asm (" mov " VALEUR_DE(Registre) "," VALEUR_DE(Valeur) ); \
                               asm (".att_syntax noprefix \n");
 
#define OUT(Port, Valeur)      asm (".intel_syntax noprefix "); \
                               asm (" mov dx," VALEUR_DE(Port)); \
                               asm (" mov al," VALEUR_DE(Valeur)); \
                               asm (" out dx,al"); \
                               asm (".att_syntax noprefix \n");

#define OUT_PAUSE(Port,Valeur) asm (".intel_syntax noprefix"); \
                               asm ("mov al," VALEUR_DE(Valeur)); \
                               asm ("out " VALEUR_DE(Port) ",al"); \
                               asm ("jmp  $+2 "); \
                               asm (" .att_syntax noprefix \n");
 
#define PUSHALL               asm (".intel_syntax noprefix "); \
                              asm ("pushad "); \
                              asm ("push DS"); \
                              asm ("push ES"); \
                              asm ("push FS"); \
                              asm ("push GS"); \
                              asm (".att_syntax noprefix \n");
 
#define POPALL                asm (".intel_syntax noprefix"); \
                              asm ("pop GS "); \
                              asm ("pop FS "); \
                              asm ("pop ES "); \
                              asm ("pop DS "); \
                              asm ("popad "); \
                              asm (".att_syntax noprefix \n");  

#define HALT     asm (".intel_syntax noprefix ");   \
                 asm("hlt"); \
                 asm (".att_syntax noprefix \n"); 

#define STI      asm (".intel_syntax noprefix ");   \
                 asm("sti"); \
                 asm (".att_syntax noprefix \n"); 
#define AUTORISE_INTERRUPTION STI


#define CLI      asm (".intel_syntax noprefix ");   \
                 asm("cli"); \
                 asm (".att_syntax noprefix \n"); 
#define INTERDIRE_INTERRUPTION CLI


#endif	/* MACRO_H */

