#include <iostream>
#include <cmath>

enum enDefaultSize { MAXSIZE = 100 };

int randomNumber(int From, int To)
{
    return ((rand() % To - From + 1) - From);
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

void fillArrayElementsWithRandomValues(int arr[MAXSIZE], int &Size, int From, int To)
{
    std::cout << "How many elements you want in the array ? : ";
    std::cin >> Size;

    for (int i = 0; i < Size; i++)
    {
        arr[i] = randomNumber(From, To);
    }
}

void printArrayElements(int arr[MAXSIZE], int Size)
{
    std::cout << "\nOriginal Array : ";
    for (int i = 0; i < Size; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

void copyPrimeNumbersInArray(int originalArr[MAXSIZE], int originalSize, int copyArr[MAXSIZE],  int &copySize)
{
    copySize = 0;

    for (int i = 0; i < originalSize; i++)
    {
        if (numberIsPrime(originalArr[i]) == true)
        {
            copyArr[copySize] = originalArr[i];
            copySize++;
        }
    }
}

int main(void)
{
    srand((unsigned)time(NULL));

    int arr[MAXSIZE];
    int arrSize = 0;

    fillArrayElementsWithRandomValues(arr, arrSize, 1, 100);
    printArrayElements(arr, arrSize);

    int newArr[MAXSIZE];
    int newArrSize = 0;

    copyPrimeNumbersInArray(arr, arrSize, newArr, newArrSize);
    printArrayElements(newArr, newArrSize);

    return (0);
}
