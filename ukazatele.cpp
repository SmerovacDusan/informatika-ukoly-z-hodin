#include <iostream>

using namespace std;

void prehodCisla(int* a, int* b) {
    /*
    int temp = *a;
    *a = *b;
    *b = temp;
    */

    // přehození bez třetí proměnné (funguje i XOR)
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

int main() {
    int a = 5;
    int b = 3;

    cout << a << " " << b << endl;

    prehodCisla(&a, &b);

    cout << a << " " << b << endl;

    /*
    int vek = 30;
    int* pVek = &vek;

    cout << pVek << endl; // vypíše adresu
    cout << *pVek << endl; // vypíše hodnotu proměnné věk
    */

    return 0;
}