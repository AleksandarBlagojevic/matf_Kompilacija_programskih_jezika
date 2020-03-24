#ifndef __TRANSFORMACIJA_HPP__
#define __TRANSFORMACIJA_HPP__ 1

#include "vektor.hpp"

class Transformacija {
public:
    virtual Vektor prebaci(const Vektor& v) const = 0;
    virtual Transformacija *kopija() const = 0;
    virtual ~Transformacija() { }
};

class Rotacija : public Transformacija {
public:
    Rotacija(double ugao) : _ugao(ugao) { }
    Vektor prebaci(const Vektor& v) const;
    Rotacija *kopija() const;
private:
    double _ugao;
};

class Homotetija : public Transformacija {
public:
    Homotetija(double koef) : _koef(koef) { }
    Vektor prebaci(const Vektor& v) const;
    Homotetija *kopija() const;
private:
    double _koef;
};

class Translacija : public Transformacija {
public:
    Translacija(Vektor v) : _v(v) { }
    Vektor prebaci(const Vektor& v) const;
    Translacija *kopija() const;
private:
    Vektor _v;
};

class Kompozicija : public Transformacija {
public:
    Kompozicija(Transformacija *prva, Transformacija *druga) : _prva(prva) , _druga(druga) { }
    Vektor prebaci(const Vektor& v) const;
    Kompozicija *kopija() const;
    Kompozicija(const Kompozicija& k);
    Kompozicija& operator=(const Kompozicija& k);
    ~Kompozicija();
private:
    Transformacija *_prva, *_druga;
};

#endif
