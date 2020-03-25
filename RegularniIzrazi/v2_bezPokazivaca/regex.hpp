#ifndef __REGEX_HPP__
#define __REGEX_HPP__ 1

#include <iostream>
#include <vector>

using namespace std;

class RegEx {
public:
  virtual ~RegEx();
  virtual void basic() const = 0;
  virtual void ispisi() const = 0;
  virtual int maxlen() const = 0;
};

class Slovo : public RegEx {
public:
  Slovo(char c) : _c(c) { }
  void basic() const;
  void ispisi() const;
  int maxlen() const;
private:
  char _c;
};

class Eps : public RegEx {
public:
  Eps() { }
  void basic() const;
  void ispisi() const;
  int maxlen() const;
};

class BinarniOperator : public RegEx {
public:
  BinarniOperator(RegEx *l, RegEx *d) : _levi(l), _desni(d) { }
  ~BinarniOperator();
protected:
  RegEx *_levi,*_desni;
private:
  BinarniOperator(const BinarniOperator&);
  BinarniOperator& operator=(const BinarniOperator&);
};

class UnarniOperator : public RegEx {
public:
  UnarniOperator(RegEx *arg) : _arg(arg) { }
  ~UnarniOperator();
protected:
  RegEx *_arg;
private:
  UnarniOperator(const UnarniOperator&);
  UnarniOperator& operator=(const UnarniOperator&);
};

class Nadovezivanje : public BinarniOperator {
public:
  Nadovezivanje(RegEx *l, RegEx *d) : BinarniOperator(l,d) { }
  void basic() const;
  void ispisi() const;
  int maxlen() const;
};

class Ili : public BinarniOperator {
public:
  Ili(RegEx *l, RegEx *d) : BinarniOperator(l,d) { }
  void basic() const;
  void ispisi() const;
  int maxlen() const;
};

class Zvezdica : public UnarniOperator {
public:
  Zvezdica(RegEx *arg) : UnarniOperator(arg) { }
  void basic() const;
  void ispisi() const;
  int maxlen() const;
};

class Plus : public UnarniOperator {
public:
  Plus(RegEx *arg) : UnarniOperator(arg) { }
  void basic() const;
  void ispisi() const;
  int maxlen() const;
};

class Upitnik : public UnarniOperator {
public:
  Upitnik(RegEx *arg) : UnarniOperator(arg) { }
  void basic() const;
  void ispisi() const;
  int maxlen() const;
};

class KarakterskaKlasa : public RegEx {
public:
  KarakterskaKlasa() { }
  void dodajSlovo(char c);
  void basic() const;
  void ispisi() const;
  int maxlen() const;
private:
  vector<char> _v;
};

class TacnoN : public RegEx {
public:
  TacnoN(RegEx *arg, unsigned n) : _arg(arg), _n(n){ }
  void dodajSlovo(char c);
  void basic() const;
  void ispisi() const;
  int maxlen() const;
private:
  RegEx *_arg;
  unsigned _n;
};



#endif
