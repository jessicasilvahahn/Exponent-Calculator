#include "exponentCalculator.h"
   
long double  EXP::ExponentCalculator::doOperation(long double resultA, long double resultB)
{
    long double resultOperation;
    if(this->op == EXP::Operation::Multi)
    {
        resultOperation = resultA*resultB;
    }
    else if(this->op == EXP::Operation::Divi)
    {
        resultOperation = resultA/resultB;
    }
    else
    {
        throw std::invalid_argument("Wrong Operation");
    }

    return resultOperation;
}

long double EXP::ExponentCalculator::result(ExponentNumbers numbers)
{
    long double resultA = 0;
    long double resultB = 0;
    bool caseAXBY = (numbers.a != nullptr && numbers.b != nullptr && numbers.x != nullptr && numbers.y != nullptr);
    bool caseAXY = (numbers.b == nullptr && numbers.x != nullptr && numbers.y != nullptr && numbers.a != nullptr);
    bool caseAX = (numbers.b == nullptr && numbers.x != nullptr && numbers.y == nullptr && numbers.a != nullptr);
    bool caseAXB = (numbers.a != nullptr && numbers.x != nullptr && numbers.y == nullptr && numbers.b != nullptr);
    bool caseABY = (numbers.a != nullptr && numbers.x == nullptr && numbers.y != nullptr && numbers.b != nullptr);
    bool caseAB = (numbers.a != nullptr && numbers.b != nullptr && numbers.y == nullptr && numbers.x == nullptr);
    bool caseA = (numbers.a != nullptr && numbers.b == nullptr && numbers.y == nullptr && numbers.x == nullptr);
    bool caseB = (numbers.b != nullptr && numbers.a == nullptr && numbers.y == nullptr && numbers.x == nullptr);

    if(caseAXBY)
    {
        resultA = pow(*numbers.a,*numbers.x);
        resultB = pow(*numbers.b,*numbers.y);
    }
    else if(caseAXY)
    {
        resultA = pow(*numbers.a,*numbers.x);
        return pow(resultA,*numbers.y);
    }
    else if(caseAX)
    {
        return pow(*numbers.a,*numbers.x);
    }
    else if(caseAXB)
    {
        resultA = pow(*numbers.a,*numbers.x);
        resultB = *numbers.b;
    }
    else if(caseABY)
    {
        resultA = *numbers.a;
        resultB = pow(*numbers.b,*numbers.y);
    }
    else if(caseAB)
    {
        resultA = *numbers.a;
        resultB = *numbers.b;
    }
    else if(caseA)
    {
        return *numbers.a;
    }
    else if(caseB)
    {
        return *numbers.b;
    }
    
    return this->doOperation(resultA,resultB);  
}

void EXP::ExponentCalculator::setOperation(Operation op)
{
    this->op = op;
};

EXP::Operation EXP::ExponentCalculator::getOperation()
{
    return this->op;
};