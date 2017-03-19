
#include "Scanner.cpp"
#include "Token.cpp"

int main(int argc, char **argv)
{

    //std::cout << argv[1] << std::endl;
    
    Scanner *s = new Scanner(argv[1]);
    s->printStuff();
    Token *tok = new Token();
    tok->printToken();
    

    return 0;
}
