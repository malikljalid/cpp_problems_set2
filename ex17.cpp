#include <iostream>

enum enASCII { A = 65, Z = 90 };

std::string readPassword(void)
{
    std::string Password;

    std::cout << "Please enter your 3 character Password (AAA ~ ZZZ): ";
    std::cin >> Password;

    return (Password);
}

bool guessPassword(std::string pswd)
{
    int Terials = 0;

    for (char i = A; i <= Z; i++)
    {
        for (char j = A; j <= Z; j++)
        {
            for (char k = A; k <= Z; k++)
            {
                Terials++;
                if (pswd[0] == i && pswd[1] == j && pswd[2] == k)
                {
                    std::cout << "Found after " << Terials << " Terials\n";
                    return (true);
                }
            }
        }
    }
    return (false);
}

void printPasswordGuessResult(std::string pswd, bool PasswordIsFound)
{
    if (PasswordIsFound)
        std::cout << "Your Password is : " << pswd << '\n';
    else
        std::cout << "Password DOES NOT exist!\n";
}

int main(void)
{
    std::string Password = readPassword();

    printPasswordGuessResult(Password, guessPassword(Password));
    return (0);
}
