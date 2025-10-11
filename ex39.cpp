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

bool isPrime(int Number)
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

void copyOnlyOddNumbersFromArray(int originalArr[MAXSIZE], int copyArr[MAXSIZE], int originalSize, int &copySize)
{
    for (int i = 0; i < originalSize; i++)
    {
        if (isPrime(originalArr[i]))
            addElementToArray(originalArr[i], copyArr, copySize);
    }
}

int main(void)
{
    srand((unsigned)time(NULL));

    int arr[MAXSIZE];
    int arrSize = 0;

    fillArrayElementsWithRandomValues(arr, arrSize, 1, 100);
    printArrayElements("oringal array : ", arr, arrSize);

    int newArr[MAXSIZE];
    int newArrSize = 0;

    copyOnlyOddNumbersFromArray(arr, newArr, arrSize, newArrSize);
    printArrayElements("copy prime array : ", newArr, newArrSize);

    return (0);
}
