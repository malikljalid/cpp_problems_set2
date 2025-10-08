#include <iostream>

void multiplicationTableHeader(void)
{
    std::cout << "\n\t\t\tMutliplication Table from 1 To 10 \n\n";
    for (int i = 1; i <= 10; i++)
    {
        std::cout << '\t' << i;
    }
    std::cout << "\n-------------------------------------------------------------------------------------\n";
}

void printNumberWithcolumSeparetor(int Number)
{
    if (Number < 10)
        std::cout << Number << "   |   ";
    else
        std::cout << Number << "  |  ";
}

void multiplicationTableOf(int Number)
{
    printNumberWithcolumSeparetor(Number);
    for (int i = 1; i <= 10; i++)
    {
        std::cout << Number * i << '\t';
    }
    std::cout << '\n';
}

void printMultiplicationTableOfFromTo(int From, int To)
{
    multiplicationTableHeader();
    for (int i = From; i <= To; i++)
        multiplicationTableOf(i);
}

int main(void)
{
    printMultiplicationTableOfFromTo(1, 10);
    return (0);
}
