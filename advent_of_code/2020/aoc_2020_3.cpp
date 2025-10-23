#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const string soubor = "aoc_2020_3_input.txt";

    int pocet_radku = 0;
    int pocet_sloupcu = 0;
    string b_radek; // Dočasný buffer pro čtení řádků

    ifstream soubor_1_p(soubor);
    if (!soubor_1_p.is_open()) {
        cerr << "Chyba: Soubor '" << soubor << "' se nepodařilo otevřít!" << std::endl;
        return 1;
    }

    while (getline(soubor_1_p, b_radek)) {
        if (!b_radek.empty()) {
            if (pocet_radku == 0) {
                // Toto je první řádek, uložíme jeho délku
                pocet_sloupcu = b_radek.length();
            }
            pocet_radku++; // Počítáme neprázdné řádky
        }
    }
    soubor_1_p.close();

    // Zkontrolujeme, jestli jsme něco načetli
    if (pocet_radku == 0 || pocet_sloupcu == 0) {
        cerr << "Chyba: Soubor je prázdný nebo má nulovou šířku!" << endl;
        return 1;
    }
    
    // Vypíšeme zjištěné rozměry
    cout << "Mapa nactena: " << pocet_radku << " radku, " << pocet_sloupcu << " sloupcu." << endl;


    // --- 2. DYNAMICKÁ ALOKACE PAMĚTI ---
    
    // 'mapa' je pointer na pole pointerů (každý pointer bude ukazovat na jeden řádek)
    char** mapa = new char*[pocet_radku];
    // Poznámka: V tuto chvíli jsme alokovali pouze "svislé" pole pointerů.
    // Jednotlivé řádky (pole charů) alokujeme až ve druhém průchodu.


    // --- 3. DRUHÝ PRŮCHOD: Načtení dat do alokované paměti ---
    
    ifstream soubor_2_p(soubor);
    if (!soubor_2_p.is_open()) {
        cerr << "Chyba: Soubor '" << soubor << "' se nepodařilo otevřít podruhé!" << endl;
        // Uvolníme paměť, kterou jsme už alokovali
        delete[] mapa; 
        return 1;
    }

    int current_row = 0;
    while (getline(soubor_2_p, b_radek)) {
        if (!b_radek.empty()) {
            // Alokujeme paměť pro aktuální řádek
            mapa[current_row] = new char[pocet_sloupcu];
            
            // Zkopírujeme znaky z bufferu do našeho dynamického pole
            for (int j = 0; j < pocet_sloupcu; ++j) {
                // Musíme ošetřit případ, že by řádek byl kratší (i když by neměl být)
                if (j < b_radek.length()) {
                    mapa[current_row][j] = b_radek[j];
                } else {
                    mapa[current_row][j] = ' '; // Pojistka
                }
            }
            current_row++;
        }
    }
    soubor_2_p.close();


    // --- 4. Logika Advent of Code ---

    const int pocet_variant = 5;
    int varianty[pocet_variant][2] = {
        {1, 1},
        {3, 1},
        {5, 1},
        {7, 1},
        {1, 2}
    };

    // Dynamické pole pro výsledky
    long long* vysledky = new long long[pocet_variant];

    // Cyklus řešící problém pro jednotlivé varianty
    for (int i = 0; i < pocet_variant; ++i) {
        int vpravo = varianty[i][0];
        int dolu = varianty[i][1];

        int x = 0;
        int y = 0;
        long long pocet = 0; 

        while (y < pocet_radku) {
            // Přístup k prvku pomocí pointerové syntaxe: *(*(mapa + y) + x)
            // nebo ekvivalentní a čitelnější syntaxe pole: mapa[y][x]
            if (mapa[y][x] == '#') {
                pocet++;
            }

            x = (x + vpravo) % pocet_sloupcu;
            y = y + dolu;
        }
        
        // Uložení výsledku pomocí pointerové syntaxe: *(vysledky + i) = pocet
        // nebo ekvivalentní syntaxe pole: vysledky[i] = pocet
        vysledky[i] = pocet;
    }


    // --- 5. Výpočet a tisk celkového součinu ---
    
    long long soucin = 1;
    for (int i = 0; i < pocet_variant; ++i) {
        soucin *= vysledky[i];
    }

    cout << "Vysledky jednotlivych variant:" << endl;
    for (int i = 0; i < pocet_variant; ++i) {
        cout << "Varianta 'right " << varianty[i][0] <<", down " << varianty[i][1] << "': " << vysledky[i] << endl;
    }   
    cout << "Celkovy soucin stromu: " << soucin << endl;


    // --- 6. Uvolnění veškeré dynamicky alokované paměti ---
    
    // Musíme uvolnit každý řádek mapy
    for (int i = 0; i < pocet_radku; ++i) {
        delete[] mapa[i]; // Uvolní pole charů (jeden řádek)
    }
    // Nakonec uvolníme pole pointerů na řádky
    delete[] mapa;

    // Uvolníme pole výsledků
    delete[] vysledky;

    return 0; // Program skončil úspěšně
}