#include <iostream>
#include "KsiazkaAdresowa.h"
#include "AdresatMenedzer.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt");
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

   /* ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();*/

    //ksiazkaAdresowa.logowanieUzytkownika();
    AdresatMenedzer adresatMenedzer("Adresaci.txt");
    adresatMenedzer.dodajAdresata(1,1);




    return 0;
}
