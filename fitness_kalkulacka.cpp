#include <iostream>
#include <cmath>

using namespace std;

void vypocetBMI(double vaha, double vyska) {
    double vypocet;
    
    vyska = vyska / 100;
    vypocet = vaha / pow(vyska, 2);

    if (vypocet < 18.5) {
        cout << "Trpíte podváhou!\n" << endl;
    }
    else if (vypocet >= 18.5 && vypocet < 25) {
        cout << "Normální váha\n" << endl;
    }
    else if (vypocet >= 25 && vypocet < 30) {
        cout << "Trpíte nadváhou\n" << endl;
    }
    else if (vypocet > 30) {
        cout << "Trpíte obezitou!\n" << endl;
    }
}

void vypocetBMR(double vaha, double vyska, int vek, char pohlavi) {
    pohlavi = tolower(pohlavi);
    double vysledek;

    if (pohlavi == 'm') {
        vysledek = 88.4 + 13.4 * vaha + 4.8 * vyska - 5.68 * vek;
        cout << vysledek << "\n\n";
    }
    else if (pohlavi == 'z') {
        vysledek = 447.6 + 9.25 * vaha + 3.1 * vyska - 4.33 * vek;
        cout << vysledek << "\n\n";
    }
    else {
        cout << "Špatně zadáno!\n" << endl;
    }
}

int main() {
    int vyber, inputVek;
    double inputVaha, inputVyska;
    char inputPohlavi;

    while (vyber != 3) {
        cout << "1. Výpočet BMI" << endl;
        cout << "2. Výpočet BMR" << endl;
        cout << "3. Konec" << endl;
        cout << "Vyberte jednu z nabízených možností (1 - 3): ";
        cin >> vyber;

        switch (vyber) {
            case 1:
                cout << "Zadejte váhu (kg): ";
                cin >> inputVaha;
                cout << "Zadejte výšku (cm): ";
                cin >> inputVyska;

                vypocetBMI(inputVaha, inputVyska);
                break;
            
            case 2:
                cout << "Zadejte váhu (kg): ";
                cin >> inputVaha;
                cout << "Zadejte výšku (cm): ";
                cin >> inputVyska;
                cout << "Zadejte věk: ";
                cin >> inputVek;
                cout << "Zadejte pohlaví (M/Z): ";
                cin >> inputPohlavi;

                vypocetBMR(inputVaha, inputVyska, inputVek, inputPohlavi);
                break;
            
            case 3:
                return 0;
                break;

        }
    }
}