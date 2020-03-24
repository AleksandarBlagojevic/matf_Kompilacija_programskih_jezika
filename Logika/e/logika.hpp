#ifndef __LOGIKA_HPP__
#define __LOGIKA_HPP__ 1

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Logika {
public:
    virtual int vrednost() const = 0;
    virtual ~Logika();
};

class Promenljiva : public Logika {
public:
    Promenljiva(string ime) : _ime(ime) { }
    int vrednost() const;
private:
    string _ime;
};

class Konstanta : public Logika {
public:
    Konstanta(int x) : _vrednost(x) { }
    int vrednost() const;
private:
    int _vrednost;
};

class BinarniOperator : public Logika {
public:
    BinarniOperator(Logika *levi, Logika *desni) : _levi(levi), _desni(desni) { }
    ~BinarniOperator();
protected:
    BinarniOperator(const BinarniOperator& b);
    BinarniOperator& operator=(const BinarniOperator& b);
    Logika *_levi,*_desni;
};

class I : public BinarniOperator {
public:
    I(Logika *l, Logika *d) : BinarniOperator(l,d) { }
    int vrednost() const;
};

class Ili : public BinarniOperator {
public:
    Ili(Logika *l, Logika *d) : BinarniOperator(l,d) { }
    int vrednost() const;
};

class Sledi : public BinarniOperator {
public:
    Sledi(Logika *l, Logika *d) : BinarniOperator(l,d) { }
    int vrednost() const;
};

class Akko : public BinarniOperator {
public:
    Akko(Logika *l, Logika *d) : BinarniOperator(l,d) { }
    int vrednost() const;
};

class Negacija : public Logika {
public:
    Negacija(Logika *l) : _l(l) { }
    ~Negacija();
    int vrednost() const;
private:
    Logika *_l;
};

#endif
