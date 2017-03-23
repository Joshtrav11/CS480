#ifndef CHECKER_FILE
#define CHECKER_FILE
#include <deque>
#include "constants.h"
#include "Token.h"
#include "TreeNode.h"

class Checker
{
public:
std::string ID;
int entryType;
int dataType;
int blackLevel;
TreeNode *parameterList;
int returnType;
int arrayMax;
std::string rename;

Checker(std::deque<Token*> &toks) 
{
    bool ignoreComment = false;

    std::ifstream myfile("text.cm");

    std::string line;
    std::string word;
    std::string c;
    Token *current;
    int i = 0, j = 0;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            word = "";
            i = 0;
            while (line[i] != '\0')
            {
                c = line[i];
                if((c != " " || c != "\t") & !(toks.empty())) {
                    toks.pop_front();
                }
                i++;
            }
        }
        myfile.close();
    }
    else
    {
        std::cout << "Unable to open file";
    }
}
};
#endif