#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H
#include <iostream>
#include <vector>
#include <fstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
//#include "PlikTekstowy.h"

using namespace std;

class PlikZAdresatami : public PlikTekstowy
{
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    const string NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI;
    int idOstatniegoAdresata;
    int idEdytowanegoAdresata;
    MetodyPomocnicze metodyPomocnicze;

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);

public:
    PlikZAdresatami(string nazwaPlikuZAdresatami, string nazwaTymczasowegoPlikuZAdresatami) : PlikTekstowy(nazwaPlikuZAdresatami),
    NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami),
    NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI(nazwaTymczasowegoPlikuZAdresatami) {
    idOstatniegoAdresata=0;
    };
    int pobierzIdOstatniegoAdresata();
    void ustawIdOstatniegoAdresata(int noweId);
    int pobierzIdEdytowanegoAdresata();
    void ustawIdEdytowanegoAdresata(int noweId);
    bool dopiszAdresataDoPliku(Adresat adresat);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void usunWybranaLinieWPliku(int idUsuwanegoAdresata);
    void edytujWybranaLinieWPliku(string liniaZDanymiAdresataOddzielonePionowymiKreskami);
    void zaktualizujDaneWybranegoAdresata(Adresat adresat);

};

#endif
