#include <iostream>
#include <cstdlib>
#include <ctime>

enum enMaxRounds        { MAXROUNDS = 10 };
enum enRoundChoice      { SCISSOR, STONE, PAPER };
enum enRoundStatus      { WON, LOST, DRAW };
enum enRoundWinner      { PLAYER1, COMPUTER, NOBODY };
enum enColors           { RED, GREEN, YELLOW };

struct stPlayer
{
    enRoundChoice   Choice;
    enRoundStatus   Status;
    short int       Wins;
    short int       Draws;
};

// struct stRound
// {
//     // short int       Number;
//     // stPlayer        Player1;
//     // stPlayer        Computer;
//     enRoundWinner   Winner;
// };

struct stGame
{
    short int       Rounds;
    // stRound         Game[MAXROUNDS];
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
    short int Rounds;

    std::cout << "How many rounds you wanna play ? : ";
    std::cin >> Rounds;

    return (Rounds);
}

enRoundChoice getPlayerChoice(void)
{
    short int userChoice;

    std::cout << "What's your choice from [1]-> Scissor [2]-> Stone [3]-> Paper  ? : ";
    std::cin  >> userChoice;

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

void fillPlayerRoundStats(enRoundWinner Winner, stPlayer &Player1)
{
    if (Winner == PLAYER1)
    {
        Player1.Status = enRoundStatus::WON;
        std::cout << "wiiins of player 1 : " << Player1.Wins << std::endl;
        Player1.Wins++;
        std::cout << "wiiins of player 1 : " << Player1.Wins << std::endl;

    }

    if (Winner == NOBODY)
        Player1.Draws++;
}

void fillComputerRoundStats(enRoundWinner Winner, stPlayer &Computer)
{
    if (Winner == COMPUTER)
    {
        Computer.Status = enRoundStatus::WON;
        Computer.Wins++;
    }

    if (Winner == NOBODY)
        Computer.Draws++;
}

void initPlayer(stPlayer &Player)
{
    Player.Draws = 0;
    Player.Wins  = 0;
}

void playGame(stRound &Round)
{
    initPlayer(Round.Player1);
    initPlayer(Round.Computer);

    Round.Player1.Choice    = getPlayerChoice();  
    Round.Computer.Choice   = getComputerChoice();
    Round.Player1.Status    = getPlayerStatus(Round.Player1.Choice, Round.Computer.Choice);
    Round.Computer.Status   = getPlayerStatus(Round.Computer.Choice, Round.Player1.Choice);
    Round.Winner            = getRoundWinner(Round.Player1.Status);

    fillPlayerRoundStats(Round.Winner, Round.Player1);
    fillPlayerRoundStats(Round.Winner, Round.Computer);

}

void fillPlayersGameStats(stGame &Game, short int RoundIndex)
{
    std::cout << "\n\n maybe here : " << Game.Round[RoundIndex].Player1.Wins << std::endl;

    Game.Player1.Wins   += Game.Round[RoundIndex].Player1.Wins;
    Game.Computer.Wins  += Game.Round[RoundIndex].Computer.Wins;
    Game.Player1.Draws  += Game.Round[RoundIndex].Computer.Draws;

    if (Game.Player1.Wins > Game.Computer.Wins)
        Game.FinalWinner = enRoundWinner::PLAYER1;
    else if (Game.Player1.Wins < Game.Computer.Wins)
        Game.FinalWinner = enRoundWinner::COMPUTER;
    else
        Game.FinalWinner = enRoundWinner::NOBODY;
}

void showRoundResults(stGame Game, short int RoundNumber)
{
    std::cout << "_________Round[" << RoundNumber << "]___________\n";
    std::cout << "Player1  choice : " << Game.Player1.Choice << '\n';
    std::cout << "Computer choice : " << Game.Computer.Choice << '\n';
    std::cout << "Round Winner    : [" << Game.RoundWinner << "]\n";
    std::cout << "_________________________________________________\n";
}

void showGameResults(stGame Game)
{
    std::cout << "\t\t\t_____________________________________________";
    std::cout << "\t\t\t            +++ GAME OVER +++ \n";
    std::cout << "\t\t\t___________________________________\n";
    std::cout << "\t\t\t_____________ [Game Results] ______________\n";
    std::cout << "\t\t\t Game Rounds        : " << Game.Rounds << '\n';
    std::cout << "\t\t\t Player1 Won Times  : " << Game.Player1.Wins  << '\n';
    std::cout << "\t\t\t Computer Won Times : " << Game.Computer.Wins << '\n';
    std::cout << "\t\t\t Draw Times         : " << Game.Player1.Draws << '\n';
    std::cout << "\t\t\t Final Winner       : " << Game.FinalWinner << '\n';
}

void gameLoop(void)
{
    stGame      Game;

    Game.Rounds = getRoundsNumber();
    for (short int i = 0; i < Game.Rounds; i++)
    {
        playGame(Game.Round[i]);
        fillPlayersGameStats(Game, i);
        showRoundResults(Game.Round[i], i);
    }
    showGameResults(Game);
}

int main(void)
{
    srand((unsigned int)time(NULL));

    gameLoop();

    return (0);
}
