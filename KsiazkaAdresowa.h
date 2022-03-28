#include <iostream>
#include <vector>
#include "Uzytkownik.h"
#include <fstream>
#include <windows.h>
#include <sstream>

using namespace std;

class KsiazkaAdresowa
{
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;
    string nazwaPlikuZUzytkownikami;

    vector <Uzytkownik> uzytkownicy;
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    Uzytkownik podajDaneNowegoUzytkownika();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    string konwerjsaIntNaString(int liczba);
    bool czyPlikJestPusty(fstream &plikTekstowy);

public:
    KsiazkaAdresowa();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
};
