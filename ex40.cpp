#include <iostream>
#include <cmath>

enum enDefaultSize { MAXSIZE = 100 };

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

short int getNumberPositionInArray(int ToFind, int arr[MAXSIZE], int Size)
{
    for (short int i = 0; i < Size; i++)
    {
        if (arr[i] == ToFind)
            return (i);
    }
    return (-1);
}

bool isNumberDoesntExistInArray(int ToFind, int arr[MAXSIZE], int Size)
{
    return (getNumberPositionInArray(ToFind, arr, Size) == -1);
}

void copyArrayDistinct(int originalArr[MAXSIZE], int copyArr[MAXSIZE], int originalSize, int &copySize)
{
    for (int i = 0; i < originalSize; i++)
    {
        if (isNumberDoesntExistInArray(originalArr[i], copyArr, copySize))
            addElementToArray(originalArr[i], copyArr, copySize);
    }
}

int main(void)
{
    srand((unsigned)time(NULL));

    int arr[MAXSIZE] = { 10, 20, 10, 10, 20, 10, 30, 10, 90, 90 };
    int arrSize = 10;

    printArrayElements("oringal array : ", arr, arrSize);

    int newArr[MAXSIZE];
    int newArrSize = 0;

    copyArrayDistinct(arr, newArr, arrSize, newArrSize);
    printArrayElements("copy array distinct : ", newArr, newArrSize);

    return (0);
}
