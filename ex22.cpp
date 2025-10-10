#include <iostream>

enum enDefaultSize { MAXSIZE = 100 };

int readNumber(void)
{
    int Number;

    std::cout << "Enter the number to check : ";
    std::cin >> Number;

    return (Number);
}

void readArrayElements(int arr[MAXSIZE], int &Size)
{
    std::cout << "How many elements you want to enter ? : ";
    std::cin >> Size;

    for (int i = 0; i < Size; i++)
    {
        std::cout << "arr[" << i << "] : ";
        std::cin >> arr[i];
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

int getOccuranceOfNumberInArray(int Number, int arr[MAXSIZE], int Size)
{
    int NumberOcc = 0;

    for (int i = 0; i < Size; i++)
    {
        if (Number == arr[i])
            NumberOcc++;
    }
    return (NumberOcc);
}

void printOccuranceOfNumberInArray(int Number, int Occ)
{
    std::cout << Number << " is repeted " << Occ << " times\n";
}

int main(void)
{
    srand((unsigned)time(NULL));

    int arr[MAXSIZE];
    int arrSize = 0;

    readArrayElements(arr, arrSize);
    printArrayElements(arr, arrSize);

    int NumberToCheck = readNumber();

    printOccuranceOfNumberInArray(NumberToCheck, getOccuranceOfNumberInArray(NumberToCheck, arr, arrSize));
    return (0);
}
