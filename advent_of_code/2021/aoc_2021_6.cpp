#include <iostream>
#include <vector>

using namespace std;

vector<int> timers = {1,4,3,3,1,3,1,1,1,2,1,1,1,4,4,1,5,5,3,1,3,5,2,1,5,2,4,1,4,5,4,1,5,1,5,5,1,1,1,4,1,5,1,1,1,1,1,4,1,2,5,1,4,1,2,1,1,5,1,1,1,1,4,1,5,1,1,2,1,4,5,1,2,1,2,2,1,1,1,1,1,5,5,3,1,1,1,1,1,4,2,4,1,2,1,4,2,3,1,4,5,3,3,2,1,1,5,4,1,1,1,2,1,1,5,4,5,1,3,1,1,1,1,1,1,2,1,3,1,2,1,1,1,1,1,1,1,2,1,1,1,1,2,1,1,1,1,1,1,4,5,1,3,1,4,4,2,3,4,1,1,1,5,1,1,1,4,1,5,4,3,1,5,1,1,1,1,1,5,4,1,1,1,4,3,1,3,3,1,3,2,1,1,3,1,1,4,5,1,1,1,1,1,3,1,4,1,3,1,5,4,5,1,1,5,1,1,4,1,1,1,3,1,1,4,2,3,1,1,1,1,2,4,1,1,1,1,1,2,3,1,5,5,1,4,1,1,1,1,3,3,1,4,1,2,1,3,1,1,1,3,2,2,1,5,1,1,3,2,1,1,5,1,1,1,1,1,1,1,1,1,1,2,5,1,1,1,1,3,1,1,1,1,1,1,1,1,5,5,1
};

class Fih {
    private:
        
    public:
        void novyDen() {
            for (int i = 0; i < timers.size(); i++) {
                timers[i] -= 1;
            }
        }

        void kontrola() {
            for (int i = 0; i < timers.size(); i++) {
                if (timers[i] < 0) {
                    timers.at(i) = 6;
                    timers.push_back(8);
                }
            } 
        }

        void vypisVector() {
            for (int n : timers) {
                cout << n << " ";
            }
            cout << endl;
        }

};

int main() {
    int dny = 256;
    Fih fih;
    fih.vypisVector();
    for (int i = 0; i < dny; i++) {
        fih.novyDen();
        fih.kontrola();
        fih.vypisVector();
    }

    cout << "Počet ryb po " << dny << " dnech je: " << timers.size() << endl;
}