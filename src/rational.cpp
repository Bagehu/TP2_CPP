// TP2 - Arthur ROUILLE et Bastien HUBERT

#include <iostream>
#include <array>
#include "../include/rational.h"
using namespace std;

class Rational {

public:
  Rational() {
    _num = _dem = 0;
  }

  Rational(long p, long q) {
    long g = euclide(p,q);
    long sign = (q>0) ? 1 : -1;
    _num = sign * p / q;
    _dem = abs(q)/g;
    
  }

  long euclide (long p, long q) {
    if (q==0) {
      return p;
    } else {
      return euclide(q,p%q);
    }
  }
  
  inline long getNum() const;
  
private:
  long _num;
  long _dem;
};

long Rational::getNum() const {
  return _num;
}
 
int main() {
  Rational r1;
  cout << r1.getNum() << endl;

  Rational r2(5,3);
  cout << r2.getNum() << endl;

  return 0; 
}
