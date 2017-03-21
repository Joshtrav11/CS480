#ifndef SCANNER_FILE
#define SCANNER_FILE

#include <string>
#include <iostream>
#include <fstream>
#include "Token.h"
#include <deque>

class Scanner
{
private:
  std::string fileToOpen;
  std::deque<Token *> toks;

public:
  Scanner(std::string fileName);
  Token *stringToToken(std::string tokenString, int lineNum);
  Token *getToken();
  Token *getTokenAndPrint();
  int getTokenSize() { return toks.size();}
};

#endif