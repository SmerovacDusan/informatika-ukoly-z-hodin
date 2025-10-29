#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

struct Student {
    int id;
    string jmeno;
    double prumer;
};

struct Uzel {
    Student student;
    Uzel* dalsi;

    Uzel(Student newStudent) {
        student = newStudent;
        dalsi = nullptr;
    }
};

Student parsujRadek(const string& radek) {
    Student s;
    stringstream vstup(radek);
    string idVstup, jmenoVstup, prumerVstup;

    getline(vstup, idVstup, ',');
    getline(vstup, jmenoVstup, ',');
    getline(vstup, prumerVstup, ',');

    s.id = stoi(idVstup);
    s.jmeno = jmenoVstup;
    s.prumer = stod(prumerVstup);

    return s;
}

Uzel* pridejStudentaNaKonec(Uzel* head, Student newStudent) {
    Uzel* newUzel = new Uzel(newStudent);

    if (head == nullptr) {
        return newUzel;
    }

    Uzel* posledni = head;

    while(posledni -> dalsi != nullptr) {
        posledni = posledni -> dalsi;
    }

    posledni -> dalsi = newUzel;
    return head;
}

Uzel* nactiStudentyZeSouboru(const string& nazevSouboru) {
    ifstream soubor(nazevSouboru);
    string radek;
    Uzel* head = nullptr;

    if(!soubor.is_open()) {
        cout << "Soubor nelze otevřít!" << endl;
    }
    else {
        while (getline(soubor, radek)) {
            if (radek.find("#") != 0 || radek.empty()) {
                head = pridejStudentaNaKonec(head, parsujRadek(radek));
            }
        }
    }
    soubor.close();
    return head;
}

void vypisSeznam(Uzel* head) {
    Uzel* current = head;
    while (current != nullptr) {
        cout << current -> student.id << setw(5) << current -> student.jmeno << setw(5) << current -> student.prumer << endl;
        current = current -> dalsi;
    }
}

void setridSeznamPodlePrumeru(Uzel* head) {
    for (Uzel* i = head; i != nullptr; i = i -> dalsi) {
        Uzel* minUzel = i;
        for (Uzel* j = i -> dalsi; j != nullptr; j = j -> dalsi) {
            if (j -> student.prumer < minUzel -> student.prumer) {
                minUzel = j;
            }
        }
        if (minUzel != i) {
            swap(i -> student, minUzel -> student);
        }
    }
}

void ulozStudentyDoSouboru(const string& nazevSouboru, Uzel* head) {
    ofstream soubor(nazevSouboru);

    if (!soubor.is_open()) {
        cout << "Soubor nelze otevřít" << nazevSouboru << endl;
        return;
    }

    Uzel* current = head;
    while (current != nullptr) {
        soubor << current -> student.id << "," << current -> student.jmeno << "," << current -> student.prumer << endl;
        current = current -> dalsi;
    }
    soubor.close();
}

void zrusSeznam(Uzel** pHead) {
    Uzel* current = *pHead;
    while (current != nullptr) {
        Uzel* dalsi = current -> dalsi;
        delete current;
        current = dalsi;
    }
    *pHead = nullptr;
}

int main() {
    string inputSoubor = "studenti.txt";
    string outputSoubor = "studenti_serazeno.txt";

    Uzel* head = nactiStudentyZeSouboru(inputSoubor);

    cout << "Před sežazením:" << endl;
    vypisSeznam(head);

    setridSeznamPodlePrumeru(head);

    cout << "\n Po seřazení:" << endl;
    vypisSeznam(head);

    Student st = parsujRadek("111, Karel Hajek, 4.3");

    pridejStudentaNaKonec(head, st);

    ulozStudentyDoSouboru(outputSoubor, head);

    return 0;
}