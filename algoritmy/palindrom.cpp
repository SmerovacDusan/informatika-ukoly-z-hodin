#include <iostream>
#include <algorithm>

using namespace std;

bool jePalindrom(string slovo) {
    int leva = 0;
    int prava = slovo.size() - 1;

    while(leva < prava) {
        if (slovo[leva] == ' ') {
            leva++;
        }
        if (slovo[prava] == ' ') {
            prava--;
        }
        if (slovo[leva] != slovo[prava]) {
            return false;
        }
        leva++;
        prava--;
    }
    return true;
}

int main() {
    string slovo;
    cout << "Zadejte slovo: ";
    cin >> slovo;

    string slovoObracene = slovo;
    reverse(slovoObracene.begin(), slovoObracene.end());

    if (jePalindrom(slovo)) {
        cout << "zadané slovo je palindrom" << endl;
    }
    else {
        cout << "zadané slovo není palindrom" << endl;
    }
}