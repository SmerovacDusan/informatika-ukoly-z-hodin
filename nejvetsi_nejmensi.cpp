#include <iostream>

using namespace std;

void najdiNejmensiNejvetsi(int* pole, int velikostPole, int** nejvetsi, int** nejmensi) {
    int* stop = pole + velikostPole;
    *nejvetsi = pole;
    *nejmensi = pole;

    while(!(pole == stop)) {
        cout << "adresa: " << pole << ", hodnota: " << *pole << endl;

        if (**nejvetsi < *pole) {
            *nejvetsi = pole;
        }

        if (**nejmensi > *pole) {
            *nejmensi = pole;
        }
        pole++;
        // vyzkoušet aoc 2020 day 3 pomocí pointerů
    }
}

int main() {
    int pole[10] = {9,4,6,27,9,2,3,7,5,8};
    int* nejmensi;
    int* nejvetsi;

    najdiNejmensiNejvetsi(pole, 10, &nejvetsi, &nejmensi);

    cout << "nejmenší: " << *nejmensi << " největší: " << *nejvetsi << endl;

    return 0;
}