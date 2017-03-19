#include "Scanner.h"

Scanner::Scanner(std::string fileName)
{
    //toks[0];

    std::ifstream myfile(fileName);

    std::string line;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            std::cout << line << '\n';
        }
        myfile.close();
    }

    else
        std::cout << "Unable to open file";
}

void Scanner::printStuff()
{
    std::cout << fileToOpen << std::endl;
}
