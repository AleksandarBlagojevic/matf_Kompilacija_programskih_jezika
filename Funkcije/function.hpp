#ifndef __FUNKCIJA_H__
#define __FUNKCIJA_H__

#include <cmath>
#include <iostream>
#include <string>
using namespace std;

//Bazna apstraktna klasa kojom se predstavlja matematicka funkcija
class Funkcija
{
public:
  //Metod dinamicki kreira izvod funkcije
  virtual Funkcija* izvod() = 0;
  
  //Metod izracunava vrednost funkcije u datoj tacki x
  virtual float vrednost(float x) = 0;
  
  //Metod za ispis u dati tok
  virtual void print(ostream& ostr) = 0;
  
  //Destruktor
  virtual ~Funkcija()
  {}
  
  //Metod kreira identicnu kopiju date funkcije
  virtual Funkcija* klon() = 0;
};

// Klasa kojom se predstavlja konstantna funkcija f(x)=c
class KonstantnaFunkcija : public Funkcija
{
public:
  // Konstruktor na osnovu datog broja c
  KonstantnaFunkcija(float c)
    : _c(c)
  {}
  
  virtual Funkcija* izvod();
  
  virtual float vrednost(float x)
  {	return _c;	}
    
  virtual void print(ostream& ostr)
  {
    ostr<<_c;
  }
  virtual Funkcija* klon()
  {
    return new KonstantnaFunkcija(*this);
  }	
  
protected:
  float _c;
};


class IdentickaFunkcija : public Funkcija
{
public:
  virtual Funkcija* izvod();
  
  virtual float vrednost(float x)
  {	return x;	}
  
  virtual void print(ostream& ostr)
  {
    ostr<<"x";
  }
  
  virtual Funkcija* klon()
  {
    return new IdentickaFunkcija(*this);
  }
};

class BinarniOperator : public Funkcija
{
public:
  // Konstruktor 
  BinarniOperator(Funkcija* op1, Funkcija* op2, char simbol)
    :_simbol(simbol)
  {
    _op1 = op1->klon();
    _op2 = op2->klon();
  }
  
  // Konstruktor kopije
  BinarniOperator(const BinarniOperator& b)
    : _op1(b._op1->klon()), _op2(b._op2->klon()), _simbol(b._simbol)
  {}
  
  // Operator Dodele
  BinarniOperator& operator=(const BinarniOperator& b)
  {
    if (this != &b)
      {
        delete _op1; delete _op2;
        _op1 = b._op1->klon(); _op2 = b._op2->klon();
      }
    return *this;
  }
  
  // Destruktor
  virtual ~BinarniOperator()
  {
    delete _op1;
    delete _op2;
  }
  
  virtual void print(ostream& ostr)
  {
    ostr<<'(';_op1->print(ostr);ostr<<')';
    ostr<<_simbol;
    ostr<<'(';_op2->print(ostr);ostr<<')';
  }
  
protected:
  //Argumenti
  Funkcija *_op1, *_op2;
  
  
  //Simbol za ispis
  char _simbol;
};

class Plus : public BinarniOperator
{
public:
  Plus(Funkcija* op1, Funkcija* op2)
    : BinarniOperator(op1, op2, '+')
  {}
  
  virtual Funkcija* izvod();
  
  virtual Funkcija* klon()
  {
    return new Plus(*this);
  }
  
  virtual float vrednost(float x)
  {	return _op1->vrednost(x)+_op2->vrednost(x);	}
};

class Puta : public BinarniOperator
{
public:
  Puta(Funkcija* op1, Funkcija* op2)
    : BinarniOperator(op1, op2, '*')
  {}
  
  virtual Funkcija* klon()
  {	return new Puta(*this); 	}
  
  virtual Funkcija* izvod();
  
  virtual float vrednost(float x)
  {	return _op1->vrednost(x)*_op2->vrednost(x);	}
};

class ElementarnaFunkcija : public Funkcija
{
public:
  // Konstruktor
  ElementarnaFunkcija(Funkcija* op, string name)
    : _name(name)
  {
    _op = op->klon();
  }
  
  // Destruktor
  virtual ~ElementarnaFunkcija()
  {	delete _op;	}
  
  // Konstruktor kopije
  ElementarnaFunkcija(const ElementarnaFunkcija& e)
    : _op(e._op->klon()), _name(e._name)
  {}
  
  // Operator dodele
  ElementarnaFunkcija& operator=(const ElementarnaFunkcija& e)
  {
    if (this != &e)
      {	delete _op;
        _op = e._op->klon();
        _name = e._name;
      }
    return *this;
  }
  
  virtual void print(ostream& ostr)
  {
    ostr<<_name<<'(';
    _op->print(ostr);
    ostr<<')';
  }
  
protected:
  Funkcija* _op;
  string _name;
};

class Sin : public ElementarnaFunkcija
{
public:
  Sin(Funkcija* fun)
    : ElementarnaFunkcija(fun, "sin")
  {}
  
  virtual Funkcija* klon()
  {	return new Sin(*this);	}
  
  virtual float vrednost(float x)
  {	return sin(x);	}
  
  virtual Funkcija* izvod();
  
};


class Cos : public ElementarnaFunkcija
{
public:
  Cos(Funkcija* fun)
    : ElementarnaFunkcija(fun, "cos")
  {}
  
  virtual Funkcija* klon()
  {	return new Cos(*this);	}
  
  virtual float vrednost(float x)
  {	return cos(x);	}
  
  virtual Funkcija* izvod();
  
};

#endif

