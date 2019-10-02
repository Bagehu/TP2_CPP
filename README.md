## C++ Lab 2
### Arthur ROUILLE & Bastien HUBERT

When we use private attributes in the "sum" function, the compiler actually throws us this error message (times the number of occurences of our violation). Thus, we have to use getter methods to access our attributes.  

$src/rational.cpp:79:15: error: ‘long int Rational::_num’ is private within this context
$   long p = r1._num * r2._den + r2._num * r1._den;
$               ^~~~
$In file included from src/rational.cpp:5:0:
$./include/rational.h:35:8: note: declared private here
$   long _num;

