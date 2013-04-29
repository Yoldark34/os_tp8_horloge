/*
 * File:   DESCRIPTEUR.h
 * Author: JLV
 * TP EMA OS 2011
 *
 */
#include "TYPE.h"

#ifndef _GDT_H
#define	_GDT_H


#define RING_0 0
#define RING_3 3

//------------------------------------------------------------------------------
#pragma pack(1)
typedef struct  {
    UINT16 Limite_Segment_0_15;   //2 Octets
    UINT16 Base_Segment_0_15;     // 2 Octets
    BYTE Base_Segment_16_23;      // 1 Octet

    BYTE Type: 4;                 // 1 Octet
    BYTE Bit_DT:1;
    BYTE Privilege:2;
    BYTE Bit_P:1;

    BYTE Limite_Segment_16_19:4; // 1 Octet
    BYTE Bit_AVL:1;
    BYTE Bit_O:1;
    BYTE Bit_D:1;
    BYTE Bit_G:1;

    BYTE Base_Segment_24_31;  // 1 Octet
                              //------------------
} T_DESCRIPTEUR_SEGMENT;      // 8 Octets en tout
#pragma pack()
//------------------------------------------------------------------------------

#pragma pack(1)
typedef struct  {
    UINT16 Limite;
    UINT32 Base;
}T_INFO_GDT;
#pragma pack()
//------------------------------------------------------------------------------


#pragma pack(1)
typedef struct  {
    UINT16 Offset_0_15;   //2 Octets

    UINT16 Selecteur;    // 2 Octets

    BYTE Non_Utilise;    // 1 Octet

    BYTE Type:4;         // 1 Octet
    BYTE Bit_DT:1;
    BYTE Bit_DPL:2;
    BYTE Bit_P :1;

    UINT16 Offset_16_31;  // 2 Octets
                              //------------------
} T_DESCRIPTEUR_GUICHET;     // 8 Octets en tout
#pragma pack()
//------------------------------------------------------------------------------

#pragma pack(1)
typedef struct  {
    UINT16 Limite;
    UINT32 Base;
}T_INFO_IDT;
#pragma pack()



//---------------------------------------------------------------------
#define SEGMENT_TYPE_LECTURE                                     0x00
#define SEGMENT_TYPE_LECTURE_ACCEDE                              0x01
#define SEGMENT_TYPE_LECTURE_ECRITURE                            0x02
#define SEGMENT_TYPE_LECTURE_ECRITURE_ACCEDE                     0x03
#define SEGMENT_TYPE_LECTURE_INVERSE                             0x04
#define SEGMENT_TYPE_LECTURE_INVERSE_ACCEDE                      0x05
#define SEGMENT_TYPE_LECTURE_ECRITURE_INVERSE                    0x06
#define SEGMENT_TYPE_LECTURE_ECRITURE_INVERSE_ACCEDE             0x07
#define SEGMENT_TYPE_EXECUTION                                   0x08
#define SEGMENT_TYPE_EXECUTION_ACCEDE                            0x09
#define SEGMENT_TYPE_LECTURE_EXECUTION                           0x0A
#define SEGMENT_TYPE_LECTURE_EXECUTION_ACCEDE                    0x0B
#define SEGMENT_TYPE_EXECUTION_CONFORME                          0x0D
#define SEGMENT_TYPE_EXECUTION_LECTURE_CONFORME                  0x0E
#define SEGMENT_TYPE_EXECUTION_LECTURE_CONFORME_ACCEDE           0x0F


//---------------------------------------------------------------------
#define SYSTEM_TSS_286_DISPONIBLE    1
#define SYSTEM_LDT                   2
#define SYSTEM_TSS_286_OCCUPE        3
#define GUICHET_APPEL_286            4
#define GUICHET_TACHE                5
#define GUICHET_INT_286              6
#define GUICHET_TRAPPE_286           7
#define SYSTEM_TSS_386_DISPONIBLE    9
#define SYSTEM_TSS_386_OCCUPE        0xB
#define GUICHET_APPEL_386            0xC
#define GUICHET_INT_386              0xE
#define GUICHET_TRAPPE_386           0xF


//---------------------------------------------------------------------

void Configure_Descripteur_Segment(T_DESCRIPTEUR_SEGMENT* P_Descripteur,
                                  UINT32 P_Base, UINT32 P_Limite,
                                  BYTE P_Type, BYTE P_DT, BYTE P_Privilege, BYTE P_Present,
                                  BYTE P_AVL, BYTE P_O, BYTE P_D, BYTE P_G);


void Configure_Descripteur_Guichet(T_DESCRIPTEUR_GUICHET* P_Descripteur, UINT16 P_Selecteur, UINT32 P_Offset,
                                   BYTE P_Type,  BYTE P_DPL, BYTE P_P);

#define _DEBUG_SEGMENT


#endif	/* GDT_H */

