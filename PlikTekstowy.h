#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class PlikTekstowy
{

    const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI;

public:

    PlikTekstowy(string nazwaPlikuZUzytkownikami) : NAZWA_PLIKU_Z_UZYTKOWNIKAMI(nazwaPlikuZUzytkownikami) {
    };
    string pobierzNazwePliku();
    bool czyPlikJestPusty();

    #endif
