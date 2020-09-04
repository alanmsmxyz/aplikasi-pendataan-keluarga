#include <iostream>
#include <sstream>
#include <string>

#include "multiList.h"
#include "toolkit.h"
#include "menu.h"

using namespace std;
List dataKeluarga;

int main()
{
    createList( dataKeluarga );

    // generating random data for demo purpose
    for( int i = 1; i <= 5; i++ )
    {
        ostringstream str1;
        str1 << i;

        keluarga temp1;
        temp1.noKK = "0000" + str1.str();
        temp1.alamat = "Jalan Telyu no" + str1.str();

        addressP p = allocateP( temp1 );
        insertP( dataKeluarga, p );

        for( int j = 1; j <= 3; j++ )
        {
            ostringstream str2;
            str2 << j;

            anggotaKeluarga temp2;

            temp2.NIK = str1.str() + "000" + str2.str();
            temp2.nama = "Bambank " + str1.str() + "-" + str2.str();
            temp2.umur = 5 * j + i ;
            temp2.jenisKelamin = "Pria Tulen";
            temp2.pekerjaan = "Petani Lumut";
            temp2.status = "Sugar Daddy";

            insertC( p, allocateC( temp2 ) );
        }
    }
    // end of generating random data

    home();
    return 0;
}
