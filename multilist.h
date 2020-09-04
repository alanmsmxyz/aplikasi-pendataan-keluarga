#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED

#include <iostream>

using namespace std;

struct anggotaKeluarga
{
    string NIK;
    string nama;
    string jenisKelamin;
    int umur;
    string pekerjaan;
    string status;
};


struct keluarga
{
    string noKK;
    string alamat;
};

typedef struct elementC *addressC;
struct elementC
{
    anggotaKeluarga info;
    addressC next;
};

typedef struct elementP *addressP;
struct elementP
{
    keluarga info;
    addressP next;
    addressP prev;
    addressC firstC;
    addressC lastC;
};

struct List
{
    addressP first;
};


void createList( List L );

/* Parent Function and Procedures */
addressP allocateP( keluarga data );
void insertP( List &L, addressP p );
void deleteP( List &L, addressP p );
addressP findP( List L, string NIK );

/* Child Function and Procedures */
addressC allocateC( anggotaKeluarga data );
void insertC( addressP &p, addressC c );
void deleteC( addressP &p, addressC c );
addressC findC( addressP p, string NIK );

/* Data Output */
void showP( addressP p );
void showC( addressC c );
void showAllC( addressP p );
void showAllP( List L );
void showAll( List L );

/* Counter */
int countC( addressP p );
int countAllC( List L );
int countP( List L );

/* Pre-declare the list */
extern List dataKeluarga;
#endif // MULTILIST_H_INCLUDED
