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

float myFloor(float Number)
{
    float fractionPart = getFractionPartOf(Number);

    if (fractionPart == 0.0)
        return (Number);

    if (Number >= 0)
        return (Number - fractionPart);
    else
        return (Number + fractionPart - 1);
}

int main(void)
{
    float Number = readNumber();

    std::cout << "My floor  : " << myFloor(Number) << '\n';
    std::cout << "C++ floor : " << floor(Number) << '\n';

    return (0);
}
