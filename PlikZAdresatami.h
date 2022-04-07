#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H
#include <iostream>
#include <vector>
#include <fstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami
{
    const string nazwaPlikuZAdresatami;
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    bool czyPlikJestPusty();
    MetodyPomocnicze metodyPomocnicze;
public:
    void dopiszAdresataDoPliku(Adresat adresat);
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI) : nazwaPlikuZAdresatami("Adresaci.txt") {};
};

#endif
