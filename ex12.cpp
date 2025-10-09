#include <iostream>

int readNumber(void)
{
    int Number;

    std::cout << "Please enter a number : ";
    std::cin >> Number;

    return (Number);
}

void printInvertedPattern(int Number)
{
    for (int i = Number; i >= 1; i--)
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
    printInvertedPattern(readNumber());
    return (0);
}
