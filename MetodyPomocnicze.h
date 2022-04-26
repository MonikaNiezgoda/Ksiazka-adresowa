#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H
#include <iostream>
#include <sstream>
#include <algorithm>

#include "PlikZUzytkownikami.h"



using namespace std;

class MetodyPomocnicze
{

public:
    static string konwerjsaIntNaString(int liczba);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    int konwersjaStringNaInt(string liczba);
    char wczytajZnak();
};

#endif
