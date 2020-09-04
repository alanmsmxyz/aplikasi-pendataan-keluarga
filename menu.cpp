#include "menu.h"
#include "multilist.h"

void addKeluarga()
{
    clearScreen();
    keluarga temp;

    cout << "        INPUT DATA KELUARGA        " << endl;
    cout << "-----------------------------------" << endl;
    cout << "Nomor KK            : ";
    cin >> temp.noKK;
    cout << "Alamat              : ";
    cin >> temp.alamat;

    insertP( dataKeluarga, allocateP( temp ) );

    cout << "Data keluarga telah dimasukan" << endl;
    hold();
    home();
}

void viewAll()
{
    clearScreen();

    cout << "        LIHAT DATA KELUARGA        " << endl;
    cout << "-----------------------------------" << endl;

    showAll( dataKeluarga );
    cout << "Total " << countP( dataKeluarga ) << " keluarga dan " << countAllC( dataKeluarga ) << " anggota keluarga ditampilkan." << endl;

    hold();
    home();
}

void viewAllKeluarga()
{
    clearScreen();

    cout << "        LIHAT DATA KELUARGA        " << endl;
    cout << "-----------------------------------" << endl;

    showAllP( dataKeluarga );

    cout << endl << "Total " << countP( dataKeluarga ) << " keluarga ditampilkan." << endl;

    hold();
    home();
}

void viewKeluarga()
{
    clearScreen();
    string noKK;
    addressP p;

    cout << "        LIHAT DATA KELUARGA        " << endl;
    cout << "-----------------------------------" << endl;

    cout << "Masukan No KK : ";
    cin >> noKK;

    p = findP( dataKeluarga, noKK );
    if( p == NULL )
    {
        cout << "Keluarga tidak ditemukan, pastikan no KK yang dimasukan benar dan coba lagi" << endl;
        hold();
        viewData();
    }
    else
    {
        showP( p );
        showAllC( p );

        cout << "Total " << countC( p ) << " anggota keluarga ditampilkan." << endl;
    }

    hold();
    home();
}

void updateKeluarga()
{
    clearScreen();
    string noKK;
    addressP p;

    cout << "      PERBARUI DATA KELUARGA       " << endl;
    cout << "-----------------------------------" << endl;

    cout << "Masukan No KK : ";
    cin >> noKK;

    p = findP( dataKeluarga, noKK );

    if( p == NULL )
    {
        cout << "Keluarga tidak ditemukan, pastikan no KK yang dimasukan benar dan coba lagi" << endl;
        hold();
        updateData();
    }
    else
    {
        cout << endl;
        cout << "Masukan data baru " << endl;
        cout << "Nomor KK            : ";
        cin >> p->info.noKK;
        cout << "Alamat              : ";
        cin >> p->info.alamat;
    }

    cout << "Data keluarga sudah diperbarui" << endl;
    hold();
    home();
}

void removeKeluarga()
{
    clearScreen();
    string noKK;
    addressP p;

    cout << "      HAPUS DATA KELUARGA       " << endl;
    cout << "-----------------------------------" << endl;

    cout << "Masukan No KK : ";
    cin >> noKK;

    p = findP( dataKeluarga, noKK );

    if( p == NULL )
    {
        cout << "Keluarga tidak ditemukan, pastikan no KK yang dimasukan benar dan coba lagi" << endl;
        hold();
        removeData();
    }
    else
    {
        deleteP( dataKeluarga, p );
    }

    cout << "Data keluarga sudah dihapus" << endl;
    hold();
    home();
}

void addAnggotaKeluarga()
{
    clearScreen();
    string noKK;
    addressP p;
    anggotaKeluarga temp;

    cout << "    INPUT DATA ANGGOTA KELUARGA    " << endl;
    cout << "-----------------------------------" << endl;
    cout << "Masukan No KK : ";
    cin >> noKK;

    p = findP( dataKeluarga, noKK );

    if( p == NULL )
    {
        cout << "Keluarga tidak ditemukan, pastikan no KK yang dimasukan benar dan coba lagi" << endl;
        hold();
        addData();
    }
    else
    {
        cout << "NIK           : ";
        cin >> temp.NIK;
        cout << "Nama          : ";
        cin >> temp.nama;
        cout << "Jenis Kelamin : ";
        cin >> temp.jenisKelamin;
        cout << "Pekerjaan     : ";
        cin >> temp.pekerjaan;
        cout << "Umur          : ";
        cin >> temp.umur;
        cout << "Status        : ";
        cin >> temp.status;

        insertC( p, allocateC( temp ) );

        cout << "Anggota keluarga sudah dimasukan" << endl;
    }
    hold();
    home();
}

void updateAnggotaKeluarga()
{
    clearScreen();
    string noKK, NIK;
    addressP p;
    addressC c;
    anggotaKeluarga temp;

    cout << "    INPUT DATA ANGGOTA KELUARGA    " << endl;
    cout << "-----------------------------------" << endl;
    cout << "Masukan No KK : ";
    cin >> noKK;

    p = findP( dataKeluarga, noKK );

    if( p == NULL )
    {
        cout << "Keluarga tidak ditemukan, pastikan no KK yang dimasukan benar dan coba lagi" << endl;
        hold();
        updateData();
    }
    else
    {
        cout << "Masukan NIK   : ";
        cin >> NIK;

        c = findC( p, NIK );

        if( c == NULL )
        {
            cout << "Anggota keluarga tidak ditemukan, pastikan NIK yang dimasukan benar dan coba lagi" << endl;
            hold();
            updateAnggotaKeluarga();
        }
        else
        {
            cout << "NIK           : ";
            cin >> temp.NIK;
            cout << "Nama          : ";
            cin >> temp.nama;
            cout << "Jenis Kelamin : ";
            cin >> temp.jenisKelamin;
            cout << "Pekerjaan     : ";
            cin >> temp.pekerjaan;
            cout << "Umur          : ";
            cin >> temp.umur;
            cout << "Status        : ";
            cin >> temp.status;
        }

        cout << "Anggota keluarga sudah diperbarui" << endl;
    }
    hold();
    home();
}

