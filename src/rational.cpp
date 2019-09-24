// TP2 - Arthur ROUILLE et Bastien HUBERT
#include <iostream>
#include <array>
#include "../include/rational.h"
using namespace std;

class Rational {

public:
  Rational() {
    r = 0;
  }

  Rational(long p, long q) {
    long pgcd=-1;
    if (q > 0) {
      r = euclide(p,q);
    }
  }
  long euclide(long p, long q) {
    long pgcd = -1;
    long g = 0;
    while(pgcd != 0) {
      pgcd = p%q;
      p = q;
      q = pgcd;
    }
    long sign = (q > 0)? 1 : -1;
    g = sign * ((p/pgcd) / (abs(q)/pgcd));
    return g;
  }
  
  inline void getNum() const;
  
private:
  long r;
};

void Rational::getNum() const {
  return r;
}
 
int main() {
  Rational r1;
  cout << r1.getNum() << endl;

  //Rational r2(5,3);
  return 0; 
}
