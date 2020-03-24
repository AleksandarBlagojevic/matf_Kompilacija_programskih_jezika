#include "transformacija.hpp"
#include <cmath>

Vektor Rotacija::prebaci(const Vektor& v) const {
    double fi = _ugao + atan(v.getY()/v.getX());
    double r = sqrt( v.getX()*v.getX() + v.getY()*v.getY());
    return Vektor(cos(fi)*r,sin(fi)*r);
}

Rotacija* Rotacija::kopija() const {
    return new Rotacija(*this);
}

Vektor Homotetija::prebaci(const Vektor& v) const {
    return Vektor(v.getX()*_koef,v.getY()*_koef);
}

Homotetija* Homotetija::kopija() const {
    return new Homotetija(*this);
}


Vektor Translacija::prebaci(const Vektor& v) const {
    return v;
}

Translacija* Translacija::kopija() const {
    return new Translacija(*this);
}

Vektor Kompozicija::prebaci(const Vektor& v) const {
    return _druga->prebaci(_prva->prebaci(v));
}

Kompozicija* Kompozicija::kopija() const {
    return new Kompozicija(_prva->kopija(), _druga->kopija());
}

Kompozicija::~Kompozicija() {
    delete _prva;
    delete _druga;
}

Kompozicija::Kompozicija(const Kompozicija& k) {
    _prva = k._prva->kopija();
    _druga = k._druga->kopija();
}

Kompozicija& Kompozicija::operator=(const Kompozicija& k){
    if ( this == &k)
        return *this;
    delete _prva;
    delete _druga;
    _prva = k._prva->kopija();
    _druga = k._druga->kopija();
    return *this;
}
