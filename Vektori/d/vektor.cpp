#include "vektor.hpp"

void Vektor::ispisi(ostream& izlaz) const {
    izlaz << "[" << _x << ", " << _y << "]";
}

void Vektor::postavi(double x, double y) {
    _x = x;
    _y = y;
}

Vektor Vektor::operator+(const Vektor& v) const {
    return Vektor(v._x + _x, v._y + _y);
}

Vektor Vektor::operator-(const Vektor& v) const {
    return Vektor( _x - v._x, _y - v._y);
}

Vektor Vektor::operator*(const double& k) const {
    return Vektor(_x * k , _y * k);
}

double Vektor::getX() const {
    return _x;
}

double Vektor::getY() const {
    return _y;
}

ostream& operator<<(ostream& izlaz, const Vektor& v) {
    v.ispisi(izlaz);
    return izlaz;
}
