#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <sstream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"


using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer adresatMenedzer;
    int idZalogowanegoUzytkownika;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami,string nazwaPlikuZAdresatami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami),
    adresatMenedzer(nazwaPlikuZAdresatami) {
        uzytkownikMenedzer.wczytajUzytkownikowZPliku();};
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wyswietlWszystkichAdresatow();
    void dodajAdresata();

};

#endif // KSIAZKAADRESOWA_H
