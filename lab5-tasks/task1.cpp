// задача 1.5
#include <iostream>
using namespace std;

class Quadrilateral {
protected:
    double a, b, c, d;

public:
    Quadrilateral(double a, double b, double c, double d) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        cout << "конструктор чотирикутника\n";
    }

    virtual ~Quadrilateral() {
        cout << "деструктор чотирикутника\n";
    }

    virtual double perimeter() {
        return a + b + c + d;
    }

    virtual double area() {
        cout << "Площа для загального чотирикутника не визначена\n";
        return 0;
    }

    virtual void print() {
        cout << "Сторони чотирикутника: "
             << a << " " << b << " " << c << " " << d << endl;
    }
};

class Rectangle : public Quadrilateral {
protected:
    double width, height;

public:
    Rectangle(double w, double h) : Quadrilateral(w, h, w, h) {
        width = w;
        height = h;
        cout << "Конструктор прямокутників\n";
    }

    ~Rectangle() {
        cout << "деструктор прямокутників\n";
    }

    double area() override {
        return width * height;
    }

    double perimeter() override {
        return 2 * (width + height);
    }

    void print() override {
        cout << "прямокутника: width=" << width
             << " height=" << height << endl;
    }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {
        cout << "конструктор квадрата\n";
    }

    ~Square() {
        cout << "деструктор квадрата\n";
    }

    void print() override {
        cout << "сторона квадрата=" << width << endl;
    }
};

int main() {

    cout << "Тест чотирикутника\n";
    Quadrilateral q(3,4,5,6);
    q.print();
    cout << "Периметр: " << q.perimeter() << endl;
    cout << endl;

    cout << "Тест прямокутника\n";
    Rectangle r(5,10);
    r.print();
    cout << "Площа: " << r.area() << endl;
    cout << "Периметр: " << r.perimeter() << endl;
    cout << endl;

    cout << "Тест квадрата\n";
    Square s(7);
    s.print();
    cout << "Плоша: " << s.area() << endl;
    cout << "Периметр: " << s.perimeter() << endl;

    return 0;
}