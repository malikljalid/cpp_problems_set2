#include <iostream>

int readNumber(void)
{
    int Number;

    std::cout << "Please enter a number : ";
    std::cin >> Number;

    return (Number);
}

void printNormalPattern(int Number)
{
    for (int i = 1; i <= Number; i++)
    {
        for (int j = i; j > 0; j--)
        {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
}

int main(void)
{
    printNormalPattern(readNumber());
    return (0);
}
