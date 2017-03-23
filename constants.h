#ifndef CONSTANTS_FILE
#define CONSTANTS_FILE
#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include "Token.h"

int findIndex(int value,std::deque<Token *> &toks);
//void subDeque (std::deque<Token *> &OGtoks, std::deque<Token *> &sideToks, int amount);

enum Constants
{
    EOF1,
    ERROR,
    ELSE,
    IF,
    INT,
    RETURN,
    VOID,
    WHILE,
    PLUS,
    MINUS,
    MULT,
    DIV,
    LS,
    LEQ,
    GT,
    GEQ,
    EQ,
    NEQ,
    ASSIGN,
    SEMI,
    COMMA,
    LPAREN,
    RPAREN,
    LBRACKET,
    RBRACKET,
    LBRACE,
    RBRACE,
    START_COMMENT,
    STOP_COMMENT,
    READ,
    WRITE,
    NUMBER,
    ID,
    PROGRAM,
    DECLARATION,
    VARIABLE,
    ARRAY,
    FUNCTION,
    EXPRESSION,
    CALL,
    COMPOUND,
    TYPE_SPECIFIER,
    PARAMETER_LIST,
    PARAMETER,
    STATEMENT_LIST,
    STATEMENT,
    ARGUMENTS
};

std::string intToString(int i)
{
    switch (i)
    {
    case 0:
    {
        return "EOF1";
    }
    case 1:
    {
        return "ERROR";
    }
    case 2:
    {
        return "ELSE";
    }
    case 3:
    {
        return "IF";
    }
    case 4:
    {
        return "INT";
    }
    case 5:
    {
        return "RETURN";
    }
    case 6:
    {
        return "VOID";
    }
    case 7:
    {
        return "WHILE";
    }
    case 8:
    {
        return "PLUS";
    }
    case 9:
    {
        return "MINUS";
    }
    case 10:
    {
        return "MULT";
    }
    case 11:
    {
        return "DIV";
    }
    case 12:
    {
        return "LS";
    }
    case 13:
    {
        return "LEQ";
    }
    case 14:
    {
        return "GT";
    }
    case 15:
    {
        return "GEQ";
    }
    case 16:
    {
        return "EQ";
    }
    case 17:
    {
        return "NEQ";
    }
    case 18:
    {
        return "ASSIGN";
    }
    case 19:
    {
        return "SEMI";
    }
    case 20:
    {
        return "COMMA";
    }
    case 21:
    {
        return "LPAREN";
    }
    case 22:
    {
        return "RPAREN";
    }
    case 23:
    {
        return "LBRACKET";
    }
    case 24:
    {
        return "RBRACKET";
    }
    case 25:
    {
        return "LBRACE";
    }
    case 26:
    {
        return "RBRACE";
    }
    case 27:
    {
        return "START_COMMENT";
    }
    case 28:
    {
        return "STOP_COMMENT";
    }
    case 29:
    {
        return "READ";
    }
    case 30:
    {
        return "WRITE";
    }
    case 31:
    {
        return "NUMBER";
    }
    case 32:
    {
        return "ID";
    }
    case 40:
    {
        return "PROGRAM";
    }
    case 41:
    {
        return "DECLARATION";
    }
    case 42:
    {
        return "VARIABLE";
    }
    case 43:
    {
        return "ARRAY";
    }
    case 44:
    {
        return "FUNCTION";
    }
    case 45:
    {
        return "EXPRESSION";
    }
    case 46:
    {
        return "CALL";
    }
    case 47:
    {
        return "COMPOUND";
    }
    case 48:
    {
        return "TYPE_SPECIFIER";
    }
    case 49:
    {
        return "PARAMETER_LIST";
    }
    case 50:
    {
        return "PARAMETER";
    }
    case 51:
    {
        return "STATEMENT_LIST";
    }
    case 52:
    {
        return "STATEMENT";
    }
    case 53:
    {
        return "ARGUMENTS";
    }
    default:
    {
        std::cout << i << " does not have an associated string" << std::endl;
    }
    }
    return "";
}
std::string trim(std::string &str)
{
    if (str != " " || !(str.compare("\t")))
    {
        size_t first = str.find_first_not_of(' ');
        size_t last = str.find_last_not_of(' ');

        str = str.substr(first, (last - first + 1));
        str.erase(std::remove(str.begin(), str.end(), '\t'), str.end());

        return str;
    }
    else
    {
        return "";
    }
}

bool hasEnding(std::string const &fullString, std::string const &ending)
{
    if (fullString.length() >= ending.length())
    {
        return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
    }
    else
    {
        return false;
    }
}
int findIndex(int value,std::deque<Token *> &toks){
    Token *current;
    for(int index = 0; index < toks.size(); index++ ) {
        current = toks.at(index);
        if(current->getType() == value) {
            return index;
        }
    }
    return -1;
}
void subDeque (std::deque<Token *> &OGtoks, std::deque<Token *> &sideToks, int amount) {
    for(int i = 0; i < amount; i++) {
        sideToks.push_back(OGtoks.front());
        OGtoks.pop_front();
    }
    return;
}
#endif