#include <iostream>

enum enASCII { A = 65, Z = 90 };

void printFromAAAToZZZ(void)
{
    for (int i = A; i <= Z; i++)
    {
        for (int j = A; j <= Z; j++)
        {
            for (int k = A; k <= Z; k++)
                std::cout << char(i) << char(j) << char(k) << '\n';
        }
    }
}

int main(void)
{
    printFromAAAToZZZ();
    return (0);
}
