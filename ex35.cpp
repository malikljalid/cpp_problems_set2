#include <iostream>

enum enDefaultSize { MAXSIZE = 100 };

int randomNumber(int From, int To)
{
    return ((rand() % To - From + 1) - From);
}

int readNumber(void)
{
    int Number;

    std::cout << "Please enter a number to search for : ";
    std::cin >> Number;

    return (Number);
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

short int getNumberPositionInArray(int arr[MAXSIZE], int Size, int ToFind)
{
    for (short int i = 0; i < Size; i++)
    {
        if (arr[i] == ToFind)
            return (i);
    }
    return (-1);
}

bool isNumberExistInArray(int arr[MAXSIZE], int Size, int ToFind)
{
    return (getNumberPositionInArray(arr, Size, ToFind) != -1);
}

void findNumberInArray(int arr[MAXSIZE], int Size, int ToFind)
{
    bool isFound = isNumberExistInArray(arr, Size, ToFind);

    std::cout << "\nThe number you are looking for is : " << ToFind << '\n';

    if (isFound == false)
        std::cout << "The number is NOT found! :(\n";
    else
        std::cout << "The number is FOUND :) \n";
}

int main(void)
{
    srand((unsigned)time(NULL));

    int arr[MAXSIZE];
    int arrSize = 0;

    fillArrayElementsWithRandomValues(arr, arrSize, 1, 100);
    printArrayElements(arr, arrSize);
    findNumberInArray(arr, arrSize, readNumber());

    return (0);
}
