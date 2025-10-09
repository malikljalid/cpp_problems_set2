#include <iostream>

enum enASCII { A = 65, Z = 90 };

int readNumber(void)
{
    int Number;

    std::cout << "Please enter a number : ";
    std::cin >> Number;

    return (Number);
}

void printInvertedPattern(int Number)
{
    for (int i = Number + (A - 1); i >= A; i--)
    {
        for (int j = i; j >= A; j--)
        {
            std::cout << char(i) << ' ';
        }
        std::cout << '\n';
    }
}

int main(void)
{
    printInvertedPattern(readNumber());
    return (0);
}
