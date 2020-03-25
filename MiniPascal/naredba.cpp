#include "naredba.hpp"
#include <iostream>

Naredba::~Naredba() {

}

void IspisS::izvrsi() const {
  cout << _s << endl;
}

/* Ispisuje vrednost izraza */
void IspisE::izvrsi() const {
  cout << _i->vrednost() << endl;
}

IspisE::~IspisE() {
  delete _i;
}

void Blok::izvrsi() const {
  for (unsigned i = 0; i < _v.size(); i++)
    _v[i]->izvrsi();
}

Blok::~Blok() {
  for (unsigned i = 0; i < _v.size(); i++)
    delete _v[i];
}

#include <map>
extern map<string, int> tablica;
void Dodela::izvrsi() const {
  int vrednost = _i->vrednost();
  tablica[_s] = vrednost;
}

Dodela::~Dodela() {
  delete _i;
}

void Unos::izvrsi() const {
  int x;
  cin >> x;
  tablica[_s] = x;
}

void AkoJeOndaInace::izvrsi() const {
  
  if (_i->vrednost())
    _n1->izvrsi();
  else
    _n2->izvrsi();
}

AkoJeOndaInace::~AkoJeOndaInace() {
  delete _i;
  delete _n1;
  delete _n2;
}

void AkoJeOnda::izvrsi() const {
  if (_i->vrednost())
    _n1->izvrsi();
}

AkoJeOnda::~AkoJeOnda() {
  delete _i;
  delete _n1;
}

void DokJe::izvrsi() const {
  while (_i->vrednost())
    _n1->izvrsi();
}

DokJe::~DokJe() {
  delete _i;
  delete _n1;
}
