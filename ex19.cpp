#include <iostream>
#include <cstdlib>
#include <ctime>

int randomNumber(int From, int To)
{
    return (rand() % ((To - From + 1) + From));
}

int main(void)
{
    srand((unsigned)time(NULL));

    int i = randomNumber(13, 42);

    std::cout << "My Random Numbr : " << i << std::endl;

    return (0);
}
