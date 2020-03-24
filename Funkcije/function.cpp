#include "function.hpp"

Funkcija* IdentickaFunkcija::izvod()
{	// x' = 1
  return new KonstantnaFunkcija(1);	
}


Funkcija* KonstantnaFunkcija::izvod()
{	// c' = 0
  return new KonstantnaFunkcija(0);	
}

Funkcija* Plus::izvod()
{	// (f+g)' = f' + g'
  return new Plus(_op1->izvod(), _op2->izvod());
}

Funkcija* Puta::izvod()
{	// (f*g)' = f'*g + f*g'
  return new Plus(
                  new Puta(_op1->izvod(), _op2->klon()),
                  new Puta(_op1->klon(), _op2->izvod()));
}


Funkcija* Cos::izvod()
{	// cos(g(x))' = g'(x)*(-1)*sin(g(x))
  return new Puta(_op->izvod(), 
                  new Puta(new KonstantnaFunkcija(-1),
                           new Sin(_op->klon())));	
}

Funkcija* Sin::izvod()
{	// sin(g(x))' = g'(x)*cos(g(x))
  return new Puta(_op->izvod(), 
                  new Cos(_op->klon()));	
}

