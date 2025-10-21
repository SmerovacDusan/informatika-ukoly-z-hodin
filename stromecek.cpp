#include <iostream>

using namespace std;

int main() {
    cout<< "Zadejte vysku koruny stromu: ";
    int vyska;
    cin >> vyska;

    cout << "Zadejte sirku kmene stromu: ";
    int sirka;
    cin >> sirka;

    cout << "Zadejte vysku kmene stromu: ";
    int vyska_kmene;
    cin >> vyska_kmene;

    for (int i = 0; i < vyska; ++i) {
        for (int j = 0; j < vyska - i - 1; ++j) {
            cout << ' ';
        }
        for (int k = 0; k < (2 * i + 1); ++k) {
            cout << '*';
        }
        cout << endl;
    }
    for (int i = 0; i < vyska_kmene; ++i) {
        for (int j = 0; j < (vyska - sirka / 2 - 1); ++j) {
            cout << ' ';
        }
        for (int k = 0; k < sirka; ++k) {
            cout << '#';
        }
        cout << endl;
    }
    return 0;
}