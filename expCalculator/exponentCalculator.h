#ifndef EXPONENT_CALCULATOR_H
#define EXPONENT_CALCULATOR_H
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <iostream>
#include "exponentNumbers.h"
namespace EXP
{
    enum Operation {Divi, Multi, Other};
    class ExponentCalculator
    {
    public:
        long double result(ExponentNumbers numbers);
        void setOperation(Operation op);
        Operation getOperation();
    private:
        Operation op = Other;
        long double doOperation(long double resultA, long double resultB);

    };
}

#endif 