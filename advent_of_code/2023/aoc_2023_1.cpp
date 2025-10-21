#include <iostream>
#include <fstream>

using namespace std;

string cisla[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int prevedNaCislo(string retezec, int pozice) {
    for (int i = 0; i < 9; i++) {
        if(retezec.find(cisla[i], pozice) == pozice){
            return i+1;
        }
    }
    return 0;
}

int main() {
    string input;
    int suma = 0;

    ifstream soubor("aoc_2023_1_input.txt");

    if (!soubor.is_open()) {
        cout << "Soubor se nepodařilo otevřít!";
    }
    else {
        // PRVNÍ ČÁST

        while(getline(soubor, input)) {
            string cislice = "";
            for (int i = 0; i < input.size(); i++) {
                if (isdigit(input[i])) {
                    cislice += input[i];
                    break;
                }

                int cislo = prevedNaCislo(input, i);
                if(cislo != 0){
                    cislice += to_string(cislo);
                    break;
                }
            }

            for (int i = input.size() - 1; i >= 0; i--) {
                if (isdigit(input[i])) {
                    cislice += input[i];
                    break;
                }

                int cislo = prevedNaCislo(input, i);
                if(cislo != 0){
                    cislice += to_string(cislo);
                    break;
                }
            }
            suma += stoi(cislice);
        }   
    }
    cout << suma << endl;

    return 0;
}