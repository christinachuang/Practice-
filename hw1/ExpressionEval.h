//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
#ifndef ExpressionEval_h
#define ExpressionEval_h

#include "Expression.h"

//Expression Evaluation
//It contains the functions that you have to override in implement.h/.cpp.
class ExpressionEval
{
public:
    //----------------------------------------------------------------------
    // convert the input infix expression to prefix one
    //----------------------------------------------------------------------
    virtual void infix2Prefix(Expression &prefix, const Expression &infix);

    //----------------------------------------------------------------------
    // convert the input infix expression to postfix one
    //----------------------------------------------------------------------
    virtual void infix2Postfix(Expression &postfix, const Expression &infix);
    
    //----------------------------------------------------------------------
    // evaluate the input prefix expression
    //----------------------------------------------------------------------
    virtual int evalPrefix(const Expression &prefix);
    
    //----------------------------------------------------------------------
    // evaluate the input postfix expression
    //----------------------------------------------------------------------
    virtual int evalPostfix(const Expression &postfix);
};

#endif
//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
