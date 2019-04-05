#ifndef Implement_H
#define Implement_H

#include "readonly/Chain.h"

class Implement : public Chain
{
public:
    // add your code here
    //------------------------------------------------------

    void InsertBack(int data);
	//...
    void InsertAfter(int data1, int data2);
    void Delete(int data);
    void Reverse();


    //------------------------------------------------------
};

#endif
