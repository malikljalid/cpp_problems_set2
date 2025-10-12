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

float myCeil(float Number)
{
    float fractionPart = getFractionPartOf(Number);

    if (fractionPart == 0.0)
        return (Number);

    if (Number >= 0)
        return (Number - fractionPart + 1);
    else
        return (Number + fractionPart);
}

int main(void)
{
    float Number = readNumber();

    std::cout << "My ceil  : " << myCeil(Number) << '\n';
    std::cout << "C++ ceil : " << ceil(Number) << '\n';

    return (0);
}
