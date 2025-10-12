#include <iostream>

enum enDefaultSize { MAXSIZE=100 };

int readUserInput(int index)
{
    int Number;

    std::cout << "arr[" << index << "] : ";
    std::cin >> Number;

    return (Number);
}

void addElementToArray(int elem, int arr[MAXSIZE], int &size)
{
    arr[size++] = elem;
}

void fillArrayWithUserInput(int arr[MAXSIZE], int &size)
{
    int userWantAdd = 0;

    std::cout << "Please how many number you want to enter : ";
    std::cin >> userWantAdd;
    
    size = 0;
    while (userWantAdd--)
        addElementToArray(readUserInput(size), arr, size);
}

void printArrayElements(std::string msg, int arr[MAXSIZE], int size)
{
    std::cout << '\n' << msg;
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

bool arrayIsPalindorme(int arr[MAXSIZE], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        if (arr[i] != arr[size - 1 - i])
            return (false);
    }
    return (true);
}

void printIfArrayIsPalindorme(int arr[MAXSIZE], int size)
{
    std::string Palindorme[2] = { "NOT Palindorme", "Palindorme" };

    std::cout << "Array is : " << Palindorme[arrayIsPalindorme(arr, size)] << '\n';
}

int main(void)
{
    int arr[MAXSIZE];
    int size = 0;

    fillArrayWithUserInput(arr, size);
    printArrayElements("array : ", arr, size);
    printIfArrayIsPalindorme(arr, size);

    return (0);
}
