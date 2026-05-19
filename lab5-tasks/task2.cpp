// задача 2.10

#include <iostream>
#include <cstring>
using namespace std;

class Processor {
private:
    int power;

public:
    Processor() {
        power = 0;
    }

    Processor(int p) {
        power = p;
    }

    int getPower() {
        return power;
    }

    void setPower(int p) {
        power = p;
    }
};

class Computer {
protected:
    Processor cpu;
    char* brand;
    double price;

public:
    Computer() {
        brand = nullptr;
        price = 0;
    }

    Computer(const char* b, double p, int cpuPower) : cpu(cpuPower) {
        brand = new char[strlen(b) + 1];
        strcpy(brand, b);
        price = p;
    }

    virtual ~Computer() {
        delete[] brand;
    }

    virtual void print() {
        cout << "Бренд: " << brand << endl;
        cout << "Ціна: " << price << endl;
        cout << "потужність процесора: " << cpu.getPower() << " MHz" << endl;
    }
};

class PublicComputer : public Computer {
private:
    int monitorSize;

public:
    PublicComputer(const char* b, double p, int cpuPower, int m)
        : Computer(b, p, cpuPower) {
        monitorSize = m;
    }

    ~PublicComputer() {
        cout << "PublicComputer destructor\n";
    }

    void print() {
        Computer::print();
        cout << "розмір монітора: " << monitorSize << " дюймів\n";
    }
};

class PrivateComputer : private Computer {
private:
    int monitorSize;

public:
    PrivateComputer(const char* b, double p, int cpuPower, int m)
        : Computer(b, p, cpuPower) {
        monitorSize = m;
    }

    ~PrivateComputer() {
        cout << "PrivateComputer destructor\n";
    }

    void print() {
        Computer::print();
        cout << "розмір монітора: " << monitorSize << " дюймів\n";
    }
};

int main() {

    cout << "Public computer:\n";
    PublicComputer pc("Dell", 1200, 3600, 27);
    pc.print();

    cout << "\nPrivate computer:\n";
    PrivateComputer pc2("HP", 900, 3200, 24);
    pc2.print();

    return 0;
}