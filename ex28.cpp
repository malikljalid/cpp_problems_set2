#include <iostream>
#include <cmath>

enum enDefaultSize { MAXSIZE = 100 };

int randomNumber(int From, int To)
{
    return ((rand() % To - From + 1) - From);
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

void copyArray(int originalArr[MAXSIZE], int copyArr[MAXSIZE], int Size)
{
    for (int i = 0; i < Size; i++)
    {
        copyArr[i] = originalArr[i];
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

    copyArray(arr, newArr, arrSize);
    printArrayElements(newArr, arrSize);

    return (0);
}
