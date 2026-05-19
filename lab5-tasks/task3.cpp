// задача 3.2

#include <iostream>
#include <string>
using namespace std;

class Education {
protected:
    string schoolName;
    int graduationYear;

public:
    Education() : schoolName(""), graduationYear(0) {}

    Education(const string& name, int year) : schoolName(name), graduationYear(year) {}

    // Конструктор копіювання
    Education(const Education& other) {
        schoolName = other.schoolName;
        graduationYear = other.graduationYear;
    }

    // Оператор присвоювання
    Education& operator=(const Education& other) {
        if (this != &other) {
            schoolName = other.schoolName;
            graduationYear = other.graduationYear;
        }
        return *this;
    }

    virtual ~Education() {}

    // Перевизначення потокового виведення
    virtual void print(ostream& out) const {
        out << "Школа: " << schoolName << ", Рік: " << graduationYear;
    }

    // Перевизначення потокового введення
    virtual void read(istream& in) {
        cout << "Введіть назву школи: ";
        in.ignore(); // для уникнення залишку '\n' у буфері
        getline(in, schoolName);
        cout << "Введіть випускний рік: ";
        in >> graduationYear;
    }

    // Оператори потоків
    friend ostream& operator<<(ostream& out, const Education& e) {
        e.print(out);
        return out;
    }

    friend istream& operator>>(istream& in, Education& e) {
        e.read(in);
        return in;
    }
};

// Похідний клас Вища освіта
class HigherEducation : public Education {
private:
    string university;
    string degree;

public:
    HigherEducation() : Education(), university(""), degree("") {}

    HigherEducation(const string& school, int year, const string& uni, const string& deg)
        : Education(school, year), university(uni), degree(deg) {}

    // Конструктор копіювання
    HigherEducation(const HigherEducation& other) : Education(other) {
        university = other.university;
        degree = other.degree;
    }

    // Оператор присвоювання
    HigherEducation& operator=(const HigherEducation& other) {
        if (this != &other) {
            Education::operator=(other);
            university = other.university;
            degree = other.degree;
        }
        return *this;
    }

    // Перевизначення виведення
    void print(ostream& out) const override {
        Education::print(out);
        out << ", Університет: " << university << ", Ступінь: " << degree;
    }

    // Перевизначення введення
    void read(istream& in) override {
        Education::read(in);
        cout << "Введіть назву університету: ";
        in.ignore();
        getline(in, university);
        cout << "Введіть ступінь: ";
        getline(in, degree);
    }
};

int main() {
    cout << "Base class тест:\n";
    Education e1("Школа #1", 2015);
    cout << e1 << endl;

    cout << "\nПохідний class тест:\n";
    HigherEducation he1("Школа #2", 2012, "Чернівецький університет", "Бакалавр");
    cout << he1 << endl;

    cout << "\nВведіть нову інформацію про вищу освіту:\n";
    HigherEducation he2;
    cin >> he2;
    cout << "\nВи ввели:\n" << he2 << endl;

    cout << "\nCopy constructor тест:\n";
    HigherEducation he3 = he2;
    cout << he3 << endl;

    cout << "\nОператор присвоювання тест:\n";
    HigherEducation he4;
    he4 = he1;
    cout << he4 << endl;

    return 0;
}