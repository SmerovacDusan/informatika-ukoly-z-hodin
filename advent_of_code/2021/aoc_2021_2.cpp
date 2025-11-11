#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

int x = 0, y = 0, aim = 0;

void vypocetSouradnic(vector<string>& input, set<pair<int, int>>& souradnice) {
    string hodnota;
    for (int i = 0; i < input.size(); i++) {
        hodnota = input[i];
        int cislo = 0;

        for (int j = 0; j < hodnota.size(); j++) {
            if (isdigit(hodnota[j])) {
                cislo = cislo * 10 + (hodnota[j] - '0');
            }
        }

        if(input[i].find("forward") != string::npos) {
            x += cislo;
            y += aim * cislo;
            souradnice.insert({x, y});   
        }
        else if (input[i].find("up") != string::npos) {
            // není potřeba v druhé části úkolu
            //y -= cislo;
            aim -= cislo;
            souradnice.insert({x, y});
        }
        else if (input[i].find("down") != string::npos) {
            // není potřeba v druhé části úkolu
            //y += cislo;
            aim += cislo; 
            souradnice.insert({x, y});
        }
    }
}

int nasobeniSouradnic(int x, int y) {
    return x * y;
}

int main() {
    string nacteniHodnoty;
    set<pair<int, int>> souradnice;
    
    souradnice.insert({x, y});
    vector<string> input;

    ifstream soubor("aoc_2021_2_input.txt");
    while (getline(soubor, nacteniHodnoty)) {
        input.push_back(nacteniHodnoty);
    }

    vypocetSouradnic(input, souradnice);

    cout << "x: " << x << " y: " << y << endl;

    cout << nasobeniSouradnic(x, y) << endl;

    return 0;
}