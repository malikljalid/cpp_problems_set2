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

bool isNumberPalindorme(int Number)
{
    int ReversedNumber = getReversedNumber(Number);

    return (ReversedNumber == Number);
}

void printIfNumberIsPalindorme(int Number)
{
    std::string Pal[2] = {"NOT Palindorme", "Palindorme"};

    std::cout << Number << " is : " << Pal[isNumberPalindorme(Number)] << '\n';
}

int main(void)
{
    printIfNumberIsPalindorme(readNumber());
    return (0);
}
