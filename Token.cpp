#include "Token.h"
#include "constants.h"

Token::Token(int t, std::string v, int ln)
{
    type = t;
    value = v;
    lineNum = ln;
}

void Token::printToken()
{
    std::cout << "Type: " << intToString(getType()) <<
    "\nValue: " << getValue() <<
    "\nLine Number: " << getLineNum() << std::endl;
}