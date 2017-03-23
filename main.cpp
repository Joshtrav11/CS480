#include <deque>
#include "Scanner.cpp"
#include "Token.cpp"
#include "constants.h"
#include "TreeNode.h"
#include "test.h"
#include "Checker.h"

int main(int argc, char **argv)
{
    
    Scanner *s = new Scanner(argv[1]);
    Token *current;
    int size = s->getTokenSize();

    std::deque<Token*> toks;

    for(int i = 0 ; i < size; i++) {
        //current = s->getTokenAndPrint();
        //toks->push_back(current);
        toks.push_back(s->getTokenAndPrint());
    }
    std::cout << "NEXT PHASE" << std::endl;
    /*
    std::deque<Token *>::const_iterator first = toks.begin() + 5;
    std::deque<Token *>::const_iterator last = toks.begin() + 10;
    std::deque<Token *> toks1(first, last);
    current = toks1.front();
    std::cout << toks1.size() << std::endl;
    toks1.pop_front();
    current = toks1.front();
    std::cout << toks1.size() << std::endl;
    toks1.pop_front();
    current = toks1.front();
    std::cout << toks1.size() << std::endl;
    */
    /*
    for(int i = 0; i < 4; i++) {
        toks1.push_back(toks.front());
        *current = toks.front();
        current->printToken();
        toks.pop_front();
    }
    */
    
    TreeNode *root = new TreeNode();
    root->nodeType = PROGRAM;
    root->createSubtree(toks);
    std::cout << "TREE CREATED" << std::endl;
    //root->createSubtree(yolo);
    Checker *check = new Checker(toks);
    std::cout << "CHECKER PASSED" << std::endl;
    

    return 0;
}
