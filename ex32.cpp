#include <iostream>
#include <cmath>

enum enDefaultSize { MAXSIZE = 100 };

int randomNumber(int From, int To)
{
    return ((rand() % To - From + 1) - From);
}

int readNumber(void)
{
    int Size;

    std::cout << "How many elements you want in the array ? : ";
    std::cin >> Size;

    return (Size);
}

void fillArrayElementsWithRandomValues(int arr[MAXSIZE], int Size, int From, int To)
{
    for (int i = 0; i < Size; i++)
    {
        arr[i] = randomNumber(From, To);
    }
}

void printArrayElements(std::string arrName, int arr[MAXSIZE], int Size)
{
    std::cout << "\n" << arrName;
    for (int i = 0; i < Size; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

void copyReversedArray(int arr1[MAXSIZE], int arr2[MAXSIZE], int Size)
{
    for (int i = 0; i < Size; i++)
    {
        arr2[i] = arr1[Size - 1 - i];
    }
}

int main(void)
{
    srand((unsigned)time(NULL));

    int arr1[MAXSIZE];
    int arr2[MAXSIZE];
    int arrSize = readNumber();

    fillArrayElementsWithRandomValues(arr1, arrSize, 1, 100);
    printArrayElements("Original Array : ", arr1, arrSize);

    copyReversedArray(arr1, arr2, arrSize);
    printArrayElements("Reversed Array : ", arr2, arrSize);

    return (0);
}
