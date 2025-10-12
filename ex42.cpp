#include <iostream>
#include <cmath>

enum enDefaultSize { MAXSIZE = 100 };

int randomNumber(int From, int To)
{
    return ((rand() % To - From + 1) - From);
}

int isOdd(int Number)
{
    return (Number % 2 != 0);
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

void printArrayElements(std::string msg, int arr[MAXSIZE], int Size)
{
    std::cout << "\n" << msg;
    for (int i = 0; i < Size; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

void addElementToArray(int elem, int arr[MAXSIZE], int &size)
{
    arr[size++] = elem;
}

int getCountOfOddNumbersInArray(int arr[MAXSIZE], int size)
{
    int oddCount = 0;

    for (int i = 0; i < size; i++)
    {
        if (isOdd(arr[i]))
            oddCount++;
    }
    return (oddCount);
}

int main(void)
{
    srand((unsigned)time(NULL));

    int arr[MAXSIZE];
    int arrSize = 0;

    fillArrayElementsWithRandomValues(arr, arrSize, 1, 100);
    printArrayElements("array : ", arr, arrSize);

    std::cout << "Odd numbers in array : " << getCountOfOddNumbersInArray(arr, arrSize) << '\n';

    return (0);
}
