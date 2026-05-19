#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string name = "", int age = 0)
        : name(name), age(age) {}

    virtual ~Person() {}

    virtual void print() const {
        cout << "Ім'я: " << name << ", Вік: " << age << endl;
    }

    friend istream& operator>>(istream& in, Person& p) {
        cout << "Введіть ім'я: ";
        in >> p.name;
        cout << "Введіть вік: ";
        in >> p.age;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Person& p) {
        out << "Ім'я: " << p.name << ", Вік: " << p.age;
        return out;
    }
};

class Father : virtual public Person {
protected:
    string job;

public:
    Father(string name = "", int age = 0, string job = "")
        : Person(name, age), job(job) {}

    virtual ~Father() {}

    void print() const override {
        Person::print();
        cout << "Професія батька: " << job << endl;
    }

    friend istream& operator>>(istream& in, Father& f) {
        in >> (Person&)f;
        cout << "Введіть професію батька: ";
        in >> f.job;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Father& f) {
        out << (Person&)f;
        out << ", Професія батька: " << f.job;
        return out;
    }
};

class Mother : virtual public Person {
protected:
    string hobby;

public:
    Mother(string name = "", int age = 0, string hobby = "")
        : Person(name, age), hobby(hobby) {}

    virtual ~Mother() {}

    void print() const override {
        Person::print();
        cout << "Хобі матері: " << hobby << endl;
    }

    friend istream& operator>>(istream& in, Mother& m) {
        in >> (Person&)m;
        cout << "Введіть хобі матері: ";
        in >> m.hobby;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Mother& m) {
        out << (Person&)m;
        out << ", Хобі матері: " << m.hobby;
        return out;
    }
};

class Son : public Father, public Mother {
private:
    string school;

public:
    Son(string name = "", int age = 0,
        string job = "", string hobby = "", string school = "")
        : Person(name, age), Father(name, age, job),
          Mother(name, age, hobby), school(school) {}

    ~Son() {}

    void print() const override {
        cout << "\nІнформація про сина: \n";
        Person::print();
        cout << "Професія батька: " << job << endl;
        cout << "Хобі матері: " << hobby << endl;
        cout << "Школа: " << school << endl;
    }

    friend istream& operator>>(istream& in, Son& s) {
        in >> (Person&)s;

        cout << "Введіть професію батька: ";
        in >> s.job;

        cout << "Введіть хобі матері: ";
        in >> s.hobby;

        cout << "Введіть школу: ";
        in >> s.school;

        return in;
    }

    friend ostream& operator<<(ostream& out, const Son& s) {
        out << "Ім'я: " << s.name
            << ", Вік: " << s.age
            << ", Професія батька: " << s.job
            << ", Хобі матері: " << s.hobby
            << ", Школа: " << s.school;
        return out;
    }
};

int main() {
    Son s;

    cin >> s;

    cout << "\nЧерез оператор <<:\n";
    cout << s << endl;

    cout << "\nЧерез метод print():\n";
    s.print();

    return 0;
}