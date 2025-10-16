#include <iostream>
#include <set>
#include <utility>
#include <fstream>

using namespace std;

int main() {
    set<pair<int, int>> souradnice;
    set<pair<int, int>> souradniceRobo;
    int x = 0, y = 0, xRobo = 0, yRobo = 0;
    souradnice.insert({x, y});
    souradniceRobo.insert({xRobo, yRobo});
    string pohyb = "", fileInput;
    
    ifstream soubor("aoc_2015_3_input.txt");
    while (getline(soubor, fileInput)) {
        pohyb += fileInput;
    }
    
    for (int i = 0; i < pohyb.size(); i++) {
        if (i % 2 == 0) {
            if (pohyb[i] == '>') {
                x++;
                souradnice.insert({x, y});
            }
            else if (pohyb[i] == '<') {
                x--;
                souradnice.insert({x, y});
            }
            else if (pohyb[i] == '^') {
                y++;
                souradnice.insert({x, y});
            }
            else if (pohyb[i] == 'v') {
                y--;
                souradnice.insert({x, y});
            }
        }
        else {
            if (pohyb[i] == '>') {
                xRobo++;
                souradniceRobo.insert({xRobo, yRobo});
            }
            else if (pohyb[i] == '<') {
                xRobo--;
                souradniceRobo.insert({xRobo, yRobo});
            }
            else if (pohyb[i] == '^') {
                yRobo++;
                souradniceRobo.insert({xRobo, yRobo});
            }
            else if (pohyb[i] == 'v') {
                yRobo--;
                souradniceRobo.insert({xRobo, yRobo});
            }
        }
        
    }

    set<pair<int, int>> vsechnySouradnice = souradnice;
    vsechnySouradnice.insert(souradniceRobo.begin(), souradniceRobo.end());

    cout << vsechnySouradnice.size() << endl;

    return 0;
}