// TP2 - Arthur ROUILLE and Bastien HUBERT

#include <iostream>
#include <array>
#include "rational.h"
using namespace std;

Rational::Rational() : _num{0}, _den{1}
{
  cout << "\t+++Rational()" << " [" << this << "]" << endl;
}

Rational::Rational(long p, long q) {
  long g = euclide(p,q);
  long sign = (q>=0) ? 1 : -1;
  
  _num = (sign * p) / g;
  _den = abs(q) / g;

  cout << "\t+++Rational(" << _num << "," << _den << ")" << " [" << this << "]" << endl;
}

Rational::Rational(const Rational & r) : Rational(r._num,r._den)
{
   cout << "\trrrRational(" << _num << "," << _den << ")" << " [" << this << "]" << endl;
}

long Rational::euclide(long p, long q) {
  if (q == 0) {
    return abs(p);
  } else {
    return euclide(q, p % q);
  }
}

long Rational::getNum() const {
  return _num;
}

long Rational::getDen() const {
  return _den;
}

long Rational::getSign() const {
  return (_den*_num >= 0) ? 1 : -1;
}

void Rational::displayFraction(ostream & output) {
  if(_den == 1 || _den == -1) {
    output << _num*_den; 
  } else {
    output << "(" << _num << "/" << _den << ")";
  }
}

Rational inverse(Rational r) {
  long num = r.getNum();
  long den = r.getDen();
  long tmp = num;
  num=-den;
  den=-tmp;
  Rational inv(num,den);
  return inv;
}

Rational Rational::pow(unsigned int n) {
  if (n == 1) {
    return *this;
  }
  if (n%2 == 0) {
    return *this = (Rational(_num*_num, _den*_den).pow(n/2));
  }
  else {
    return *this = Rational(_num, _den)*(Rational(_num*_num, _den*_den).pow((n-1)/2));
  } 
}

/* The wrong "sum" method, using private attributes of the "Rational" class */
/*
Rational sum(Rational r1, Rational r2) {
  long p = r1._num * r2._den + r2._num * r1._den;
  long q = r1._den * r2._den;
  return Rational(p,q); 
}
*/

Rational sum(Rational r1, Rational r2) {
  long p = r1.getNum() * r2.getDen() + r2.getNum() * r1.getDen();
  long q = r1.getDen() * r2.getDen();
  return Rational(p,q); 
}

Rational difference(Rational r1, Rational r2) {
  long p = r1.getNum() * r2.getDen() - r2.getNum() * r1.getDen();
  long q = r1.getDen() * r2.getDen();
  return Rational(p,q); 
}

Rational product(Rational r1, Rational r2) {
  long p = r1.getNum() * r2.getNum();
  long q = r1.getDen() * r2.getDen();
  return Rational(p, q); 
}

Rational quotient(Rational r1, Rational r2) {
  return product(r1,inverse(r2));
}

Rational Rational::operator*(Rational other) {
  return Rational(_num * other._num,
		  _den * other._den);
}

Rational Rational::operator/(Rational other) {
  return Rational(_num * other._den,
		  _den * other._num);
}

Rational Rational::operator+(Rational other) {
  return Rational (_num * other._den + other._num * _den,
		   _den * other._den);
}
Rational Rational::operator-(Rational other) {
  return Rational (_num * other._den - other._num * _den,
		   _den * other._den);
}
bool Rational::operator>(const Rational &other) const {
  if (_num * other._den > other._num * _den) {
    return true;
  } else {
    return false;
  }
}

Rational Rational::operator=(const Rational & other) {
  if (this == &other) {
    return *this;
  }
  if (other._num && other._den) {
    _num = other._num;
    _den = other._den;
  }
  return *this;
}

Rational Rational::operator-() {
  Rational r(- _num, _den);
  return r;
}

ostream & operator<<(ostream & out, Rational r) {
  r.displayFraction(out);
  return out;
}

Rational sqr(Rational &r) {
  return r*r;
}

const Rational max(const Rational a, const Rational b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}
    
int test() {
  cout << "CONSTRUCTORS AND GETTERS" << endl;
  Rational r1;
  //cout << r1 << ": ";
  cout << "Numerator:" << r1.getNum();
  cout << " denominator:" << r1.getDen();
  cout << " sign:" << r1.getSign();
  cout << "\n" << endl;

  Rational r2(1,2);
  cout << r2 << ": ";
  cout << "Numerator:" << r2.getNum();
  cout << " denominator:" << r2.getDen();
  cout << " sign:" << r2.getSign();
  cout << "\n" << endl;

  Rational r3(-1,4);
  cout << r3 << ": ";
  cout << "Numerator:" << r3.getNum();
  cout << " denominator:" << r3.getDen();
  cout << " sign:" << r3.getSign();
  cout << "\n" << endl;
  
  cout << "POW TESTING" << endl;
  Rational r4(1,2);
  Rational r4init(r4);
  cout << r4init << "^3=" << r4.pow(3) << endl;
  cout << "\n" << endl;
  
  cout << "OPERATORS OVERLOADING" << endl;
  cout << r2 << " + " << r3 << " = " << (r2+r3) << endl;
  cout << r2 << " - " << r3 << " = " << (r2-r3) << endl;
  cout << r2 << " * " << r3 << " = " << (r2*r3) << endl;
  cout << r2 << " / " << r3 << " = " << (r2/r3) << endl;
  cout << "-" << r3 << " = " << (-r3) << endl;
  cout << "\n" << endl;

  cout << "MAX FUNCTION" << endl;
  cout << max(Rational(1,2), Rational(1,100)) << endl;
  Rational a(1,2);
  Rational b(1,4);
  a=max((a + b), (a * b));
  cout << a << endl;

  Rational c(0,1);
  c=max(a,b);
  cout << c << endl;
  
  return EXIT_SUCCESS;
}

int main() {
  test();
  return EXIT_SUCCESS; 
}
