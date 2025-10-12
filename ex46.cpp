#include <iostream>
#include <cmath>

int readNumber(void)
{
    int Number;

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

int main(void)
{
    int Number = readNumber();

    std::cout << "My abs  : " << myAbs(Number) << '\n';
    std::cout << "C++ abs : " << abs(Number) << '\n';

    return (0);
}
