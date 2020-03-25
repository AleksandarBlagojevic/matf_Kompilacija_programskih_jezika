#ifndef __IZRAZ_HPP__
#define __IZRAZ_HPP__ 1

#include <string>
using namespace std;

class Izraz {
public:
  virtual int vrednost() const = 0;
  virtual Izraz* kopija() const = 0;
  virtual ~Izraz();
};

class Konstanta : public Izraz {
public:
  Konstanta(int i)
    :_vrednost(i)
  {}
  int vrednost() const;
  Izraz* kopija() const;
private:
  int _vrednost;
};

class Promenljiva : public Izraz {
public:
  Promenljiva(string s)
    :_ime(s)
  {}
  int vrednost() const;
  Izraz* kopija() const;
private:
  string _ime;
};


class BinOp : public Izraz {
public:
  BinOp(Izraz *i1, Izraz *i2)
    :_levi(i1->kopija()), _desni(i2->kopija())
  {}
  ~BinOp();
  BinOp(const BinOp& z);
  BinOp& operator=(const BinOp& z);
protected:
  Izraz *_levi;
  Izraz *_desni;
};

class Zbir : public BinOp {
public:
  Zbir(Izraz *i1, Izraz *i2)
    :BinOp(i1, i2)
  {}
  int vrednost() const;
  Izraz* kopija() const;
};

class Razlika : public BinOp {
public:
  Razlika(Izraz *i1, Izraz *i2)
    :BinOp(i1, i2)
  {}
  int vrednost() const;
  Izraz* kopija() const;
};

class Proizvod : public BinOp {
public:
  Proizvod(Izraz *i1, Izraz *i2)
    :BinOp(i1, i2)
  {}
  int vrednost() const;
  Izraz* kopija() const;
};

class Kolicnik : public BinOp {
public:
  Kolicnik(Izraz *i1, Izraz *i2)
    :BinOp(i1, i2)
  {}
  int vrednost() const;
  Izraz* kopija() const;
};

class Mod : public BinOp {
public:
  Mod(Izraz *i1, Izraz *i2)
    :BinOp(i1, i2)
  {}
  int vrednost() const;
  Izraz* kopija() const;
};


class Manje : public BinOp {
public:
  Manje(Izraz *i1, Izraz *i2)
    :BinOp(i1, i2)
  {}
  int vrednost() const;
  Izraz* kopija() const;
};

class Vece : public BinOp {
public:
  Vece(Izraz *i1, Izraz *i2)
    :BinOp(i1, i2)
  {}
  int vrednost() const;
  Izraz* kopija() const;
};




#endif
