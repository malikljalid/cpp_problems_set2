#include <iostream>
#include <cmath>

float readNumber(void)
{
    float Number;

    std::cout << "Please enter a number : ";
    std::cin >> Number;

    return (Number);
}

float myAbs(float Number)
{
    if (Number < 0)
        return (Number * -1);
    else
        return (Number);
}

// newton method to find square root implemented
float mySqrt(int Number)
{
    float i  = 0;
    float xn = 1;

    if (Number == 0)
        return (0);

    while (1)
    {
        i  = (xn + (Number / xn)) / 2;

        if (myAbs(i - xn) <= 0.000001)
            break;

        xn  = i;
    }
    return (i);
}

int main(void)
{
    float Number = readNumber();

    std::cout << "My sqrt  : " << mySqrt(Number) << '\n';
    std::cout << "C++ sqrt : " << sqrt(Number) << '\n';

    return (0);
}
