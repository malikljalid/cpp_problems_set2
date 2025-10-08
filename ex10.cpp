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
        ReversedNumber  *= 10;
        ReversedNumber  += LastDigitOf(Remainder);
        Remainder /= 10;
    }
    return (ReversedNumber);
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

void printNumberDigitsInOrder(int Number)
{
    int ReversedNumber = getReversedNumber(Number);

    printNumberReversed(ReversedNumber); // so it will print each digit from lift to right in the order of the original number
}

int main(void)
{
    printNumberDigitsInOrder(readNumber());
    return (0);
}
