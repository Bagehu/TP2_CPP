// TP2 - Arthur ROUILLÉ and Bastien HUBERT

#ifndef __RATIONAL_H__
#define __RATIONAL_H__

#include <iostream>
using namespace std;

class Rational {

public:
    Rational();
    Rational(long p, long q);
    Rational(const Rational & r);
    long euclide (long p, long q);
    inline long getNum() const;
    inline long getDen() const;
    inline long getSign() const;
    void displayFraction(ostream & output);

    Rational pow(unsigned int n);
    Rational inverse(Rational r);

    Rational operator*(Rational other);
    Rational operator/(Rational other);
    Rational operator+(Rational other);
    Rational operator-(Rational other);
    bool operator>(const Rational &other) const;
    Rational operator-();
    Rational operator=(const Rational & other);
    friend ostream & operator << (ostream & out, Rational r);
    ~Rational() {
      cout << "---Rational(" << _num << "," << _den << ")"  << " [" << this << "]" << endl;
    }
    
 private:
  long _num;
  long _den;
};

Rational sum(Rational r1, Rational r2);
Rational difference(Rational r1, Rational r2);
Rational product(Rational r1, Rational r2);
Rational quotient(Rational r1, Rational r2);
Rational sqr(Rational &r);
const Rational max(const Rational a, const Rational b);

int test();
int main();

#endif
