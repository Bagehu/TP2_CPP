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

private:
  long _num;
  long _den;
};

    Rational inverse(Rational r);


#endif
  
