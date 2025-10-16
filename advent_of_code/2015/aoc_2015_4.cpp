#include <iostream>
#include <openssl/md5.h>
#include <sstream>
#include <iomanip>
// NUTNÉ ZKOMPILOVAT POMOCÍ PŘÍKAZU g++ md5_test.cpp -o md5_test.out -lcrypto -lssl

using namespace std;

string md5(const string& input) {
    unsigned char result[MD5_DIGEST_LENGTH];
    MD5(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), result);

    ostringstream oss;
    for (unsigned char c : result)
        oss << hex << setw(2) << setfill('0') << (int)c;
    return oss.str();
}

int main() {
    string text = "iwrupvqb", kandidat, kandidatMD5;
    int cislo, pocetNul = 0;

    int i = 0;

    while (true) {
        string input = text + to_string(i);
        string hash = md5(input);

        if (hash.rfind("000000", 0) == 0) {
            cout << "Nalezeno číslo: " << i << endl;
            cout << "Hash: " << hash << endl;
            break;
        }

        i++;
    }

    return 0;
}