// TP2 - Arthur ROUILLE et Bastien HUBERT

#include <iostream>
#include <array>
#include "../include/rational.h"
using namespace std;

Rational::Rational() {
    _num = _den = 0;
}

Rational::Rational(long p, long q) {
    long g = euclide(p,q);
    long sign = (q>0) ? 1 : -1;
    _num = sign * p / g;
    _den = abs(q)/g;
}

Rational::Rational(const Rational & r) {
  _num = r._num;
  _den = r._den;
}

long Rational::euclide (long p, long q) {
    if (q == 0) {
	return p;
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
    return (_den >= 0) ? 1 : -1;
}

void Rational::displayFraction(ostream & output) {
    if(_num == 1) {
	output << _den << endl; 
    }else {
	output << _den << "/" << _num << endl;
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

Rational Rational::pow(int n) {
  if (n < 0) {
    return ::inverse(pow(-n));
  }else if (n == 0) {
    return Rational(1, 1);
  } 
  if (n%2==0) {
    cout << "2" << endl;
    _num*=_num;
    _den*=_den;
    return pow(n-1);
  }
  if (n%2==1) {
    cout << "3" << endl;
    return pow(2*(n-1));
  }
  exit(-1);
}

Rational sum(long p1, long p2, long q1, long q2) {
  long pOut = p1 * q2 + p2 * q1;
  long qOut = q1 * q2;
  cout << "pOut/qOut =" << pOut << "/" << qOut << endl;
  return Rational(pOut, qOut); 
}

Rational difference(long p1, long p2, long q1, long q2) {
  return sum(p1, -p2, q1, q2); 
}

Rational product(long p1, long p2, long q1, long q2) {
  long pOut = p1 * p2;
  long qOut = q1 * q2;
  return Rational(pOut, qOut); 
}

Rational quotient(long p1, long p2, long q1, long q2) {
  return product(p1, q2, q1, p2);
}
 
int main() {    
    Rational r1;
    cout << "Numerator:" << r1.getNum();
    cout << " denominator:" << r1.getDen();
    cout << " sign:" << r1.getSign();
    cout << endl;

    Rational r2(5,3);
    cout << "Numerator:" << r2.getNum();
    cout << " denominator:" << r2.getDen();
    cout << " sign:" << r2.getSign();
    cout << endl;

    Rational r3(-7,6);
    cout << "Numerator:" << r3.getNum();
    cout << " denominator:" << r3.getDen();
    cout << " sign:" << r3.getSign();
    cout << endl;

    cout << "The fractionnal form of r3 is " << endl;
    r3.displayFraction(cout);

    cout << "The fractionnal form of r3^-1 is " << endl;
    inverse(r3).displayFraction(cout);

    Rational r4(r2.pow(2));
    cout << "r2^2=" << r4.getNum() << "/" << r4.getDen() << endl;

    cout << "1/2 + 1/4 =" << endl;
    sum(1, 1, 2, 4).displayFraction(cout);

        cout << "1/4 + 1/2 =" << endl;
    sum(1, 1, 4, 2).displayFraction(cout);

    return 0; 
}
