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

long Rational::euclide (long p, long q) {
    if (q==0) {
	return p;
    } else {
	return euclide(q,p%q);
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

void Rational::display(ostream & output) {
    if(_num == 1) {
	
    }
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

    return 0; 
}
