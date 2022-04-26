#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H
#include <iostream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    int idOstatniegoAdresata;
    Adresat adresat;
    vector <Adresat> adresaci;
    Adresat podajDaneNowegoAdresata();
    string wczytajLinie();
    PlikZAdresatami plikZAdresatami;
    void wyswietlDaneAdresata(Adresat adresat);

public:

    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
        : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
        {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        };
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void ustawIdOstatniegoAdresata();
    void wyczyscAdresatow();
};

#endif
