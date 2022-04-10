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
    if (adresatMenedzer.adresaci.empty() == true)
    idOstatniegoAdresata = adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresatMenedzer.adresaci, idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::dodajAdresata()
{
    adresatMenedzer.dodajAdresata(idZalogowanegoUzytkownika,idOstatniegoAdresata);
}

void KsiazkaAdresowa::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    idOstatniegoAdresata=adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresatMenedzer.adresaci,idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    adresatMenedzer.wyswietlWszystkichAdresatow();
}
