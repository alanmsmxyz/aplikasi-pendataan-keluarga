#include "multiList.h"

void createList( List L )
{
    L.first = NULL;
}


/* Parent Function and Procedures */
addressP allocateP( keluarga data )
{
    addressP p;
    p = new elementP;
    p->info  = data;
    p->next = NULL;
    p->prev = NULL;
    p->firstC = NULL;
    p->lastC = NULL;
    return p;
}

void insertP( List &L, addressP p )
{
    if( L.first == NULL )
    {
        L.first = p;
    }
    else
    {
        addressP q = L.first;
        while( q->next != NULL )
        {
            q = q->next;
        }
        q->next = p;
        p->prev = q;
    }
}

void deleteP( List &L, addressP p ) // delete p
{
    if( L.first == NULL )
    {
        cout<< "empty";
    }
    else
    {
        if( p == L.first )
        {
            L.first = p->next;
            L.first->prev = NULL;
            p->next = NULL;
        }
        else if( p->next == NULL)
        {
            p->prev->next = NULL;
            p->prev = NULL;
        }
        else
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            p->next = NULL;
            p->prev = NULL;
        }
    }
}

addressP findP( List L, string noKK )
{
    if ( L.first == NULL )
    {
        return NULL;
    }
    else
    {
        addressP p = L.first;

        while( ( p != NULL ) && ( p->info.noKK != noKK ) )
        {
            p = p->next;
        }

        return p;
    }
}

/* Child Function and Procedures */
addressC allocateC( anggotaKeluarga data )
{
    addressC c;
    c = new elementC;
    c->info = data;
    c->next = NULL;
    return c;
}

void insertC( addressP &p, addressC c )
{
    if( p->firstC == NULL)
    {
        p->firstC = c;
        p->lastC = c;
        p->lastC->next = c;
    }
    else
    {
        p->lastC->next = c;
        p->lastC = c;
        c->next = p->firstC;
    }
}

void deleteC( addressP &p, addressC c )
{
    if( p->firstC == NULL )
    {
        cout << "empty";
    }
    else if ( p->firstC->next == p->firstC )
    {
        p->firstC = NULL;
        p->lastC = NULL;
        c->next = NULL;
    }
    else
    {
        if( p->firstC == c )
        {
            p->firstC = c->next;
            p->lastC->next = c->next;
            c->next = NULL;
        }
        else
        {
            addressC d = p->firstC;
            while( d->next != c )
            {
                d = d->next;
            }

            d->next = c->next;
            c->next = NULL;

            if( p->lastC == c)
            {
               p->lastC = d;
            }
        }
    }
}

addressC findC( addressP p, string NIK )
{
    if( p->firstC == NULL )
    {
        return NULL;
    }
    else
    {
        addressC d;
        d = p->firstC;

        if( d->info.NIK != NIK )
        {
            d = d->next;

            while( ( d != p->firstC ) && ( d->info.NIK != NIK ) )
            {
                d = d->next;
            }
        }

        return d;
    }
}


/* Data Output */
void showP( addressP p )
{
    cout << "No KK  :" << p->info.noKK << endl;
    cout << "Alamat :" << p->info.alamat << endl;
    cout << endl;
}

void showC( addressC c )
{
    cout << "- Nama          : " << c->info.nama << endl;
    cout << "- NIK           : " << c->info.NIK << endl;
    cout << "- Jenis Kelamin : " << c->info.jenisKelamin << endl;
    cout << "- Umur          : " << c->info.umur << endl;
    cout << "- Pekerjaan     : " << c->info.pekerjaan << endl;
    cout << "- Status        : " << c->info.status << endl;
    cout << endl;
}

void showAllC( addressP p )
{

    if( p->firstC == NULL )
    {
        cout << "Tidak ada anggota keluarga" << endl;
    }
    else
    {
        addressC c = p->firstC;
        do
        {
            showC( c );
            c = c->next;
        } while( c != p->firstC );
    }
}

void showAllP( List L )
{
    if( L.first == NULL )
    {
        cout << "Belum ada data" << endl;
    }
    else
    {
        addressP p = L.first;
        while( p != NULL )
        {
            showP( p );
            p = p->next;
        }
    }
}

void showAll( List L )
{
    if( L.first == NULL )
    {
        cout << "Belum ada data" << endl;
    }
    else
    {
        addressP p = L.first;
        while( p != NULL )
        {
            showP( p );
            showAllC( p );
            p = p->next;

            cout << "-----" << endl;
        }
    }
}


/* Counter */
int countC( addressP p )
{
    if( p->firstC == NULL)
    {
        return 0;
    }
    else
    {
        int counter = 0;
        addressC c = p->firstC;

        do
        {
            counter = counter + 1;
            c = c->next;
        } while( c != p->firstC );

        return counter;
    }
}

int countAllC( List L )
{
    if( L.first == NULL)
    {
        return 0;
    }
    else
    {
        int counter = 0;
        addressP p = L.first;

        while( p != NULL )
        {
            counter = counter + countC( p );
            p = p->next;
        }

        return counter;
    }
}

int countP( List L )
{
    if( L.first == NULL)
    {
        return 0;
    }
    else
    {
        int counter = 0;
        addressP p = L.first;

        while( p != NULL )
        {
            counter = counter + 1;
            p = p->next;
        }

        return counter;
    }
}
