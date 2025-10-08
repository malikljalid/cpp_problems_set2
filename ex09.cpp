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

void printAllDigitsFrequencyInNumber(int Number)
{
    int DigitOcc[10] = { 0 };
    int Remainder    = Number;

    while (Remainder != 0) //scanning the number's digits, all of them
    {
        DigitOcc[LastDigitOf(Remainder)]++;  // increment each digit occurance in the number
        Remainder /= 10;
    }

    for (int Digit = 0; Digit < 9; Digit++) // walk through all digits
    {
        if (DigitOcc[Digit] != 0)  // only digits existed in the number
            std::cout << Digit << " Frequency in " << DigitOcc[Digit] << " Times\n";
    }
}

int main(void)
{
    printAllDigitsFrequencyInNumber(readNumber());
    return (0);
}
