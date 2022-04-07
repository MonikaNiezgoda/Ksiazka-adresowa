#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H
#include <iostream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer
{
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    vector <Adresat> adresaci;
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    string wczytajLinie();
    PlikZAdresatami plikZAdresatami;

public:
    int dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami){};

};

#endif
