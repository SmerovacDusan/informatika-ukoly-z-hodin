#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int vypocet (int l, int w, int h) {
    int vysledek;

    vysledek = (2 * l * w) + (2 * w * h) + (2 * h * l);
    
    vector<int> strany = {l, w, h};
    sort(strany.begin(), strany.end());

    vysledek += strany[0] * strany[1];
    return vysledek;
}

int ribbon (int length, int width, int height) {
    int vysledek;
    
    vector<int> strany = {length, width, height};
    sort(strany.begin(), strany.end());

    vysledek = (2 * strany[0]) + (2 * strany[1]);
    vysledek += length * width * height;
    return vysledek;
}

int main() {
    string stringRozmery;
    int total = 0, ribbonTotal = 0;
    vector<string> hodnoty;
    vector<int> hodnotyLength;
    vector<int> hodnotyWidth;
    vector<int> hodnotyHeight;

    ifstream inputFile("aoc_2015_2_input.txt");
    while (getline (inputFile, stringRozmery)) {
        hodnoty.push_back(stringRozmery);
    }

    for (string hodnota : hodnoty) {
        int pocetX = 0;
        string length = "", width = "", height = "";

        for (int i = 0; i < hodnota.size(); i++) {
            if (hodnota[i] != 'x') {
                if (pocetX == 0)
                    length += hodnota[i];
                else if (pocetX == 1)
                    width += hodnota[i];
                else if (pocetX == 2)
                    height += hodnota[i];
            }
            else {
                pocetX++;
            }
        }

        int l = stoi(length);
        int w = stoi(width);
        int h = stoi(height);

        hodnotyLength.push_back(l);
        hodnotyWidth.push_back(w);
        hodnotyHeight.push_back(h);
    }

    for (int i = 0; i < hodnotyLength.size(); i++) {
        total += vypocet(hodnotyLength[i], hodnotyWidth[i], hodnotyHeight[i]);
        ribbonTotal += ribbon(hodnotyLength[i], hodnotyWidth[i], hodnotyHeight[i]);
    }

    cout << total << endl;
    cout << ribbonTotal << endl;


    return 0;
    // KOMPILOVAT PŘÍKAZEM g++ -std=c++17 aoc_2015_2.cpp -o aoc_2015_2.out KVŮLI stoi()
}