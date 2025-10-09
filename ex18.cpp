#include <iostream>

enum enEncryptionKey { ENCRYPTION_KEY = 2 };

std::string readText(void)
{
    std::string Txt;

    std::cout << "Please enter a Text : ";
    std::getline(std::cin, Txt);

    return (Txt);
}

std::string encryptText(std::string Txt)
{
    for (int i = 0; i < Txt.length(); i++)
    {
        Txt[i] += ENCRYPTION_KEY;
    }
    return (Txt);
}

std::string decryptText(std::string Txt)
{
    for (int i = 0; i < Txt.length(); i++)
    {
        Txt[i] -= ENCRYPTION_KEY;
    }
    return (Txt);
}

int main(void)
{
    std::string Text            = readText();
    std::string encryptedText   = encryptText(Text);

    std::cout << "Text Before Encryption : " << Text << "\n";
    std::cout << "Text After  Encryption : " << encryptedText << "\n";
    std::cout << "Text After  Decryption : " << decryptText(encryptedText) << "\n";

    return (0);
}
