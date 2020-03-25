#include "regex.hpp"

RegEx::~RegEx() { }

void Slovo::ispisi() const {
  cout << _c;
}

void Slovo::basic() const {
  this->ispisi();
}

int Slovo::maxlen() const {
  return 1;
}

void Eps::ispisi() const {
  this->ispisi();
}

void Eps::basic() const {
  cout<<"EPS";
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

void Nadovezivanje::basic() const {
  cout << "(";
  _levi->basic();
  cout << ")(";
  _desni->basic();
  cout << ")";
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

void Ili::basic() const {
  cout << "(";
  _levi->basic();
  cout << ")|(";
  _desni->basic();
  cout << ")";
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

void Zvezdica::basic() const {
  this->ispisi();
}

int Zvezdica::maxlen() const {
  return -1;
}

void Plus::ispisi() const {
  cout << "(";
  _arg->ispisi();;
  cout << ")+";
}

void Plus::basic() const {
  cout << "(";
  _arg->ispisi();;
  cout << ")";
  cout << "(";
  _arg->ispisi();;
  cout << ")*";
}

int Plus::maxlen() const {
  return -1;
}

void Upitnik::ispisi() const {
  cout << "(";
  _arg->ispisi();;
  cout << ")?";
}

void Upitnik::basic() const {
  cout << "(";
  _arg->basic();;
  cout << ")";
  cout << "|(EPS)";
}

int Upitnik::maxlen() const {
  return _arg->maxlen();
}


void KarakterskaKlasa::dodajSlovo(char c){
  _v.push_back(c);
}

void KarakterskaKlasa::basic() const {
  if(_v.size()==1)
    cout<<_v[0];
  cout << _v[0] << "|" << _v[1];
  for(unsigned i=2; i<_v.size();i++)
    cout << "|" <<_v[i];
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

void TacnoN::basic() const {
  if(_n==0)
      cout << "EPS";
  else if(_n==1)
    _arg->basic();
  else {
    cout<<"(";
    _arg->basic();
    cout<<")";
    cout<<"(";
    _arg->basic();
    cout<<")";
        for(unsigned i=3; i<=_n;i++){
        cout<<"(";
        _arg->basic();
        cout<<")";
        }
    }
}
  
void TacnoN::ispisi() const {
  cout << "(";
  _arg->ispisi();;
  cout << "){" << _n << "}";
}
  
int TacnoN::maxlen() const{
  return _n;
}
/*
int main(){
    char c = 'a';
    cout << c << endl;
    KarakterskaKlasa *k = new KarakterskaKlasa();
    while(c<='e'){
        c+=1;
        
    cout << c << endl;
        k->dodajSlovo(c);
    }
    k->ispisi();
    cout << endl;
    k->basic();
    cout << endl;
    
    TacnoN *t = new TacnoN(k,3);
    t->ispisi();

cout << endl;
cout << endl;
cout << endl;
cout << endl;
t->basic();
cout << endl;
//delete r;
    
    return 0;
    
}
*/
