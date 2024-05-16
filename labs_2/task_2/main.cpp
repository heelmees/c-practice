#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

class Cube {
    private:
        double edge;
    public:
        Cube(double e) {
            edge = e;
        }
        double Square() const {
            return pow(edge, 2) * 6;
        }
        double Volume() const {
            return pow(edge, 3);
        }
        double Diagonal() const {
            double d1 = edge * sqrt(2);
            double d2 = sqrt(pow(edge, 2) + pow(d1, 2));
            return d2;
        }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    double edge;
    cout << "Введите длину ребра куба:";
    cin >> edge;
    Cube cube(edge);
    cout << "Площадь куба: " << cube.Square() << endl;
    cout << "Объем куба: " << cube.Volume() << endl;
    cout << "Диагональ куба: " << cube.Diagonal() << endl;
}