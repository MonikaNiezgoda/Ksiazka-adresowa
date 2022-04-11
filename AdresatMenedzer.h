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

    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    string wczytajLinie();
    PlikZAdresatami plikZAdresatami;
    void wyswietlDaneAdresata(Adresat adresat);

public:
    vector <Adresat> adresaci;

    int dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami){};
    void wyswietlWszystkichAdresatow();
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika);

};

#endif
