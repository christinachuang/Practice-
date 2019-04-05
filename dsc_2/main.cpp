#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
    Stack s;
    s.Setsize();
    int i, m,top;
    top=0;
    while(cin >> s.input){
        for(i=0; i<capacity ; i++){
            if(s.input[i]=='+'||s.input[i]=='-'||s.input[i]=='*'||s.input[i]=='/'){
                s.input[i-1]=ope(s.input[i], input[i], input[i-1]);

            }
        }

}
