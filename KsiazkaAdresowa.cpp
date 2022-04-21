#include "KsiazkaAdresowa.h"


void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    idZalogowanegoUzytkownika=uzytkownikMenedzer.logowanieUzytkownika();
    adresatMenedzer.ustawIdOstatniegoAdresata();

}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::dodajAdresata()
{
   adresatMenedzer.dodajAdresata(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    adresatMenedzer.wyswietlWszystkichAdresatow(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
   idZalogowanegoUzytkownika=uzytkownikMenedzer.wylogowanieUzytkownika(idZalogowanegoUzytkownika);
   adresatMenedzer.wyczyscAdresatow();

}

void KsiazkaAdresowa::ustawId(int noweId)
{
    if (noweId >= 0)
    idZalogowanegoUzytkownika = noweId;
}
int KsiazkaAdresowa::pobierzId()
{
    return idZalogowanegoUzytkownika;
}
