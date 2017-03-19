#ifndef TOKEN_FILE
#define TOKEN_FILE

#include <string>
#include <iostream>
#include <fstream>

class Token
{
  private:
    std::string type;
    std::string Id;
    int lineNum;
    int value;

  public:
    Token();
    void setType(std::string t) {type = t;}
    void setId(std::string i) {Id = i;}
    void setLineNum(int ln) {lineNum = ln;}
    void setValue(int v) {value = v;}
    std::string getType() {return type;}
    std::string getId() {return Id;}
    int getLineNum() {return lineNum;}
    int getValue() {return value;}
    void printToken();
};

#endif
