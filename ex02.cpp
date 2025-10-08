#include <iostream>

int readNumber(void)
{
    int Number;

    std::cout << "Please enter a number : ";
    std::cin >> Number;

    return (Number);
}

int getNumberSumOfDevidors(int Number)
{
    int SumOfDevidors = 0;

    for (int i = 1; i < Number; i++)
    {
        if (Number % i == 0)
            SumOfDevidors += i;
    }
    return (SumOfDevidors);
}

bool isNumberPerfect(int Number)
{
    return (getNumberSumOfDevidors(Number) == Number);
}

void printIfNumberIsPerfect(int Number)
{
    std::string Perfect[2] = {"Not Perfect", "Perfect"};

    std::cout << Number << " : " << Perfect[isNumberPerfect(Number)] << '\n';
}

int main(void)
{
    printIfNumberIsPerfect(readNumber());
    return (0);
}
