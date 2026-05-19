#include <iostream>
using namespace std;

class RekeningBank {
protected:
    string nama;
    double saldo;

public:
    RekeningBank(string nama, double saldo) {
        this->nama = nama;
        this->saldo = saldo;
    }

    virtual void potongAdmin() = 0;

    void tampilkanInfo() {
        cout << "Nama  : " << nama << endl;
        cout << "Saldo : Rp " << saldo << endl;
        cout << "------------------------" << endl;
    }

    virtual ~RekeningBank() {}
};


class RekeningBRI : public RekeningBank {
public:
    RekeningBRI(string nama, double saldo)
        : RekeningBank(nama, saldo) {}

    void potongAdmin() override {
    }
};

class RekeningBRIPremium : public RekeningBank {
public:
    RekeningBRIPremium(string nama, double saldo)
        : RekeningBank(nama, saldo) {}

    void potongAdmin() override {
        if (saldo > 10000000) {
            // Bebas biaya admin
        } else {
            saldo -= 50000;
        }
    }
};
