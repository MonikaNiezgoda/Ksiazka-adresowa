#include <iostream>
#include <vector>
#include "UzytkownikMenedzer.h"
#include <fstream>
#include <windows.h>
#include <sstream>

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;

public:
    KsiazkaAdresowa();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
};
