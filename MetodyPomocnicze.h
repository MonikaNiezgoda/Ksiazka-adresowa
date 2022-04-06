#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H
#include <iostream>
#include <sstream>
#include <algorithm>

#include "PlikZUzytkownikami.h"
#include "AdresatMenedzer.h"

using namespace std;

class MetodyPomocnicze
{

public:
    static string konwerjsaIntNaString(int liczba);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
};

#endif
