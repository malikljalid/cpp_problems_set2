#include <iostream>

int readNumber(void)
{
    int Number;

    std::cout << "Please enter a number : ";
    std::cin >> Number;

    return (Number);
}

int LastDigitOf(int Number)
{
    return (Number % 10);
}

int getReversedNumber(int Number)
{
    int Remainder       = Number;
    int ReversedNumber  = 0;


    while (Remainder != 0)
    {
        ReversedNumber *= 10;
        ReversedNumber  += LastDigitOf(Remainder);
        Remainder /= 10;
    }
    return (ReversedNumber);
}

void printNumberSumOfDigits(int Number)
{
    std::cout << "Reversed Of " << Number << "  : " << getReversedNumber(Number) << '\n';
}

int main(void)
{
    printNumberSumOfDigits(readNumber());
    return (0);
}
