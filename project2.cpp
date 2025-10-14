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

void textInColor(std::string txt, int color)
{
    std::cout << "\033[" << color << "m"; // setting the color code to console
    std::cout << txt << ' ';
    std::cout << "\033[0m";              // reseting the color console
    std::cout << std::endl;
}

short int getHowManyQuestionsUserWantToAnswer(void)
{
    short int NumberOfQuestions = 0;

    std::cout << "How many questions do you want to answer ? : ";
    std::cin >> NumberOfQuestions;

    return (NumberOfQuestions);
}

float getUserAnswer(void)
{
    float userAnswer;

    std::cin >> userAnswer;

    return (userAnswer);
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

    std::cout << "Enter Questions Type [1]->Add [2]->Sub [3]->Mul [4]->Div [5]->Mix : ";
    std::cin >> OperationsType;

    return ((enOperationsType)OperationsType);
}

stOperations initOperations(void)
{
    stOperations Ops;

    Ops.NumberOfQuestions = 0;
    Ops.WrongAnswers      = 0;
    Ops.RightAnswers      = 0;
    Ops.playAgain         = '\0';

    Ops.Level = getUserQuestionsLevel();
    Ops.Type  = getUserQuestionsType();
    Ops.NumberOfQuestions = getHowManyQuestionsUserWantToAnswer();

    return (Ops);
}

int getRandomNumberFromLevel(enOperationsLevel Level)
{
    switch (Level)
    {
        case (EASY) :
            return (randomNumber(1, 9));
        case (MED)  :
            return (randomNumber(10, 19));
        case (HARD) :
            return (randomNumber(20, 100));
        default     :
            return (randomNumber(1, 100));
    }
}

char getOperationSymbol(enOperationsType Type)
{
    char symbol[4] = { '+', '-', '*', '/' };

    switch (Type)
    {
        case (ADD) :
            return ('+');
        case (SUB) :
            return ('-');
        case (MUL) :
            return ('*');
        case (DIV) :
            return ('/');
        default    :
            return (symbol[randomNumber(0, 3)]);
    }
}

float getOperationResult(int Number1, int Number2, char Operation)
{
    switch (Operation)
    {
        case ('+') :
            return (Number1 + Number2);
        case ('-') :
            return (Number1 - Number2);
        case ('*') :
            return (Number1 * Number2);
        case ('/') :
            return (Number1 / (float)Number2);
        default    :
            return (0);
    }
}

void showSingleOperation(int Number1, int Number2, char OpType)
{
    std::cout << Number1 << '\n';
    std::cout << Number2 << ' ' << OpType << '\n';
    std::cout << "______\n";
}

int makeOperation(enOperationsLevel Level, enOperationsType Type)
{
    int Number1 = getRandomNumberFromLevel(Level);
    int Number2 = getRandomNumberFromLevel(Level);
    char OpType = getOperationSymbol(Type);

    showSingleOperation(Number1, Number2, OpType);

    return (getOperationResult(Number1, Number2, OpType));
}

bool userAnswerIsRight(float userAnswer, float rightAnswer)
{
    return (userAnswer == rightAnswer);
}

void playQuestion(stOperations &Operation)
{
    float rightAnswer= makeOperation(Operation.Level, Operation.Type);

    if (userAnswerIsRight(getUserAnswer(), rightAnswer))
    {
        std::cout << "Right Answer :)\n";
        Operation.RightAnswers++;
    }
    else
    {
        std::cout << "Wrong Answer :(\n";
        std::cout << "The right answer is : " << rightAnswer << '\n';
        Operation.WrongAnswers++;
    }
}

enOperationsResult getFinalResult(short int WrongAnswers, short int RightAnswers)
{
    if (WrongAnswers >= RightAnswers)
        return (enOperationsResult::PASS);
    else
        return (enOperationsResult::FAIL);
}

void showOperationsGameResults(stOperations Operations)
{
    std::string Result[2] = { "Fail :(", "PASS :)" };
    std::string Level[4]  = { "Easy", "Med", "Hard", "Mix" };
    std::string Type[5]   = { "+", "-", "*", "/", "Mix" };

    std::cout << "\n___________________________\n";
    std::cout << "\tFinal Result is : " << Result[Operations.FinalResult] << '\n';
    std::cout << "___________________________\n";
    std::cout << "Number of questions : " << Operations.NumberOfQuestions << '\n';
    std::cout << "Operations Level : " << Level[Operations.Level - 1] << '\n';
    std::cout << "Operations Type  : " << Type[Operations.Type - 1] << '\n';
    std::cout << "Number of Right Answers : " << Operations.RightAnswers << '\n';
    std::cout << "Number of Wrong Answers : " << Operations.WrongAnswers << '\n';
    std::cout << "___________________________\n\n";
}

// make the main game math monitor
void gameLoop(void)
{
    stOperations Operations = initOperations();

    for (int i = 0; i < Operations.NumberOfQuestions; i++)
    {
        std::cout << "Question [" << i << "]\n";
        playQuestion(Operations);
    }

    Operations.FinalResult = getFinalResult(Operations.WrongAnswers, Operations.RightAnswers);
    showOperationsGameResults(Operations);
}

int main(void)
{
    srand((unsigned int)time(NULL));
    gameLoop();

    return (0);
}
