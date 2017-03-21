#include "Scanner.h"
#include "constants.h"
#include <regex>

Scanner::Scanner(std::string fileName)
{
    //toks[0];
    bool ignoreComment = false;

    std::ifstream myfile(fileName);

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
            //std::cout << line << std::endl;

            while (line[i] != '\0')
            {
                c = line[i];
                word = word + c;
                //std::cout << "~" << word << "~" << std::endl;
                if (!ignoreComment)
                {

                    if (c == " " || c == "\t")
                    {
                        word = trim(word);

                        if (word != "")
                        {
                            current = stringToToken(word, j);
                            //current->printToken();
                            toks.push_back(current);
                            word = "";
                        }
                    }

                    else if (c == ";")
                    {
                        word = word.substr(0, word.length() - 1);
                        if (!word.empty())
                        {
                            current = stringToToken(word, j);
                            //current->printToken();
                            toks.push_back(current);
                        }
                        else
                        {
                            std::cout << "tokenString is empty" << std::endl;
                        }
                        word = "";
                        word += c;
                        current = stringToToken(word, j);
                        //current->printToken();
                        toks.push_back(current);
                        word = "";
                    }

                    else if (c == "[")
                    {
                        if (!(word == "["))
                        {
                            current = stringToToken(word.substr(0, word.length() - 1), j);
                            //current->printToken();
                            toks.push_back(current);
                            word = "[";
                        }
                        current = stringToToken(word, j);
                        //std::cout << "~" << word << "~" << std::endl;
                        //current->printToken();
                        toks.push_back(current);
                        word = "";
                    }
                    else if (c == "(")
                    {
                        if (!(word == "("))
                        {
                            current = stringToToken(word.substr(0, word.length() - 1), j);
                            //current->printToken();
                            toks.push_back(current);
                            word = "(";
                        }
                        current = stringToToken(word, j);
                        //std::cout << "~" << word << "~" << std::endl;
                        //current->printToken();
                        toks.push_back(current);
                        word = "";
                    }
                    else if (c == ")")
                    {
                        if (!(word == ")"))
                        {
                            current = stringToToken(word.substr(0, word.length() - 1), j);
                            //current->printToken();
                            toks.push_back(current);
                            word = ")";
                        }
                        current = stringToToken(word, j);
                        //std::cout << "~" << word << "~" << std::endl;
                        //current->printToken();
                        toks.push_back(current);
                        word = "";
                    }
                    else if (c == ",")
                    {
                        if (!(word == ","))
                        {
                            current = stringToToken(word.substr(0, word.length() - 1), j);
                            //current->printToken();
                            toks.push_back(current);
                            word = ",";
                        }
                        current = stringToToken(word, j);
                        //std::cout << "~" << word << "~" << std::endl;
                        //current->printToken();
                        toks.push_back(current);
                        word = "";
                    }
                    else if (c == "=")
                    {
                        if (!(word == "="))
                        {
                            current = stringToToken(word.substr(0, word.length() - 1), j);
                            //current->printToken();
                            toks.push_back(current);
                            word = "=";
                        }
                        current = stringToToken(word, j);
                        //std::cout << "~" << word << "~" << std::endl;
                        //current->printToken();
                        toks.push_back(current);
                        word = "";
                    }

                    else if (c == "*" && word.compare(0, 2, "/*") == 0)
                    {
                        ignoreComment = true;
                    }
                }
                else if (hasEnding(word, "*/"))
                {
                    ignoreComment = false;
                    word = "";
                }
                i++;
            }
            if (!ignoreComment && !word.empty())
            {
                //std::cout << "~" << word << "~" << std::endl;
                current = stringToToken(word, j);
                //current->printToken();
                toks.push_back(current);
                word = "";
            }
            j++;
        }
        myfile.close();
    }

    else
        std::cout << "Unable to open file";
}

