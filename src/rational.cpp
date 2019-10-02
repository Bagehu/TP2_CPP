// TP2 - Arthur ROUILLE and Bastien HUBERT

#include <iostream>
#include <array>
#include "rational.h"
using namespace std;

Rational::Rational() : _num{0}, _den{0}
{
  cout << "+++Rational()" << " [" << this << "]" << endl;
}

Rational::Rational(long p, long q) {
  long g = euclide(p,q);
  long sign = (q>=0) ? 1 : -1;
  
  _num = (sign * p) / g;
  _den = abs(q) / g;

  cout << "+++Rational(p,q)" << " [" << this << "]" << endl;
}

Rational::Rational(const Rational & r) : Rational(r._num,r._den)
{
  cout << "rrrRational(p,q)" << " [" << this << "]" << endl;
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

ostream & operator<<(ostream & out, Rational r) {
  r.displayFraction(out);
  return out;
}

Rational Rational::operator-() {
  Rational r(- _num, _den);
  return r;
}

int test() {
  Rational r1;
  cout << "Numerator:" << r1.getNum();
  cout << " denominator:" << r1.getDen();
  cout << " sign:" << r1.getSign();
  cout << endl;

  Rational r2(1,2);
  cout << "Numerator:" << r2.getNum();
  cout << " denominator:" << r2.getDen();
  cout << " sign:" << r2.getSign();
  cout << endl;

  Rational r3(-1,4);
  cout << "Numerator:" << r3.getNum();
  cout << " denominator:" << r3.getDen();
  cout << " sign:" << r3.getSign();
  cout << endl;

  cout << "The fractionnal form of r3 is ";
  r3.displayFraction(cout);
  cout << endl;
    
  cout << "The fractionnal form of r3^-1 is ";
  inverse(r3).displayFraction(cout);
  cout << endl;
    
  Rational r4(1,2);
  r4.pow(3);
  cout << "(1/2)^3=";
  r4.displayFraction(cout);
  cout << endl;
    
  r2.displayFraction(cout);
  cout << " + ";
  r3.displayFraction(cout);
  cout << " = ";
  (r2+r3).displayFraction(cout);
  cout << endl;

  r2.displayFraction(cout);
  cout << " - ";
  r3.displayFraction(cout);
  cout << " = ";
  (r2-r3).displayFraction(cout);
  cout << endl;

  r2.displayFraction(cout);
  cout << " * ";
  r3.displayFraction(cout);
  cout << " = ";
  (r2*r3).displayFraction(cout);
  cout << endl;

    
  r2.displayFraction(cout);
  cout << " / ";
  r3.displayFraction(cout);
  cout << " = ";
  (r2/r3).displayFraction(cout);
  cout << endl;

  cout << "-";
  r3.displayFraction(cout);
  cout << " = ";
  (-r3).displayFraction(cout);
  cout << endl;

  Rational r5(2,9);
  cout << "Nouveau rationel woaw :";
  cout << r5 << endl;

  return EXIT_SUCCESS;
}

int main() {
  test();
  return EXIT_SUCCESS; 
}
