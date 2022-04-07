#include "AdresatMenedzer.h"

int AdresatMenedzer::dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    return ++idOstatniegoAdresata;
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
    Adresat adresat;
    MetodyPomocnicze metodyPomocnicze;

    adresat.ustawId(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    string imie;
    cout << "Podaj imie: ";
    imie = wczytajLinie();
    adresat.ustawImie(metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie));

    string nazwisko;
    cout << "Podaj nazwisko: ";
    nazwisko = wczytajLinie();
    adresat.ustawNazwisko(metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(wczytajLinie());

    return adresat;
}

string AdresatMenedzer::wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}
