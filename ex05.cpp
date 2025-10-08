#include <iostream>

int readNumber(void)
{
    int Number;

    std::cout << "Please enter a number : ";
    std::cin >> Number;

    return (Number);
}

void printLastDigitOf(int Number)
{
    std::cout << Number % 10 << '\n';
}

void printNumberReversed(int Number)
{
    int Remainder = Number;

    while (Remainder != 0)
    {
        printLastDigitOf(Remainder);
        Remainder /= 10;
    }
}

int main(void)
{
    printNumberReversed(readNumber());
    return (0);
}
