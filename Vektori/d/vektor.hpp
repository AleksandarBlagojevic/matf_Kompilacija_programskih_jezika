#ifndef __VEKTOR_HPP__
#define __VEKTOR_HPP__ 1

#include <iostream>

using namespace std;

// Klasa koja predstavlja vektor
class Vektor {
public:
    // Konstruktori
    Vektor() { }
    Vektor(double x, double y) : _x(x), _y(y) { }
    ~Vektor() { }
    // Metod za ispis vektora
    void ispisi(ostream& izlaz) const;
    // Metod za postavljanje vrednosti vektora
    void postavi(double x, double y);
    // Operatori na vektorima
    Vektor operator+(const Vektor& v) const;
    Vektor operator-(const Vektor& v) const;
    Vektor operator*(const double& v) const;
    // Geteri za koordinate vektora
    double getX() const;
    double getY() const;
private:
    double _x,_y;
};

// Ispis vektora
ostream& operator<<(ostream& izlaz, const Vektor& v);

#endif
