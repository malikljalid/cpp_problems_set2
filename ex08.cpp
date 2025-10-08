#include <iostream>

int readNumber(void)
{
    int Number;

    std::cout << "Please enter a number : ";
    std::cin >> Number;

    return (Number);
}

int readDigit(void)
{
    int Digit;

    std::cout << "Please enter a digit : ";
    std::cin >> Digit;

    return (Digit);
}

int LastDigitOf(int Number)
{
    return (Number % 10);
}

int getDigitFrequencyInNumber(int Digit, int Number)
{
    int Remainder  = Number;
    int Frequency  = 0;

    while (Remainder != 0)
    {
        if (LastDigitOf(Remainder) == Digit)
            Frequency++;
        Remainder /= 10;
    }
    return (Frequency);
}

void printDigitFrequencyInNumber(int Digit, int Number)
{
    std::cout << Digit << " Frequency in " << Number << " is : " << getDigitFrequencyInNumber(Digit, Number) << " Times\n";
}

int main(void)
{
    printDigitFrequencyInNumber(readDigit(), readNumber());
    return (0);
}
