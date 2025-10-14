#include <iostream>
#include <cstdlib>
#include <ctime>

enum    enOperationsLevel    { EASY=1, MED, HARD, MIX };
enum    enOperationsType     { ADD=1, SUB, MUL, DIV, ALL };
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

stOperations initOperations(void)
{
    stOperations Ops;

    Ops.NumberOfQuestions = 0;
    Ops.WrongAnswers      = 0;
    Ops.RightAnswers      = 0;
    Ops.playAgain         = '\0';

    return (Ops);
}

short int getHowManyQuestionsUserWantToAnswer(void)
{
    short int NumberOfQuestions = 0;

    std::cout << "How many questions do you want to answer ? : ";
    std::cin >> NumberOfQuestions;

    return (NumberOfQuestions);
}

enOperationsLevel getUserQuestionsLevel(void)
{
    short int OperationsLevel;

    std::cout << "Enter Questions Level [1]->Easy [2]->Med [3]->Hard [4]->Mix : ";
    std::cin >> OperationsLevel;

    return ((enOperationsLevel)OperationsLevel);
}

enOperationsType getUserQuestionsType(void)
{
    short int OperationsType;

    std::cout << "Enter Questions Type [1]->Add [2]->Sub [3]->Mul [4]->Div : ";
    std::cin >> OperationsType;

    return ((enOperationsType)OperationsType);
}



int main(void)
{
    srand((unsigned int)time(NULL));
    return (0);
}
