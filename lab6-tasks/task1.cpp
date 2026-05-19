#include <iostream>
using namespace std;

// БЕЗ VIRTUAL

class Bottom_NV {
public:
    int b;
};
class Mid_NV : public Bottom_NV {
public:
    int m;
};
class Left_NV : public Mid_NV {   
public:
    int l;
};
class Right_NV : public Mid_NV {  
public:
    int r;
};
class Top_NV : public Left_NV, public Right_NV {
public:
    int t;
};

//З VIRTUAL

class Bottom_V {
public:
    int b;
};
class Mid_V : virtual public Bottom_V {
public:
    int m;
};
class Left_V : virtual public Mid_V, virtual public Bottom_V {
public:
    int l;
};
class Right_V : virtual public Mid_V, virtual public Bottom_V {
public:
    int r;
};
class Top_V : public Left_V, public Right_V {
public:
    int t;
};

int main() {
    cout << "БЕЗ virtual\n";
    cout << "Bottom_NV: " << sizeof(Bottom_NV) << endl;
    cout << "Mid_NV:    " << sizeof(Mid_NV) << endl;
    cout << "Left_NV:   " << sizeof(Left_NV) << endl;
    cout << "Right_NV:  " << sizeof(Right_NV) << endl;
    cout << "Top_NV:    " << sizeof(Top_NV) << endl;

    Top_NV nv;
    nv.Left_NV::b  = 10; 
    nv.Right_NV::b = 30;  

    cout << "\nЗ virtual\n";
    cout << "Bottom_V: " << sizeof(Bottom_V) << endl;
    cout << "Mid_V:    " << sizeof(Mid_V) << endl;
    cout << "Left_V:   " << sizeof(Left_V) << endl;
    cout << "Right_V:  " << sizeof(Right_V) << endl;
    cout << "Top_V:    " << sizeof(Top_V) << endl;

    Top_V v;
    v.b = 100; 

    return 0;
}