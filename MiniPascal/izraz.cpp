#include <iostream>
#include "izraz.hpp"
#include <map>
using namespace std;

extern map<string, int> tablica;

Izraz::~Izraz() {
  
}

int Konstanta::vrednost() const {
  return _vrednost;
}

Izraz* Konstanta::kopija() const {
  return new Konstanta(*this);
}

int Promenljiva::vrednost() const {
  return tablica[_ime];
}

Izraz* Promenljiva::kopija() const {
  return new Promenljiva(*this);
}

BinOp::~BinOp() {
  delete _levi;
  delete _desni;
}

BinOp::BinOp(const BinOp& z) {
  _levi = z._levi->kopija();
  _desni = z._desni->kopija();
}

BinOp& BinOp::operator=(const BinOp& z) {
  if (this != &z) {
    delete _levi;
    delete _desni;
    _levi = z._levi->kopija();
    _desni = z._desni->kopija();
  }
  return *this;
}

int Zbir::vrednost() const {
  return _levi->vrednost() + _desni->vrednost();
}

Izraz* Zbir::kopija() const {
  return new Zbir(*this);
}

int Razlika::vrednost() const {
  return _levi->vrednost() - _desni->vrednost();
}

Izraz* Razlika::kopija() const {
  return new Razlika(*this);
}

int Proizvod::vrednost() const {
  return _levi->vrednost() * _desni->vrednost();
}

Izraz* Proizvod::kopija() const {
  return new Proizvod(*this);
}

int Kolicnik::vrednost() const {
  return _levi->vrednost() / _desni->vrednost();
}

Izraz* Kolicnik::kopija() const {
  return new Kolicnik(*this);
}

int Mod::vrednost() const {
  return _levi->vrednost() % _desni->vrednost();
}

Izraz* Mod::kopija() const {
  return new Mod(*this);
}

int Manje::vrednost() const {
  return _levi->vrednost() < _desni->vrednost();
}

Izraz* Manje::kopija() const {
  return new Manje(*this);
}

int Vece::vrednost() const {
  return _levi->vrednost() > _desni->vrednost();
}

Izraz* Vece::kopija() const {
  return new Vece(*this);
}
