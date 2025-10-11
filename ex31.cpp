#include <iostream>
#include <cmath>

enum enDefaultSize { MAXSIZE = 100 };

int randomNumber(int From, int To)
{
    return ((rand() % To - From + 1) - From);
}

void swap(int &N1, int &N2)
{
    int tmp = 0;

    if (N1 != N2)
    {
        tmp = N1;
        N1  = N2;
        N2  = tmp;
    }
}

int readNumber(void)
{
    int Size;

    std::cout << "How many elements you want in the array ? : ";
    std::cin >> Size;

    return (Size);
}

void fillArrayElementsWithSortedValues(int arr[MAXSIZE], int Size)
{
    for (int i = 0; i < Size; i++)
    {
        arr[i] = i + 1;
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

void shuffleSortedArray(int arr[MAXSIZE], int Size)
{
    for (int i = 0; i < Size / 2; i++)
    {
        swap(arr[i], arr[randomNumber(0, Size - 1)]);
    }
}

int main(void)
{
    srand((unsigned)time(NULL));

    int sortedArr[MAXSIZE];
    int arrSize = readNumber();

    fillArrayElementsWithSortedValues(sortedArr, arrSize);
    printArrayElements("array before shuffle : ", sortedArr, arrSize);

    shuffleSortedArray(sortedArr, arrSize);
    printArrayElements("array after shuffle : ", sortedArr, arrSize);

    return (0);
}
