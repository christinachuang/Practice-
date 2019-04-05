//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
#ifndef Expression_h
#define Expression_h

#include <iostream>
#include <cstring>
#include <cassert>
#include <ostream>

//The data structure that stores the expression.
class Expression
{
public:
    //the size of the expression
    unsigned sz;
    
    //char array that stores the expression
    char *data;
    
    //constructors and destructor
    Expression();
    Expression( const char *e );
    ~Expression();
    
    //assignment operator with respect to a cstring
    // all chars are copied to data except the end of cstring, \0.
    Expression& operator=( const char *e );
    
    //comparison operator between two expressions
    bool operator==( const Expression &e );
    
    //erase data
    void clear();
    
    //resize the space of data
    void resize(unsigned sz);
    
    //print the expression
    friend std::ostream& operator<<( std::ostream &os, const Expression &e );
};

#endif
//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