Token *Scanner::stringToToken(std::string tokenString, int lineNum)
{
    Token *result = new Token(ERROR, "error", lineNum);

    if (std::regex_match(tokenString, std::regex("[+-]?(?=[.]?[0-9])[0-9]*(?:[.][0-9]*)?(?:[Ee][+-]?[0-9]+)?")))
    { //if it's a number
        return result = new Token(NUMBER, tokenString, lineNum);
    }
    else if (tokenString == "")
    {
        result = NULL;
        return result;
    }
    else if (tokenString == "else")
    {
        result = new Token(ELSE, tokenString, lineNum);
        return result;
    }
    else if (tokenString == "if")
    {
        result = new Token(IF, tokenString, lineNum);
        return result;
    }
    else if (tokenString == "int")
    {
        result = new Token(INT, tokenString, lineNum);
        return result;
    }
    else if (tokenString == "return")
    {
        result = new Token(RETURN, tokenString, lineNum);
        return result;
    }
    else if (tokenString == "void")
    {
        result = new Token(VOID, tokenString, lineNum);
        return result;
    }
    else if (tokenString == "while")
    {
        result = new Token(WHILE, tokenString, lineNum);
        return result;
    }
    else if (tokenString == "+")
    {
        result = new Token(PLUS, tokenString, lineNum);
        return result;
    }
    else if (tokenString == "-")
    {
        result = new Token(MINUS, tokenString, lineNum);
        return result;
    }
    else if (tokenString == "*")
    {
        result = new Token(MULT, tokenString, lineNum);
        return result;
    }
    else if (tokenString == "/")
    {
        result = new Token(DIV, tokenString, lineNum);
        return result;
    }
    else if (tokenString == "<")
    {
        result = new Token(LS, tokenString, lineNum);
        return result;
    }
    else if (tokenString == "<=")
    {
        result = new Token(LEQ, tokenString, lineNum);
        return result;
    }
    else if (tokenString == ">")
    {
        result = new Token(GT, tokenString, lineNum);
        return result;
    }
    else if (tokenString == "==")
    {
        result = new Token(EQ, tokenString, lineNum);
        return result;
    }
    else if (tokenString == "!=")
    {
        result = new Token(NEQ, tokenString, lineNum);
        return result;
    }
    else if (tokenString == "=")
    {
        result = new Token(ASSIGN, tokenString, lineNum);
        return result;
    }
    else if (tokenString == ";")
    {
        result = new Token(SEMI, tokenString, lineNum);
        return result;
    }
    else if (tokenString == ",")
    {
        result = new Token(COMMA, tokenString, lineNum);
        return result;
    }
    else if (tokenString == "(")
    {
        result = new Token(LPAREN, tokenString, lineNum);
        return result;
    }
    else if (tokenString == ")")
    {
        result = new Token(RPAREN, tokenString, lineNum);
        return result;
    }
    else if (tokenString == "[")
    {
        result = new Token(LBRACKET, tokenString, lineNum);
        return result;
    }
    else if (tokenString == "]")
    {
        result = new Token(RBRACKET, tokenString, lineNum);
        return result;
    }
    else if (tokenString == "{")
    {
        result = new Token(LBRACE, tokenString, lineNum);
        return result;
    }
    else if (tokenString == "}")
    {
        result = new Token(RBRACE, tokenString, lineNum);
        return result;
    }
    else if (tokenString == "/*")
    {
        result = new Token(START_COMMENT, tokenString, lineNum);
        return result;
    }
    else if (tokenString == "*/")
    {
        result = new Token(STOP_COMMENT, tokenString, lineNum);
        return result;
    }
    else if (tokenString == "read")
    {
        result = new Token(READ, tokenString, lineNum);
        return result;
    }
    else if (tokenString == "write")
    {
        result = new Token(WRITE, tokenString, lineNum);
        return result;
    }
    else
    {
        result = new Token(ID, tokenString, lineNum);
        return result;
    }

    return result;
}

Token *Scanner::getToken()
{
    Token *t;
    if (toks.size() != 0)
    {
        t = toks.front();
        toks.pop_front();
    }
    else
    {
        t = new Token(EOF1, "", -1);
    }

    return t;
}

Token *Scanner::getTokenAndPrint()
{
    Token *t;
    t = getToken();
    if (t->getType() != EOF1)
    {
        t->printToken();
    }

    return t;
}
