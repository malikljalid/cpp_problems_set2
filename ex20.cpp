#include <iostream>
#include <cstdlib>
#include <ctime>

enum enASCIILetter { SMALL, UPPER, SPECIAL, DIGIT };

int randomNumber(int From, int To)
{
    return ((rand() % (To - From + 1)) + From);
}

char getRandomASCII(enASCIILetter Type)
{
    switch (Type)
    {
        case (enASCIILetter::SMALL) :
            return (randomNumber('a', 'z'));
        case (enASCIILetter::UPPER) :
            return (randomNumber('A', 'Z'));
        case (enASCIILetter::SPECIAL) :
            return (randomNumber('!', '/'));
        case (enASCIILetter::DIGIT) :
            return (randomNumber('0', '9'));
        default :
            return ('\0');
    }
}

int main(void)
{
    srand((unsigned)time(NULL));


    std::cout << getRandomASCII(SMALL) << '\n';
    std::cout << getRandomASCII(UPPER) << '\n';
    std::cout << getRandomASCII(SPECIAL) << '\n';
    std::cout << getRandomASCII(DIGIT) << '\n';

    return (0);
}
