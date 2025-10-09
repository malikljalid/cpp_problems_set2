#include <iostream>

enum enASCII { A = 65, Z = 90 };

int readNumber(void)
{
    int Number;

    std::cout << "Please enter a number : ";
    std::cin >> Number;

    return (Number);
}

void printLetterPattern(int Number)
{
    for (int i = A; i <= Number + (A - 1); i++)
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
    printLetterPattern(readNumber());
    return (0);
}
