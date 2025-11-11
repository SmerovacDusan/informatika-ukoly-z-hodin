#include <iostream>

using namespace std;

void caesar(string text, int posun) {
    int ascii;
    char posunutyChar;
    for (char c : text) {
        if (c == ' ') {
            posunutyChar = ' ';
        }
        else {
            ascii = c;
            ascii += posun;
            if (ascii > 'z') {
                ascii = 'a' + (ascii - 'z' - 1);
            }

            posunutyChar = ascii;
        }

        cout << posunutyChar;
    }
}

int main() {
    string text = "nvidia fuck you";
    int posun;
    //cout << "Zadejte text k zašifrování: ";
    //cin >> text;
    string lower;
    for (char c : text) {
        lower += tolower(c);
    }
    cout << "Zadejte posun: ";
    cin >> posun;

    caesar(lower, posun);
    cout << endl;
}