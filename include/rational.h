// TP2 - Arthur ROUILLÉ and Bastien HUBERT

#ifndef __RATIONAL_H__
#define __RATIONAL_H__

#include <iostream>

class Rational {

public:
    Rational();
    Rational(long p, long q);
    Rational(const Rational & r);
    long euclide (long p, long q);
    inline long getNum() const;
    inline long getDen() const;
    inline long getSign() const;
    void displayFraction(std::ostream & output);
    Rational pow(int n);
    Rational inverse(Rational r);

private:
  long _num;
  long _den;
};

Rational sum(Rational r1, Rational r2);
Rational difference(Rational r1, Rational r2);
Rational product(Rational r1, Rational r2);
Rational quotient(Rational r1, Rational r2);
#endif
  
