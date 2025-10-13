#include <iostream>
#include <cstdlib>
#include <ctime>

enum enRoundChoice      { SCISSOR=1, STONE, PAPER };
enum enRoundStatus      { WON, LOST, DRAW };
enum enRoundWinner      { PLAYER1, COMPUTER, NOBODY };
enum enColors           { RED=31, GREEN=32, YELLOW=33 };

struct stPlayer
{
    enRoundChoice   Choice;
    enRoundStatus   Status;
    short int       Wins;
    short int       Draws;
};

struct stGame
{
    char            Repeat;
    short int       Rounds;
    stPlayer        Player1;
    stPlayer        Computer;
    enRoundWinner   RoundWinner;
    enRoundWinner   FinalWinner;
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

short int getRoundsNumber(void)
{
    short int Rounds = -1;

    while (Rounds < 0)
    {
        std::cout << "How many rounds you wanna play ? : ";
        std::cin >> Rounds;
    }
    return (Rounds);
}

void initPlayer(stPlayer &Player)
{
    Player.Draws = 0;
    Player.Wins  = 0;
}

stGame initGame(void)
{
    stGame Game;

    initPlayer(Game.Player1);
    initPlayer(Game.Computer);
    Game.Rounds = getRoundsNumber();
    Game.Repeat = '\0';

    return (Game);
}

enRoundChoice getPlayerChoice(void)
{
    short int userChoice = 0;

    do
    {
        std::cout << "What's your choice from [1]-> Scissor [2]-> Stone [3]-> Paper  ? : ";
        std::cin  >> userChoice;
    }
    while (userChoice != 1 && userChoice != 2 && userChoice != 3);

    return ((enRoundChoice)userChoice);
}

enRoundChoice getComputerChoice(void)
{
    return ((enRoundChoice)randomNumber(1, 3));
}

enRoundWinner getRoundWinner(enRoundStatus Player1)
{
    switch (Player1) 
    {
        case (WON)  :
            return (enRoundWinner::PLAYER1);
        case (LOST) :
            return (enRoundWinner::COMPUTER);
        default     :
            return (enRoundWinner::NOBODY);
    }
}

enRoundStatus getPlayerStatus(enRoundChoice Player1, enRoundChoice Player2)
{
    if (Player1 == Player2)
        return (enRoundStatus::DRAW);

    if ((Player1 == SCISSOR && Player2 == PAPER)   ||
        (Player1 == STONE   && Player2 == SCISSOR) ||
        (Player1 == PAPER   && Player2 == STONE))
        return (enRoundStatus::WON);
    
    return (enRoundStatus::LOST);
}

enRoundWinner getGameFinalWinner(stGame &Game)
{
    if (Game.Player1.Wins > Game.Computer.Wins)
        return (enRoundWinner::PLAYER1);
    else if (Game.Player1.Wins < Game.Computer.Wins)
        return (enRoundWinner::COMPUTER);
    else
        return (enRoundWinner::NOBODY);
}

void fillPlayersStats(stGame &Round)
{
    if (Round.RoundWinner == PLAYER1)
        Round.Player1.Wins++;
    if (Round.RoundWinner == COMPUTER)
        Round.Computer.Wins++;
    if (Round.RoundWinner == NOBODY)
    {
        Round.Player1.Draws++;
        Round.Computer.Draws++;
    }
}

void playGame(stGame &Round)
{

    Round.Player1.Choice    = getPlayerChoice();  
    Round.Computer.Choice   = getComputerChoice();

    Round.Player1.Status    = getPlayerStatus(Round.Player1.Choice, Round.Computer.Choice);
    Round.Computer.Status   = getPlayerStatus(Round.Computer.Choice, Round.Player1.Choice);

    Round.RoundWinner       = getRoundWinner(Round.Player1.Status);

    fillPlayersStats(Round);
}

void showRoundResults(stGame Game, short int RoundNumber)
{
    std::string Option[3] = { "SCISSOR", "STONE", "PAPER" };
    std::string Player[3] = { "PLAYER 1", "COMPUTER", "NO WINNER" };
    enColors    Color[3]  = { GREEN, RED, YELLOW };

    std::cout << "\n\n_________Round[" << RoundNumber << "]___________\n";
    std::cout << "Player1  choice : " << Option[Game.Player1.Choice - 1] << '\n';
    std::cout << "Computer choice : " << Option[Game.Computer.Choice - 1] << '\n';
    std::cout << "Round Winner    : ";
    textInColor("[" + Player[Game.RoundWinner] + "]", Color[Game.RoundWinner]);
    std::cout << "____________________________\n\n\n";
}

char showGameResults(stGame Game)
{
    std::string Player[3] = { "PLAYER 1", "COMPUTER", "NO WINNER" };
    enColors    Color[3]  = { GREEN, RED, YELLOW };

    std::cout << "\n\t______________________________________________\n";
    std::cout << "\t            +++ GAME OVER +++ \n";
    std::cout << "\t______________________________________________\n";
    std::cout << "\t_____________ [Game Results] _________________\n";
    std::cout << "\t Game Rounds        : " << Game.Rounds << '\n';
    std::cout << "\t Player1 Won Times  : " << Game.Player1.Wins  << '\n';
    std::cout << "\t Computer Won Times : " << Game.Computer.Wins << '\n';
    std::cout << "\t Draw Times         : " << Game.Player1.Draws << '\n';
    std::cout << "\t Final Winner       : ";
    textInColor(Player[Game.FinalWinner], Color[Game.FinalWinner] );
    std::cout << "\t______________________________________________\n";

    while (Game.Repeat != 'y' && Game.Repeat != 'n')
    {
        std::cout << "\t Do you want to play again ? (Yes[y] / No[n]) : ";
        std::cin >> Game.Repeat;
    }
    return (Game.Repeat);
}

char gameLoop(stGame Game)
{
    for (short int i = 0; i < Game.Rounds; i++)
    {
        playGame(Game);
        showRoundResults(Game, i);
    }

    Game.FinalWinner = getGameFinalWinner(Game);
    return (showGameResults(Game));
}

int main(void)
{
    srand((unsigned int)time(NULL));

    while (gameLoop(initGame()) == 'y') { }

    return (0);
}
//