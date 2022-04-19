#include "AdresatMenedzer.h"


void AdresatMenedzer::dodajAdresata(int idZalogowanegoUzytkownika)
{
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika);

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika)
{
    MetodyPomocnicze metodyPomocnicze;
    idOstatniegoAdresata=plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika);

    idOstatniegoAdresata=idOstatniegoAdresata+1;

    adresat.ustawId(idOstatniegoAdresata);
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

    idOstatniegoAdresata++;

    return adresat;
}

string AdresatMenedzer::wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow(int idZalogowanegoUzytkownika)
{
    idOstatniegoAdresata=plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci,idZalogowanegoUzytkownika);
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}
