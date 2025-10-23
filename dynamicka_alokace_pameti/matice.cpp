#include <iostream>
#include <ctime>

using namespace std;

int** nasobekMatic = nullptr;
int** soucetMatic = nullptr;

void tiskniPole(int** pole, int radky, int sloupce) {
    for (int i = 0; i < radky; ++i) {
        for (int j = 0; j < sloupce; ++j) {
            cout << pole[i][j] << "\t";
        }
        cout << endl;
    }
}

int** vytvorPole(int radky, int sloupce) {
    int** pole = new int*[radky];

    for (int i = 0; i < radky; ++i) {
        pole[i] = new int[sloupce];
        for (int j = 0; j < sloupce; ++j) {
            pole[i][j] = rand() % 10;
        }
    }

    return pole;
}

void nasobeniMatic(int** matice1, int** matice2, int radky1, int sloupce1, int radky2, int sloupce2) {
    if (sloupce1 != radky2) {
        cout << "Matice nelze vynásobit!" << endl;
        return;
    }
    
    nasobekMatic = new int*[radky1];
    for (int i = 0; i < radky1; i++) {
        nasobekMatic[i] = new int[sloupce2];
        for (int j = 0; j < sloupce2; j++) {
            nasobekMatic[i][j] = 0;
            for (int k = 0; k < radky2; k++) {
                nasobekMatic[i][j] += matice1[i][k] * matice2[k][j];
            }
            cout << nasobekMatic[i][j] << "\t";
        }
        cout << endl;
    }
}

void scitaniMatic(int** matice1, int** matice2, int radky1, int sloupce1, int radky2, int sloupce2) {
    if (radky1 != radky2 || sloupce1 != sloupce2) {
        cout << "Matice nelze sečíst!" << endl;
        return;
    }
    
    soucetMatic = new int*[radky1];
    for (int i = 0; i < radky1; i++) {
        soucetMatic[i] = new int[sloupce1];
        for (int j = 0; j < sloupce1; j++) {
            soucetMatic[i][j] = matice1[i][j] + matice2[i][j];
            cout << soucetMatic[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));
    int radkyMat1, sloupceMat1, radkyMat2, sloupceMat2;

    cout << "Zadejte počet řádků první matice: ";
    cin >> radkyMat1;
    cout << "Zadejte počet sloupců první matice: ";
    cin >> sloupceMat1;

    cout << "Zadejte počet řádků druhé matice: ";
    cin >> radkyMat2;
    cout << "Zadejte počet sloupců druhé matice: ";
    cin >> sloupceMat2;

    if (radkyMat1 <= 0 || sloupceMat1 <= 0 || radkyMat2 <= 0 || sloupceMat2 <=0 ) {
        cout << "Rozměry musí být kladné!" << endl;
        return 1;
    }

    int** matice1 = nullptr;
    int** matice2 = nullptr;

    matice1 = vytvorPole(radkyMat1, sloupceMat1);
    matice2 = vytvorPole(radkyMat2, sloupceMat2);

    cout << "Matice A:" << endl;
    tiskniPole(matice1, radkyMat1, sloupceMat1);
    cout << endl;
    cout << "Matice B:" << endl;
    tiskniPole(matice2, radkyMat2, sloupceMat2);
    cout << endl;

    cout << "A * B:" << endl;
    nasobeniMatic(matice1, matice2, radkyMat1, sloupceMat1, radkyMat2, sloupceMat2);
    cout << endl;

    cout << "A + B:" << endl;
    scitaniMatic(matice1, matice2, radkyMat1, sloupceMat1, radkyMat2, sloupceMat2);
    cout << endl;

    // uvolnění paměti
    // matice
    for (int i = 0; i < radkyMat1; ++i)
    delete[] matice1[i];
    delete[] matice1;

    for (int i = 0; i < radkyMat2; ++i)
        delete[] matice2[i];
    delete[] matice2;

    // výsledky
    if (nasobekMatic != nullptr) {
        for (int i = 0; i < radkyMat1; ++i)
            delete[] nasobekMatic[i];
        delete[] nasobekMatic;
    }

    if (soucetMatic != nullptr) {
        for (int i = 0; i < radkyMat1; ++i)
            delete[] soucetMatic[i];
        delete[] soucetMatic;
    }

    return 0;
}