void removeAnggotaKeluarga()
{
    clearScreen();
    string noKK, NIK;
    addressP p;
    addressC c;
    anggotaKeluarga temp;

    cout << "    HAPUS DATA ANGGOTA KELUARGA    " << endl;
    cout << "-----------------------------------" << endl;
    cout << "Masukan No KK : ";
    cin >> noKK;

    p = findP( dataKeluarga, noKK );

    if( p == NULL )
    {
        cout << "Keluarga tidak ditemukan, pastikan no KK yang dimasukan benar dan coba lagi" << endl;
        hold();
        removeData();
    }
    else
    {
        cout << "Masukan NIK   : ";
        cin >> NIK;

        c = findC( p, NIK );

        if( c == NULL )
        {
            cout << "Anggota keluarga tidak ditemukan, pastikan NIK yang dimasukan benar dan coba lagi" << endl;
            hold();
            removeAnggotaKeluarga();
        }
        else
        {
            deleteC( p, c );
        }

        cout << "Anggota keluarga sudah dihapus" << endl;
    }
    hold();
    home();
}


void addData()
{
    int input;
    clearScreen();

    cout << "            INPUT DATA             " << endl;
    cout << "-----------------------------------" << endl;
    cout << "1. Input data keluarga" << endl;
    cout << "2. Input data anggota keluarga" << endl;
    cout << "0. Kembali" << endl;
    cout << endl;
    cout << "Masukan pilihan anda: ";
    cin >> input;

    switch( input )
    {
        case 1  :
            addKeluarga();
            break;
        case 2  :
            addAnggotaKeluarga();
            break;
        case 0  :
            home();
            break;
        default :
            cout << "Input yang anda masukkan salah, silahkan ulangi lagi";
            hold();
            addData();
            break;
    }
}

void viewData()
{
    int input;
    clearScreen();

    cout << "             LIHAT DATA           " << endl;
    cout << "----------------------------------" << endl;
    cout << "1. Lihat semua data yang ada" << endl;
    cout << "2. Lihat semua keluarga terdaftar" << endl;
    cout << "3. Lihat data keluarga tertentu" << endl;
    cout << "0. Kembali ke menu utama" << endl;
    cout << endl;
    cout << "Masukan pilihan anda: ";
    cin >> input;

    switch( input )
    {
        case 1  :
            viewAll();
            break;
        case 2  :
            viewAllKeluarga();
            break;
        case 3  :
            viewKeluarga();
            break;
        case 0  :
           home();
            break;
        default :
            cout << "Input yang anda masukkan salah, silahkan ulangi lagi";
            hold();
            viewData();
            break;
    }
}

void updateData()
{
    int input;
    clearScreen();

    cout << "           PERBARUI DATA          " << endl;
    cout << "----------------------------------" << endl;
    cout << "1. Perbarui data keluarga" << endl;
    cout << "2. Perbarui data anggota keluarga" << endl;
    cout << "0. Kembali ke menu utama" << endl;
    cout << endl;
    cout << "Masukan pilihan anda: ";
    cin >> input;

    switch( input )
    {
        case 1  :
            updateKeluarga();
            break;
        case 2  :
            updateAnggotaKeluarga();
            break;
        case 0  :
            home();
            break;
        default :
            cout << "Input yang anda masukkan salah, silahkan ulangi lagi";
            hold();
            updateData();
            break;
    }
}

void removeData()
{
    int input;
    clearScreen();

    cout << "             HAPUS DATA           " << endl;
    cout << "----------------------------------" << endl;
    cout << "1. Hapus data keluarga" << endl;
    cout << "2. Hapus data anggota keluarga" << endl;
    cout << "0. Kembali ke menu utama" << endl;
    cout << endl;
    cout << "Masukan pilihan anda: ";
    cin >> input;

    switch( input )
    {
        case 1  :
            removeKeluarga();
            break;
        case 2  :
            removeAnggotaKeluarga();
            break;
        case 0  :
            home();
            break;
        default :
            cout << "Input yang anda masukkan salah, silahkan ulangi lagi";
            hold();
            removeData();
            break;
    }
}

void quit()
{
    clearScreen();
    cout << "    APLIKASI PENDATAAN KELUARGA    " << endl;
    cout << "-----------------------------------" << endl;
    cout << "Terima kasih telah menggunakan aplikasi pendataan keluarga" << endl;
    hold();
}

void home()
{
    int input;
    clearScreen();

    cout << "    APLIKASI PENDATAAN KELUARGA    " << endl;
    cout << "-----------------------------------" << endl;
    cout << "1. Tambahkan data keluarga"  << endl;
    cout << "2. Lihat data"  << endl;
    cout << "3. Perbarui data"  << endl;
    cout << "4. Hapus data"  << endl;
    cout << "0. Keluar" << endl;
    cout << endl;
    cout << "Masukan pilihan anda: ";
    cin >> input;

    switch( input )
    {
        case 1  :
            addData();
            break;
        case 2  :
            viewData();
            break;
        case 3  :
            updateData();
            break;
        case 4  :
            removeData();
            break;
        case 0  :
            quit();
            break;
        default :
            cout << "Input yang anda masukkan salah, silahkan ulangi lagi";
            hold();
            home();
            break;
    }
}
