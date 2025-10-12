#include <iostream>
#include <cmath>

float readNumber(void)
{
    float Number;

    std::cout << "Please enter a number : ";
    std::cin >> Number;

    return (Number);
}

int myAbs(int Number)
{
    if (Number < 0)
        return (Number * -1);
    else
        return (Number);
}

int Last4DigitsOf(int Number)
{
    return (Number % 1000);
}

float getFractionPartOf(float Number)
{
    int FractionPart = myAbs((int)(Number * 1000));

    return (Last4DigitsOf(FractionPart) / (float)1000);
}

float myRound(float Number)
{
    float fractionPart = getFractionPartOf(Number);

    if (Number >= 0 && fractionPart < 0.5)
        return (Number - fractionPart);
    else if (Number >= 0 && fractionPart >= 0.5)
        return (Number - fractionPart + 1);
    else if (Number <  0 && fractionPart >= 0.5)
        return (Number + fractionPart - 1);
    else
        return (Number + fractionPart);
}

int main(void)
{
    float Number = readNumber();

    std::cout << "My round  : " << myRound(Number) << '\n';
    std::cout << "C++ round : " << round(Number) << '\n';

    return (0);
}
