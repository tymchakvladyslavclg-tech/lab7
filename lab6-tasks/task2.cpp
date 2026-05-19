#include <iostream>
#include <cmath>
using namespace std;

class Equation {
public:
    virtual void solve() = 0;
    virtual ~Equation() {}
};

// ax + b = 0
class LinearEquation : public Equation {
private:
    double a, b;

public:
    LinearEquation(double a, double b) : a(a), b(b) {}

    void solve() override {
        cout << "\nЛінійне рівняння: " << a << "x + " << b << " = 0\n";

        if (a == 0) {
            if (b == 0)
                cout << "Безліч розв'язків\n";
            else
                cout << "Немає розв'язків\n";
        } else {
            double x = -b / a;
            cout << "x = " << x << endl;
        }
    }
};

//ax^2 + bx + c = 0
class QuadraticEquation : public Equation {
private:
    double a, b, c;

public:
    QuadraticEquation(double a, double b, double c)
        : a(a), b(b), c(c) {}

    void solve() override {
        cout << "\nКвадратне рівняння: "
             << a << "x^2 + " << b << "x + " << c << " = 0\n";

        double D = b*b - 4*a*c;

        if (D > 0) {
            double x1 = (-b + sqrt(D)) / (2*a);
            double x2 = (-b - sqrt(D)) / (2*a);
            cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
        } else if (D == 0) {
            double x = -b / (2*a);
            cout << "x = " << x << endl;
        } else {
            cout << "Немає дійсних коренів\n";
        }
    }
};

// ax^4 + bx^2 + c = 0
class BiQuadraticEquation : public Equation {
private:
    double a, b, c;

public:
    BiQuadraticEquation(double a, double b, double c)
        : a(a), b(b), c(c) {}

    void solve() override {
        cout << "\nБіквадратне рівняння: "
             << a << "x^4 + " << b << "x^2 + " << c << " = 0\n";

        //t = x^2
        double D = b*b - 4*a*c;

        if (D < 0) {
            cout << "Немає дійсних коренів\n";
            return;
        }

        double t1 = (-b + sqrt(D)) / (2*a);
        double t2 = (-b - sqrt(D)) / (2*a);

        if (t1 >= 0) {
            cout << "x1 = " << sqrt(t1)
                 << ", x2 = " << -sqrt(t1) << endl;
        }

        if (t2 >= 0) {
            cout << "x3 = " << sqrt(t2)
                 << ", x4 = " << -sqrt(t2) << endl;
        }

        if (t1 < 0 && t2 < 0) {
            cout << "Немає дійсних коренів\n";
        }
    }
};

int main() {
    Equation* eq1 = new LinearEquation(2, -4);
    Equation* eq2 = new QuadraticEquation(1, -3, 2);
    Equation* eq3 = new BiQuadraticEquation(1, -5, 4);

    eq1->solve();
    eq2->solve();
    eq3->solve();

    delete eq1;
    delete eq2;
    delete eq3;

    return 0;
}