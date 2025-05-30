#include <string>


struct Fraction {
    int numerator;    
    int denominator;  
};

 
Fraction createFraction(int numerator, int denominator);


Fraction addFractions(Fraction a, Fraction b);      
Fraction subtractFractions(Fraction a, Fraction b); 
Fraction multiplyFractions(Fraction a, Fraction b); 
Fraction divideFractions(Fraction a, Fraction b);   

Fraction reduceFraction(Fraction f);               
std::string fractionToString(Fraction f);         

