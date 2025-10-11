#include <iostream>
#include <cstdlib>
#include <ctime>

enum enDefaultSize  { MAXSIZE   = 100 };

int randomNumber(int From, int To)
{
    return ((rand() % (To - From + 1)) + From);
}

int readHowManyKeys(void)
{
    int KeysNumber;

    std::cout << "How many keys you want to generate ? : ";
    std::cin >> KeysNumber;

    return (KeysNumber);
}

bool isNotUnderscore(int index)
{
    return (index != 4 && index != 9 && index != 14);
}

std::string generateKey(void)
{
    std::string key = "XXXX-XXXX-XXXX-XXXX";

    for (int i = 0; i < key.length(); i++)
    {
        if (isNotUnderscore(i))
            key[i] = randomNumber('A', 'Z');
    }
    return (key);
}

void printKey(int keyNumber, std::string key)
{
    std::cout << "Key[" << keyNumber << "] : " << key << '\n';
}

void printKeys(std::string keys[MAXSIZE], int Size)
{
    for (int i = 0; i < Size; i++)
    {
        printKey(i, keys[i]);
    }
}

void fillArrayWithRandomKeys(std::string arr[MAXSIZE], int Size)
{
    for (int i = 0; i < Size; i++)
    {
        arr[i] = generateKey();
    }
}

int main(void)
{
    srand((unsigned)time(NULL));

    std::string keys[MAXSIZE];
    int         Size = readHowManyKeys();

    fillArrayWithRandomKeys(keys, Size);
    printKeys(keys, Size);

    return (0);
}
