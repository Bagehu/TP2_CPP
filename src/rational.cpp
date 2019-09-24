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
    long g=-1;
    if (q > 0) {
      while(g != 0) {
	g = p%q;
	p = q;
	b = g;
      }
      long sign = (q > 0)? 1 : -1;
      r = sign * ((p/g) / (abs(q)/g));
    }
  }

}
