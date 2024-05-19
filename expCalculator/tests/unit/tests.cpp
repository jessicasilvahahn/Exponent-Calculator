#include "../../exponentCalculator.h"
#include <gtest/gtest.h>
 
TEST(ExponentCalculatorTestMulti, axMultiay) {
    /*case a^xa^y
        result = 2^5 = 32 
    */

    ExponentNumbers numbers = ExponentNumbers();
    numbers.a = new double(2);
    numbers.b = numbers.a;
    numbers.x = new double(2);
    numbers.y = new double(3);
    EXP::ExponentCalculator *expo = new EXP::ExponentCalculator();
    expo->setOperation(EXP::Operation::Multi);
    long double result = expo->result(numbers);
    ASSERT_EQ(32, result);
}

TEST(ExponentCalculatorTestMulti, axMultibx) {
    /*case a^xb^x
        result = (2*1)^2 = 4
    */
    ExponentNumbers numbers = ExponentNumbers();
    numbers.a = new double(2);
    numbers.b = new double(1);
    numbers.x = new double(2);
    EXP::ExponentCalculator expo = EXP::ExponentCalculator();
    expo.setOperation(EXP::Operation::Multi);
    long double result = expo.result(numbers);
    ASSERT_EQ(4, result);
}

TEST(ExponentCalculatorTestDiv, axDivay) {
    /*case a^x/a^y
        result = 2^5/2^3 = 32/8 = 4 
    */

    ExponentNumbers numbers = ExponentNumbers();
    numbers.a = new double(2);
    numbers.b = numbers.a;
    numbers.x = new double(5);
    numbers.y = new double(3);
    EXP::ExponentCalculator expo = EXP::ExponentCalculator();
    expo.setOperation(EXP::Operation::Divi);
    long double result = expo.result(numbers);
    ASSERT_EQ(4,result);
}

TEST(ExponentCalculatorTestDiv, axDivbx) {
    /*case a^x/b^x
        result = (8/2)^2 = 16 
    */
    ExponentNumbers numbers = ExponentNumbers();
    numbers.a = new double(8);
    numbers.b = new double(2);
    numbers.x = new double(2);
    numbers.y = numbers.x;
    EXP::ExponentCalculator expo = EXP::ExponentCalculator();
    expo.setOperation(EXP::Operation::Divi);
    long double result = expo.result(numbers);
    ASSERT_EQ(16, result);
}

TEST(ExponentCalculatorOther, axy) {
    /*case (a^x)^y
        result = (8^2)^2 = 4096 
    */
    ExponentNumbers numbers = ExponentNumbers();
    numbers.a = new double(8);
    numbers.x = new double(2);
    numbers.y = numbers.x;
    EXP::ExponentCalculator expo = EXP::ExponentCalculator();
    long double result = expo.result(numbers);
    ASSERT_EQ(4096,result);
}

TEST(ExponentCalculatorOther, a0) {
    /*case a^0
        result = 1
    */
    ExponentNumbers numbers = ExponentNumbers();
    numbers.a = new double(8);
    numbers.x = new double(0);
    EXP::ExponentCalculator expo = EXP::ExponentCalculator();
    long double result = expo.result(numbers);
    ASSERT_EQ(1,result);
}

TEST(ExponentCalculatorOther, aNegative) {
    /*case a^-x
        result = 8^-2
    */
    ExponentNumbers numbers = ExponentNumbers();
    numbers.a = new double(8);
    numbers.x = new double(-2);
    EXP::ExponentCalculator expo = EXP::ExponentCalculator();
    long double result = expo.result(numbers);
    ASSERT_EQ(0.015625,result);
}

TEST(ExponentCalculatorTestMulti, axMultiby) {
    /*case a^x*b^y
        result = 2^2*3^3 = 108;
    */
    ExponentNumbers numbers = ExponentNumbers();
    numbers.a = new double(2);
    numbers.b = new double(3);
    numbers.x = new double(2);
    numbers.y = new double(3);
    EXP::ExponentCalculator expo = EXP::ExponentCalculator();
    expo.setOperation(EXP::Operation::Multi);
    long double result = expo.result(numbers);
    ASSERT_EQ(108,result);
}

TEST(ExponentCalculatorTestDiv, axDivib) {
    /*case a^x/b
        result = 2^2/2 = 2;
    */
    ExponentNumbers numbers = ExponentNumbers();
    numbers.a = new double(2);
    numbers.b = numbers.a;
    numbers.x = new double(2);
    EXP::ExponentCalculator expo = EXP::ExponentCalculator();
    expo.setOperation(EXP::Operation::Divi);
    long double result = expo.result(numbers);
    ASSERT_EQ(2,result);
}

TEST(ExponentCalculatorTestDiv, aDiviby) {
    /*case a/b^y
        result = 1/1^2 = 1;
    */

    ExponentNumbers numbers = ExponentNumbers();
    numbers.a = new double(1);
    numbers.b = numbers.a;
    numbers.y = new double(2);
    EXP::ExponentCalculator expo = EXP::ExponentCalculator();
    expo.setOperation(EXP::Operation::Divi);
    long double result = expo.result(numbers);
    ASSERT_EQ(1,result);
}

TEST(ExponentCalculatorTestDiv, ab) {
    /*case a/b
        result = 4/2 = 2;
    */

    ExponentNumbers numbers = ExponentNumbers();
    numbers.a = new double(4);
    numbers.b = new double(2);
    EXP::ExponentCalculator expo = EXP::ExponentCalculator();
    expo.setOperation(EXP::Operation::Divi);
    long double result = expo.result(numbers);
    ASSERT_EQ(2,result);
}

TEST(ExponentCalculatorTestDiv, a) {
    /*case a
        result = 4 = 4;
    */

    ExponentNumbers numbers = ExponentNumbers();
    numbers.a = new double(4);
    EXP::ExponentCalculator expo = EXP::ExponentCalculator();
    long double result = expo.result(numbers);
    ASSERT_EQ(4,result);
}

TEST(ExponentCalculatorTestDiv, b) {
    /*case a
        result = 2 = 2;
    */

    ExponentNumbers numbers = ExponentNumbers();
    numbers.b = new double(2);
    EXP::ExponentCalculator expo = EXP::ExponentCalculator();
    long double result = expo.result(numbers);
    ASSERT_EQ(2,result);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}