#ifndef SCANNER_FILE
#define SCANNER_FILE

#include <string>
#include <iostream>
#include <fstream>
#include "Token.h"

class Scanner
{
  private:
    std::string fileToOpen;
    Token toks[40];

  public:
    Scanner(std::string fileName);
    void printStuff();
};

#endif