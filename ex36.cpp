#include <iostream>

enum enDefaultSize { MAXSIZE = 100 };

int readNumber(void)
{
    int Number;

    std::cout << "Please enter a number : ";
    std::cin >> Number;

    return (Number);
}

void addElementToArray(int elem, int arr[MAXSIZE], int &size)
{
    arr[size++] = elem;
}

void fillArray(int arr[MAXSIZE], int &size)
{
    bool userWantAddMore = true;

    while (userWantAddMore)
    {
        addElementToArray(readNumber(), arr, size);
        std::cout << "Do you want to add More Numbers ? (0-No / 1-Yes) : ";
        std::cin >> userWantAddMore;
    }
}

void printArrayElements(std::string msg, int arr[MAXSIZE], int Size)
{
    std::cout << msg;
    for (int i = 0; i < Size; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

int main(void)
{
    int arr[MAXSIZE];
    int size = 0;

    fillArray(arr, size);
    printArrayElements("array content : ", arr, size);

    return (0);
}
