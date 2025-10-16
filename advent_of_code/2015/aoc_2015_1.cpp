#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string s = "", fileInput;
    int patro = 0, basementIndex;
    //cin >> s;

    ifstream inputSoubor("aoc_2015_1_input.txt");

    if (inputSoubor.is_open()) {

        while (getline (inputSoubor, fileInput)) {
            s += fileInput;
        }

        for (int i = 0; i < s.length(); i++) {
            if (patro < 0) {
                basementIndex = i;
                break;
            }
            if (s[i] == '(') {
                patro++;
            }
            else {
                patro--;
            }
        }

        // for-each loop, vice pythonovsky zpusob
        /*
        for (char znak : s) {
            if (znak == '(') {
                patro++;
            }
            else {
                patro--;
            }
        }
        */

        cout << patro << endl;
        cout << basementIndex << endl;
        inputSoubor.close();
    }
    else {
        cout << "Chyba při otevírání souboru!" << endl;
    }

    return 0;
}