#ifndef __NAREDBA_HPP__
#define __NAREDBA_HPP__ 1
#include "izraz.hpp"
#include <string>
#include <vector>
using namespace std;

class Naredba {
public:
  virtual ~Naredba();
  virtual void izvrsi() const = 0;
};

class IspisS : public Naredba {
public:
  IspisS(string s)
    :_s(s)
  {}
  void izvrsi() const;
private:
  string _s;
};

class IspisE : public Naredba {
public:
  IspisE(Izraz *i)
    :_i(i)
  {}
  void izvrsi() const;
  ~IspisE();
private:
  IspisE(const IspisE&);
  IspisE& operator=(const IspisE&);
  Izraz *_i;
};

class Blok : public Naredba {
public:
  Blok(vector<Naredba*> v)
    :_v(v)
  {}
  void izvrsi() const;
  ~Blok();
private:
  Blok(const Blok&);
  Blok& operator=(const Blok&);
  vector<Naredba*> _v;
};

class Dodela : public Naredba {
public:
  Dodela(string s, Izraz *i)
    :_s(s), _i(i)
  {}
  void izvrsi() const;
  ~Dodela();
private:
  Dodela(const Dodela&);
  Dodela& operator=(const Dodela&);
  string _s;
  Izraz *_i;
};

class Unos : public Naredba {
public:
  Unos(string s)
    :_s(s)
  {}
  void izvrsi() const;
private:
  string _s;
};

class AkoJeOndaInace : public Naredba {
public:
  AkoJeOndaInace(Izraz *i, Naredba *n1, Naredba *n2)
    :_i(i), _n1(n1), _n2(n2)
  {}
  void izvrsi() const;
  ~AkoJeOndaInace();
private:
  AkoJeOndaInace(const AkoJeOndaInace&);
  AkoJeOndaInace& operator=(const AkoJeOndaInace&);
  Izraz *_i;
  Naredba *_n1;
  Naredba *_n2;
};

class AkoJeOnda : public Naredba {
public:
  AkoJeOnda(Izraz *i, Naredba *n1)
    :_i(i), _n1(n1)
  {}
  void izvrsi() const;
  ~AkoJeOnda();
private:
  AkoJeOnda(const AkoJeOnda&);
  AkoJeOnda& operator=(const AkoJeOnda&);
  Izraz *_i;
  Naredba *_n1;
};

class DokJe : public Naredba {
public:
  DokJe(Izraz *i, Naredba *n1)
    :_i(i), _n1(n1)
  {}
  void izvrsi() const;
  ~DokJe();
private:
  DokJe(const DokJe&);
  DokJe& operator=(const DokJe&);
  Izraz *_i;
  Naredba *_n1;
};



#endif
