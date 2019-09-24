// TP2 - Arthur ROUILLE et Bastien HUBERT

#include <iostream>
#include <array>
#include "../include/rational.h"
using namespace std;

class Rational {

public:
  Rational() {
    _num = _den = 0;
  }

  Rational(long p, long q) {
    long g = euclide(p,q);
    long sign = (q>0) ? 1 : -1;
    _num = sign * p / g;
    _den = abs(q)/g;
    
  }

  long euclide (long p, long q) {
    if (q==0) {
      return p;
    } else {
      return euclide(q,p%q);
    }
  }
  inline long getNum() const;
  inline long getDen() const;
  inline long getSign() const;  
private:
  long _num;
  long _den;
};

long Rational::getNum() const {
  return _num;
}

long Rational::getDen() const {
  return _den;
}

long Rational::getSign() const {
  return (_den>=0) ? 1 : -1;
}
 
int main() {
  Rational r1;
  cout << "Numérateur:" << r1.getNum();
  cout << " dénominateur:" << r1.getDen();
  cout << " signe:" << r1.getSign();
  cout << endl;

  Rational r2(5,3);
  cout << "Numérateur:" << r1.getNum();
  cout << " dénominateur:" << r1.getDen();
  cout << " signe:" << r1.getSign();
  cout << endl;

  Rational r3(-7,6);
  cout << "Numérateur:" << r3.getNum();
  cout << " dénominateur:" << r3.getDen();
  cout << " signe:" << r3.getSign();
  cout << endl;

  return 0; 
}
