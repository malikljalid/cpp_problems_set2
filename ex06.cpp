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

int getSumOfNumberDigits(int Number)
{
    int Remainder   = Number;
    int SumOfDigits = 0;

    while (Remainder != 0)
    {
        SumOfDigits += LastDigitOf(Remainder);
        Remainder /= 10;
    }
    return (SumOfDigits);
}

void printNumberSumOfDigits(int Number)
{
    std::cout << "Sum of " << Number << " Digits = " << getSumOfNumberDigits(Number) << '\n';
}

int main(void)
{
    printNumberSumOfDigits(readNumber());
    return (0);
}
