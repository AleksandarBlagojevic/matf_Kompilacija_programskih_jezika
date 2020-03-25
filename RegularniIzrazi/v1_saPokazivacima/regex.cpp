#include "regex.hpp"

RegEx::~RegEx() { }

void Slovo::ispisi() const {
  cout << _c;
}

RegEx* Slovo::basic() const {
  return new Slovo(_c);
}

int Slovo::maxlen() const {
  return 1;
}

void Eps::ispisi() const {
  cout << "EPS";
}

RegEx* Eps::basic() const {
  return new Eps();
}

int Eps::maxlen() const {
  return 0;
}

BinarniOperator::~BinarniOperator() {
  delete _levi;
  delete _desni;
}

void Nadovezivanje::ispisi() const {
  cout << "(";
  _levi->ispisi();
  cout << ")(";
  _desni->ispisi();
  cout << ")";
}

RegEx* Nadovezivanje::basic() const {
  return new Nadovezivanje(_levi->basic(),_desni->basic());
}

int Nadovezivanje::maxlen() const {
  int l = _levi->maxlen();
  int d = _desni->maxlen();
  if(l*d>=0)
    return l+d;
  return -1;
}

void Ili::ispisi() const {
  cout << "(";
  _levi->ispisi();
  cout << ")|(";
  _desni->ispisi();
  cout << ")";
}

RegEx* Ili::basic() const {
  return new Ili(_levi->basic(),_desni->basic());
}

int Ili::maxlen() const {
  int l = _levi->maxlen();
  int d = _desni->maxlen();
  if(l*d>=0)
    return (l>=d) ? l : d;
  return -1;
}

UnarniOperator::~UnarniOperator(){
  delete _arg;
}

void Zvezdica::ispisi() const {
  cout << "(";
  _arg->ispisi();;
  cout << ")*";
}

RegEx* Zvezdica::basic() const {
  return new Zvezdica(_arg->basic());
}

int Zvezdica::maxlen() const {
  return -1;
}

void Plus::ispisi() const {
  cout << "(";
  _arg->ispisi();;
  cout << ")+";
}

RegEx* Plus::basic() const {
  return new Nadovezivanje(_arg,new Zvezdica(_arg));
}

int Plus::maxlen() const {
  return -1;
}

void Upitnik::ispisi() const {
  cout << "(";
  _arg->ispisi();;
  cout << ")?";
}

RegEx* Upitnik::basic() const {
  return new Ili(_arg->basic(),new Eps());
}

int Upitnik::maxlen() const {
  return _arg->maxlen();
}


void KarakterskaKlasa::dodajSlovo(char c){
  _v.push_back(c);
}

RegEx* KarakterskaKlasa::basic() const {
  if(_v.size()==1)
    return new Slovo(_v[0]);
  Ili *rez = new Ili(new Slovo(_v[0]),new Slovo(_v[1]));
  for(unsigned i=2; i<_v.size();i++)
    rez = new Ili(rez,new Slovo(_v[i]));
  return rez;  
}
  
void KarakterskaKlasa::ispisi() const {
  cout << "[";
  for(unsigned i=0; i<_v.size(); i++)
    cout << _v[i];
  cout << "]";
}
  
int KarakterskaKlasa::maxlen() const{
  return 1;
}

RegEx* TacnoN::basic() const {
  if(_n==1)
    return _arg;
  Nadovezivanje *rez = new Nadovezivanje(_arg->basic(),_arg->basic());
  for(unsigned i=3; i<=_n;i++)
    rez = new Nadovezivanje(rez,_arg->basic());
  return rez;  
}
  
void TacnoN::ispisi() const {
  cout << "(";
  _arg->ispisi();;
  cout << "){" << _n << "}";
}
  
int TacnoN::maxlen() const{
  return _n;
}
