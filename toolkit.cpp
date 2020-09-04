#include "toolkit.h"

void clearScreen()
{
    cout << string( 30, '\n' );
}

void hold()
{
    cout << endl << "Tekan enter untuk melanjutkan...";
    cin.get();
    cin.get();
}
