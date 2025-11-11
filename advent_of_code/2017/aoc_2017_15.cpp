#include <iostream>
#include <bitset>

using namespace std;

int match = 0;

uint64_t genAVypocet(uint64_t A) {
    uint64_t vypocet = A * 16807;
    return vypocet % 2147483647;
}

uint64_t genBVypocet(uint64_t B) {
    uint64_t vypocet = B * 48271;
    return vypocet % 2147483647;
}

bitset<32> genAToBin(uint64_t A) {
    bitset<32> binA(A);
    return binA;
}

bitset<32> genBToBin(uint64_t B) {
    bitset<32> binB(B);
    return binB;
}

void compare(bitset<32> binA, bitset<32> binB) {
    bool stejne = true;
    for (int i = 0; i < 16; i++) {
        if (binA[i] != binB[i]) {
            stejne = false;
            break;
        }
    }
    if (stejne) {
        match++;
    }
}

int main() {
    uint meziVypocetA = 65, meziVypocetB = 8921;
    bitset<32> binaryA, binaryB;

    for (int i = 0; i < 5; i++) {
        meziVypocetA = genAVypocet(meziVypocetA);
        meziVypocetB = genBVypocet(meziVypocetB);
        binaryA = genAToBin(meziVypocetA);
        binaryB = genBToBin(meziVypocetB);
        compare(binaryA, binaryB);
        cout << "A: " << meziVypocetA << ", B: " << meziVypocetB << endl;
        cout << "binární reprezentace A: " << binaryA << ", B: " << binaryB << endl;
    }

    //cout << "A: " << genA << ", B: " << genB << endl;
    //cout << "binární reprezentace A: " << binaryA << ", B: " << binaryB << endl;
    cout << "počet stejných: " << match << endl;

    return 0;
}