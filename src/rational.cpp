// TP2 - Arthur ROUILLE et Bastien HUBERT

#include <iostream>
#include <array>
#include "../include/rational.h"
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

    cout << "+++Rational(" << _num << "," << _den << ")" << " [" << this << "]" << endl;
}

Rational::Rational(const Rational & r) : Rational(r._num,r._den)
{
   cout << "rrrRational(" << _num << "," << _den << ")" << " [" << this << "]" << endl;
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

//Doesn't work
Rational Rational::pow(int n) {
  if (n < 0) {
    return ::inverse(pow(-n));
  }
  if (n == 0) {
    return Rational(1, 1);
  }
  if (n%2==0) {
    cout << "1:"<<_num << "/" <<_den << endl;
    Rational r(_num*_num,_den*_den);
    //this=r;
    return Rational(_num*_num,_den*_den);
  }
  else {
    cout << "2:" <<_num << "/" <<_den << endl;
    pow(n-1);
    return Rational(_num,_den).pow(n-1);
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
bool Rational::operator>(Rational other) {
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


ostream & operator<<(ostream & out, Rational r) {
  r.displayFraction(out);
  return out;
}

//Woaw non
Rational Rational::operator-() {
  Rational r;
  r._num = - _num;
  r._den = - _den;
  return r;
}

Rational sqr(Rational &r) {
  return r*r;
}

Rational & max(Rational &a, Rational &b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int main() {    
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

    cout << "FONCTION MAX" << endl;
    cout << *max(new Rational(1,2), new Rational(1,100)) << endl;
    
    return 0; 
}
