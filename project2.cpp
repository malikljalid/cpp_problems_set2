#include <iostream>
#include <cstdlib>
#include <ctime>

enum    enOperationsLevel    { EASY, MED, HARD, MIX };
enum    enOperationsType     { ADD='+', SUB='-', MUL='*', DIV='/', ALL };
enum    enOperationsResult   { FAIL, PASS };

struct  stOperations
{
    enOperationsLevel       Level;
    enOperationsType        Type;
    enOperationsResult      FinalResult;
    short int               NumberOfQuestions;
    short int               WrongAnswers;
    short int               RightAnswers;
    char                    playAgain;
};

int randomNumber(int From, int To)
{
    return ((rand() % (To - From + 1)) + From);
}

int main(void)
{
    srand((unsigned int)time(NULL));
    return (0);
}
//logic