#include "polinomi.hpp"

void Polinom::ispisi(ostream& izlaz) const {
    int n = _koef.size();
    for(int i=0; i<n;i++){
        if(i==0){
            if(_koef[i] !=0 || n==0)
                cout << _koef[i];
            continue;
        }
        if(_koef[i] != 0){
            if(_koef[i]>0){
                cout << "+";
        if(_koef[i] != 1)
          cout << _koef[i];
        }
        else{
            if(_koef[i] == -1)
                cout << "-";
            else
                cout << _koef[i];       
        }
        if( i>1)
            cout << "x^" << i;
        else
            cout << "x";
        }
    }
        izlaz << endl;
}

void Polinom::dodaj_element(double x){
    _koef.push_back(x);
}

Polinom Polinom::operator+(const Polinom& p) const{
    int n = _koef.size();
    int m = p._koef.size();
    Polinom rez;
    int manji;
    if(m<=n){
        manji = m;
        rez = Polinom(_koef);
    }
    else {
        manji = n;
        rez = Polinom(p._koef);
    }
     
    for(int i=0; i<manji; i++)
        rez._koef[i]= _koef[i] + p._koef[i];
    return rez;
}

Polinom Polinom::operator-(const Polinom& p) const{
    int n = _koef.size();
    int m = p._koef.size();
    Polinom rez;
    int manji;
    if(m<=n){
        manji = m;
        rez = Polinom(_koef);
    }
    else {
        manji = n;
        rez = Polinom(p._koef);
    }
     
    for(int i=0; i<manji; i++)
        rez._koef[i]= _koef[i] - p._koef[i];
    return rez;
}

Polinom Polinom::operator*(const Polinom& p) const{
    int n = _koef.size();
    int m = p._koef.size();
    Polinom rez = Polinom();
    rez._koef.resize(m+n);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            rez._koef[i+j] += _koef[i] * p._koef[j];
    return rez;
}

Polinom Polinom::minus() const{
    int n = _koef.size();
    Polinom rez = Polinom(*this);
    for(int i=0; i<n; i++)
        rez._koef[i]= -rez._koef[i];
    return rez;
}


bool Polinom::operator==(const Polinom& p) const{
    return _koef == p._koef;
}

bool Polinom::operator!=(const Polinom& p) const{
    return _koef != p._koef;
}

ostream& operator<<(ostream& izlaz, const Polinom& p){
    p.ispisi(izlaz);
    return izlaz;
}


Polinom Polinom::izvod() const{
    int n = _koef.size();
    Polinom rez = Polinom(*this);
    for(int i=1; i<n; i++)
        rez._koef[i-1] = _koef[i] * i;
    rez._koef.resize(n-1);
    return rez;
}


Polinom Polinom::integral(double x) const{
    int n = _koef.size();
    Polinom rez = Polinom(*this);
    rez._koef.resize(n+1);
    rez._koef[0] = x;
    for(int i=0; i<n; i++)
        rez._koef[i+1] = _koef[i] / (i+1);
    return rez;
}

double Polinom::vrednost(double x) const{
    double rez=0;
    for(int i = _koef.size(); i>=0; i--)
        rez = rez * x + _koef[i];
    return rez;
}
