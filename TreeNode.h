#ifndef TREENODE_FILE
#define TREENODE_FILE

//#include <string>
//#include <iostream>
#include <deque>
#include "constants.h"
#include "Token.h"

class TreeNode
{
  
public:
  int lineNumber;     //Line in program where this construct is found
  int nValue;         //Numerical value of a number
  std::string sValue; //Lexeme or string value of an identifier
  int nodeType;       //PROGRAM, DECLARATION, etc.
  int typeSpecifier;  //VOID or INT
  std::string rename; //Used by the Semantic Analyzer
  bool visited;       //Initialized to false, used for traversals
  TreeNode *C1;       //Pointer to Child 1
  TreeNode *C2;       //Pointer to Child 2
  TreeNode *C3;       //Pointer to Child 3
  TreeNode *sibling;  //Pointer to Sibling
  
public:
  void createSubtree(std::deque<Token*> &toks) {
    if (nodeType == PROGRAM)
    {
        createSiblingtree(toks);
    }
		else if (nodeType == COMPOUND)
    {
        C1 = new TreeNode();
        C1->nodeType = DECLARATION;
        {
            bool checkTrue = true;
            int index = 0;
            do
            {
                Token *t = toks.at(index);
                if (t->getType() == INT)
                {
                    index += 3;
                }
                else
                {
                    checkTrue = false;
                }
            } while (checkTrue);

            if (index > 0)
            {

                std::deque<Token *> toks1;
                for (int i = 0; i < index; i++)
                {
                    toks1.push_back(toks.front());
                    toks.pop_front();
                }
                C1->createSiblingtree(toks1);
            }
        }

        C2 = new TreeNode();
        C2->nodeType = STATEMENT_LIST;

        C2->createSiblingtree(toks);
    }
    else if (nodeType == PARAMETER_LIST)
    {

        if (nodeType == VOID)
        {
            //node.typeSpecifier = VOID;
        }
        else if (nodeType == INT)
        {
            createSiblingtree(toks);
        }
        else
        {
            std::cout << "Can't find the type specifier for node: " << typeSpecifier << std::endl;
            exit(1);
        }
    }
    else if (nodeType == STATEMENT_LIST)
    {
        createSiblingtree(toks);
    }
    else
    {
        std::cout << "Can't find the node type: " << nodeType << std::endl;
        exit(1);
    }
  } 
	void createSiblingtree(std::deque<Token*> &toks){
		;
	}
  
};
#endif