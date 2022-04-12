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

    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
    string wczytajLinie();
    PlikZAdresatami plikZAdresatami;
    Adresat adresat;
    void wyswietlDaneAdresata(Adresat adresat);

public:
    vector <Adresat> adresaci;
    int dodajAdresata(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika);
    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami){};
    void wyswietlWszystkichAdresatow();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
};

#endif
