#include <iostream>

using namespace std;

class Obdelnik {
    private:
        int a = 10;
        int b = 12;

        public:
        void tisk() {
            cout << "Strana a: " << a << ", strana b: " << b << endl;
        }

        void nastavHodnotuA(int a) {
            this -> a = a;
        }

        void nastavHodnotuB(int b) {
            this -> b = b;
        }

        int obsah() {
            return a * b;
        }

        int obvod() {
            return 2 * (a + b);
        }
};

int main() {
    Obdelnik obdelnik1;
    Obdelnik* pObdelnik1 = &obdelnik1;

    obdelnik1.nastavHodnotuA(15);
    obdelnik1.nastavHodnotuB(10);
    obdelnik1.tisk();

    // práce s pointery, první příklad je lépe čitelnější a používá se častěji
    //pObdelnik1 -> tisk();
    //(*pObdelnik1).tisk();

    cout << "Obvod obdélníku: " << obdelnik1.obvod() << ", obsah obdélníku: " << obdelnik1.obsah() << endl;

    return 0;
}