#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

bool vyskytSamohlasky = false, vyskytDvojiteZnaky = false, vyskytZakazaneStringy = false, vyskytDvojice = false, vyskytOpakujicichZnaku = false;
int pocetNiceStrings = 0, pocetNiceStringsPart2 = 0;

void vowels(string jmeno) {
    int samohlasky = 0;
    for (char c : jmeno) {
        if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u') {
            samohlasky++;
        }
    }

    if (samohlasky >= 3) {
        vyskytSamohlasky = true;
    }
    else {
        vyskytSamohlasky = false;
    }
}

void doubleLetter(string jmeno) {
    char posledniZnak = 0;
    int dvojiteZnaky = 0;

    for (int i = 0; i < jmeno.size(); i++) {
        if (posledniZnak == jmeno[i]) {
            dvojiteZnaky++;
        }

        posledniZnak = jmeno[i];
    }

    if (dvojiteZnaky >= 1) {
        vyskytDvojiteZnaky = true;
    }
    else {
        vyskytDvojiteZnaky = false;
    }
}

void zakazaneStringy(string jmeno) {
    vyskytZakazaneStringy = false;

    for (int i = 0; i < jmeno.size(); i++) {
        //spojeni = string() + posledniZnak + jmeno[i];
        string dvojice = "";
        dvojice += jmeno[i-1];
        dvojice += jmeno[i];
        if (dvojice == "ab" || dvojice == "cd" || dvojice == "pq" || dvojice == "xy") {
            vyskytZakazaneStringy = true;
            break;
        }
    }
}

void kontrola (bool samohlasky, bool dvojiteZnaky, bool zakazaneStringy) {
    if (samohlasky && dvojiteZnaky && !zakazaneStringy) {
        pocetNiceStrings++;
    }
}

void kontrolaDvojicPart2(string input) {
    vyskytDvojice = false;

    for (int i = 0; i < input.size() - 1; i++) {
        string dvojice = string(1, input[i]) + input[i + 1];

        for (int j = i + 2; j < input.size() - 1; j++) {
            string dalsi = string(1, input[j]) + input[j + 1];
            if (dvojice == dalsi) {
                vyskytDvojice = true;
                break;
            }
        }

        if (vyskytDvojice) {
            break;
        }
    }
}

void kontrolaOpakujicihoPismena(string input) {
    vyskytOpakujicichZnaku = false;

    for (int i = 0; i < input.size() - 2; i++) {
        if (input[i] == input[i+2]) {
            vyskytOpakujicichZnaku = true;
            break;
        }
    }

}

void kontrolaPart2(bool dvojice, bool opakovani) {
    dvojice = vyskytDvojice;
    opakovani = vyskytOpakujicichZnaku;

    if (vyskytDvojice && vyskytOpakujicichZnaku) {
        pocetNiceStringsPart2++;
    }
}

int main() {
    vector<string> stringy;
    string fileInput;

    ifstream inputSoubor("aoc_2015_5_input.txt");

    if (inputSoubor.is_open()) {
        while (getline(inputSoubor, fileInput)) {
            stringy.push_back(fileInput);
        }
    }

    for (int i = 0; i < stringy.size(); i++) {
        vowels(stringy[i]);
        doubleLetter(stringy[i]);
        zakazaneStringy(stringy[i]);
        kontrola(vyskytSamohlasky, vyskytDvojiteZnaky, vyskytZakazaneStringy);
        kontrolaDvojicPart2(stringy[i]);
        kontrolaOpakujicihoPismena(stringy[i]);
        kontrolaPart2(vyskytDvojice, vyskytOpakujicichZnaku);
    }

    cout << "Počet nice strings part 1: " << pocetNiceStrings << endl;
    cout << "Počet nice strings part 2: " << pocetNiceStringsPart2 << endl;

    return 0;
}