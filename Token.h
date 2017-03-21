#ifndef TOKEN_FILE
#define TOKEN_FILE

#include <string>
#include <iostream>
#include <fstream>

class Token
{
  private:
    int type;
    std::string value;
    int lineNum;

  public:
    Token(int t, std::string v, int ln);
    void setType(int t) {type = t;}
    void setValue(std::string v) {value = v;}
    //void setLineNum(int ln) {lineNum = ln;}
    int getType() {return type;}
    std::string getValue() {return value;}
    int getLineNum() {return lineNum;}
    void printToken();
};

#endif
