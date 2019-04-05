//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
#include "Expression.h"

Expression::Expression() : sz(0)
{

}

Expression::Expression(const char *e) : Expression()
{
    *this = e;
}

Expression::~Expression()
{
    this->clear();
}

Expression& Expression::operator=( const char *e )
{
    this->clear();
    this->sz = (unsigned) std::strlen(e);
    this->data = new char[ this->sz ];
    std::memcpy( this->data, e, this->sz*sizeof(char) );
    
    return *this;
}

bool Expression::operator==( const Expression &e )
{
    if( e.sz != this->sz )
        return false;
    
    if( 0!=strncmp( e.data, this->data, e.sz ) )
        return false;
    
    return true;
}

void Expression::clear()
{
    if( this->sz == 0 )
        return;
    
    delete [] this->data;
    this->sz = 0;
}

void Expression::resize( unsigned sz )
{
    assert( sz>0 );
    
    char *data = new char[ sz ];
    std::memcpy( data, this->data, std::min(sz, this->sz)*sizeof(char) );
    this->clear();
    
    this->data = data;
    this->sz = sz;
}

std::ostream& operator<<( std::ostream &os, const Expression &e )
{
    for(int i=0;i<e.sz;i++)
        std::cout << e.data[i];
    return os;
}
//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
