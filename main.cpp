
#include "Scanner.cpp"
#include "Token.cpp"
#include "constants.h"
#include <deque>

int main(int argc, char **argv)
{
    
    Scanner *s = new Scanner(argv[1]);
    Token *current;
    int size = s->getTokenSize();

    for(int i = 0 ; i < size; i++) {
        current = s->getTokenAndPrint();
    } 

    return 0;
}
