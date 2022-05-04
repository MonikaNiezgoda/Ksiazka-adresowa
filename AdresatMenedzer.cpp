#include "AdresatMenedzer.h"


void AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    if (plikZAdresatami.dopiszAdresataDoPliku(adresat))
        cout << "Nowy adresat zostal dodany do ksiazki" << endl;
    else
        cout << "Blad. Nie udalo sie dodac nowego adresata do pliku."<< endl;
    system("pause");
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{
    Adresat adresat;
    MetodyPomocnicze metodyPomocnicze;

    adresat.ustawId( (plikZAdresatami.pobierzIdOstatniegoAdresata()+1) );
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

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

void AdresatMenedzer::wyswietlWszystkichAdresatow()
{
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


void AdresatMenedzer::wyczyscAdresatow()
{
    adresaci.clear();
}

void AdresatMenedzer::usunAdresata()
{
    MetodyPomocnicze metodyPomocnicze;
    idUsuwanegoAdresata = 0;
    int numerLiniiUsuwanegoAdresata = 0;


    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (itr -> pobierzId() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = metodyPomocnicze.wczytajZnak();
            if (znak == 't')
            {
                plikZAdresatami.usunWybranaLinieWPliku(idUsuwanegoAdresata);
                adresaci.erase(itr);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
}

int AdresatMenedzer::podajIdWybranegoAdresata()
{
    MetodyPomocnicze metodyPomocnicze;
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = metodyPomocnicze.wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}

void AdresatMenedzer::edytujAdresata()
{
    system("cls");
    MetodyPomocnicze metodyPomocnicze;
    plikZAdresatami.ustawIdEdytowanegoAdresata(0);
    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    plikZAdresatami.ustawIdEdytowanegoAdresata(podajIdWybranegoAdresata());

    char wybor;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzId() == plikZAdresatami.pobierzIdEdytowanegoAdresata())
        {
            czyIstniejeAdresat = true;
            wybor = wybierzOpcjeZMenuEdycja();

            switch (wybor)
            {
            case '1':{
                cout << "Podaj nowe imie: ";
                string noweImie;
                noweImie = wczytajLinie();
                adresaci[i].ustawImie(metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(noweImie));
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);}
                break;
            case '2':{
                cout << "Podaj nowe nazwisko: ";
                string noweNazwisko;
                noweNazwisko=wczytajLinie();
                adresaci[i].ustawNazwisko(metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(noweNazwisko));
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);}
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                adresaci[i].ustawNumerTelefonu(wczytajLinie());
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                adresaci[i].ustawEmail(wczytajLinie());
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].ustawAdres(wczytajLinie());
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

char AdresatMenedzer::wybierzOpcjeZMenuEdycja()
{
    MetodyPomocnicze metodyPomocnicze;
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = metodyPomocnicze.wczytajZnak();

    return wybor;
}






