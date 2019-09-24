// TP2 - Arthur ROUILLÉ and Bastien HUBERT

#ifndef __RATIONAL_H__
#define __RATIONAL_H__

class Rational {

public:
    Rational();
    Rational(long p, long q);
    
    long euclide (long p, long q);
    inline long getNum() const;
    inline long getDen() const;
    inline long getSign() const;
    //    void display(ostream & output);
    Rational pow(int n);
    Rational inverse(Rational r);
private:
  long _num;
  long _den;
};


#endif
  
