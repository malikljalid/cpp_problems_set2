#include <iostream>
#include <string>
#include <cmath>

enum enColor { GREEN = 32 };

int readNumber(void)
{
    int Number;

    std::cout << "Please enter a number N : ";
    std::cin >> Number;

    return (Number);
}

int readPostiveNumber(void)
{
    int Number = readNumber();

    while (Number < 0)
    {
        std::cout << "This is Negative Number! Please enter Postive!\n";
        Number = readNumber();
    }
    return (Number);
}

bool numberIsDevidedBy(int Number, int Devider)
{
    return (Number % Devider == 0);
}

bool checkIfNumberIsPrime(int Number)
{
    float STOP = sqrt(Number);

    for (int i = 2; i <= STOP; i++)
    {
        if (numberIsDevidedBy(Number, i))
        {
            return (false);
        }
    }
    return (true);
}

bool numberIsPrime(int Number)
{
    if (Number < 2)
        return (false);
    else
        return (checkIfNumberIsPrime(Number));
}

void textToGreen(int Number)
{
    std::cout << "\033[" << GREEN << "m";
    std::cout << Number << ' ';
    std::cout << "\033[0m";
}

void fitNumberInPrimeTable(int Number)
{
    if (Number < 10)
        std::cout << ' ';

    if (numberIsPrime(Number))
        textToGreen(Number);
    else
        std::cout << Number << ' ';
        
    if (Number % 10 == 0)
        std::cout << '\n';
}

void printTableOfPrimeNumbersFromTo(int From, int To)
{
    std::cout << "\nTable of Prime Numbers (Green Numbers) from " << From << " to " << To << " : \n\n";
    for (int i = From; i <= To; i++)
    {
        fitNumberInPrimeTable(i);
    }
    std::cout << std::endl;
}

int main(void)
{
    printTableOfPrimeNumbersFromTo(1, readPostiveNumber());
    return (0);
}
