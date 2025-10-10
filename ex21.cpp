#include <iostream>

enum enKeyLength { KeyLength = 19 };

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

bool is_underscore(int index)
{
    return (index == 4 || index == 9 | index == 14);
}

std::string generateKey(void)
{
    std::string key = "";

    for (int i = 0; i < KeyLength; i++)
    {
        if (is_underscore(i))
            key[i] = '-';
        else
            key[i] = randomNumber('A', 'Z');
    }
    return (key);
}

void printKey(int keyNumber, std::string key)
{
    std::cout << "Key[" << keyNumber << "] : " << key << '\n';
}

void printKeys(int keysNumber)
{
    for (int i = 1; i <= keysNumber; i++)
    {
        printKey(i, generateKey());
    }
}

int main(void)
{
    printKeys(readHowManyKeys());
    return (0);
}
