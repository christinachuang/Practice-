//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "../Implement.h"
using namespace std;
void tryTestCase(ExpressionEval &inst, std::string testfile)
{
    std::ifstream ifs(testfile);
    if( !ifs.good() )
        throw "[Missing Test File]";

    // parse each case
    std::string infixStr, prefixStr, postfixStr, valueStr;
    while( std::getline(ifs, infixStr) )
    {
        std::getline(ifs, prefixStr);
        std::getline(ifs, postfixStr);
        std::getline(ifs, valueStr);

        // test data
        Expression infix = infixStr.c_str();
        Expression prefix = prefixStr.c_str();
        Expression postfix = postfixStr.c_str();
        int value = std::atoi( valueStr.c_str() );

        // generate your results
        Expression urprefix, urpostfix;
        inst.infix2Prefix( urprefix, infix );
        inst.infix2Postfix( urpostfix, infix );
        int valuePre  = inst.evalPrefix( prefix );
        int valuePost = inst.evalPostfix( postfix );

        // compare results
        bool prefixPass = prefix==urprefix;
        bool postfixPass = postfix==urpostfix;
        bool valuePass = value==valuePre && value==valuePost;
//        cout << "ANSWER: " <<postfix << endl;
        if( !prefixPass )
            throw "[Wrong Prefix]";

        if( !postfixPass )
            throw "[Wrong Postfix]";

        if( !valuePass )
            throw "[Wrong Evaluation]";
    }

    ifs.close();
}

int main(int argc, char *argv[])
{
    // do try other test files
    std::string testfile = argc==1 ? "1.in" : argv[1];

    try
    {
        Implement inst;
        tryTestCase( inst, testfile );
        std::cout << "[Accepted]" << std::endl;
    }
    catch(const char *e)
    {
        std::cout << e << std::endl;
    }

	return 0;
}
//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
