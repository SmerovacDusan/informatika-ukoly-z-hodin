#include <iostream>
#include <fstream>

using namespace std;

// řešení na githubu + přetěžování operátorů
class Waypoint {
    private:
        int x = 10;
        int y = 1;
    
    public:
        void vypisPozici() {

        }

        void posunSmerem() {

        }

        void otoc() {

        }

        int getX() {

        }

        int getY() {

        }
};

class Lod {
    private:
        int x = 0;
        int y = 0;
        int stupne = 90;
        string filename, radek;
        char stupneNaSmer() {
            switch (stupne)
            {
            case 0:
                return 'N';
            case 90:
                return 'E';
            case 180:
                return 'S';
            case 270:
                return 'W';
            }
        }
    
    public:
        Lod(string filename) {
            this->filename = filename;
        }

        void navigace() {
            ifstream soubor(filename);
            if (!soubor.is_open()) {
                cerr << "Chyba: Soubor '" << filename << "' se nepodařilo otevřít!" << std::endl;
            }

            while (soubor >> radek) {
                if (!radek.empty()) {
                    char prikaz = radek[0];
                    int hodnota = stoi(radek.substr(1));
                    if (prikaz == 'F') {
                        posunDopredu(hodnota);
                    }
                    else if (prikaz == 'L' || prikaz == 'R') {
                        zmenSmer(prikaz, hodnota);
                    }
                    else {
                        posunSmerem(prikaz, hodnota);
                    }
                }
            }
            soubor.close();
        }

        void zmenSmer(char smer, int stupne) {
            switch (smer) {
                case 'R':
                    this->stupne = (this->stupne + stupne) % 360;
                    break;
                case 'L':
                    this->stupne = (this->stupne - stupne) % 360;
                    if (this->stupne < 0) {
                        this->stupne += 360;
                    }
                    break;
                default:
                    break;;
            }
        }

        void posunDopredu(int kroky) {
            posunSmerem(stupneNaSmer(), kroky);
        }

        void posunSmerem(char smer, int kroky) {
            switch (smer) {
                case 'N':
                    y += kroky;
                    break;
                case 'S':
                    y -= kroky;
                    break;
                case 'E':
                    x += kroky;
                    break;
                case 'W':
                    x -= kroky;
                    break;
            }
        }

        void vypisPozici() {
            cout << "Pozice x: " << x << ", pozice y: " << y << ", smer: " << stupne << ", manhattanovská vzdálenost: " << abs(x) + abs(y) << endl;
        }
};

int main() {
    Lod lod("aoc_2020_12_input.txt");
    lod.navigace();
    lod.vypisPozici();

    return 0;
}