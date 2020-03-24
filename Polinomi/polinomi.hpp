#ifndef __POLINOMI_HPP__
#define __POLINOMI_HPP__ 1

#include <iostream>
#include <vector>

using namespace std;

class Polinom {
public:
    Polinom()   {   }
    Polinom(const vector<double> koef) : _koef(koef) { }
    void ispisi(ostream& izlaz) const;
    void dodaj_element(double x);
    Polinom operator+(const Polinom& p) const;
    Polinom operator-(const Polinom& p) const;
    Polinom operator*(const Polinom& p) const;
    Polinom minus() const;
    bool operator==(const Polinom& p) const;
    bool operator!=(const Polinom& p) const;
    Polinom izvod() const;
    Polinom integral(double x) const;
    double vrednost(double x) const;
private:
    vector<double> _koef;
};

ostream& operator<<(ostream& izlaz, const Polinom& p);

#endif
