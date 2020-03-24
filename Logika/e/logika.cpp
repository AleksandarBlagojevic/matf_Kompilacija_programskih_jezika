#include "logika.hpp"

extern map<string, Logika*> tablica;

Logika::~Logika(){

}

int Konstanta::vrednost() const {
    return _vrednost;
}

int Promenljiva::vrednost() const {
    return tablica[_ime]->vrednost();
}

BinarniOperator::~BinarniOperator(){
    delete _levi;
    delete _desni;
}

int I::vrednost() const {
    return (_levi->vrednost()==0) ? 0 : _desni->vrednost();
}

int Ili::vrednost() const {
    return (_levi->vrednost()==1) ? 1 : _desni->vrednost(); 
}

int Sledi::vrednost() const {
    return (_desni->vrednost()==1 || _levi->vrednost()==0) ? 1 : _desni->vrednost();
}

int Akko::vrednost() const {
    return (_levi->vrednost()==-1 || _desni->vrednost()==-1) ? -1 : _levi->vrednost() == _desni->vrednost();
}

Negacija::~Negacija(){
    delete _l;
}

int Negacija::vrednost() const {
    return _l->vrednost() == -1 ? -1 : (_l->vrednost()+1)%2;
}
