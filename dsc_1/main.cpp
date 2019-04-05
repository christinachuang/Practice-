#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
    Stack s;
    s.top=0;
    s.Setsize();
    int i, m;
    while(cin >> s.input){
        for(i=0; s.input[i]!='\0' ; i++){
            s.infixtopostfix(s.input[i]);
        }
        if(s.top>0){
            for(i=s.top-1; i>=0; i--){
                for(m=19; m>=0; m--){
                    if(s.sign[m]=='\0' && s.sign[m-1]!='\0'){
                        s.sign[m]=s.words[i];
                    }
                }
            }
        }
//        cout << s.words << endl;
        cout << s.sign << endl;
        for(i=0; i<s.capacity; i++){
            s.words[i]={'\0'};
        }
        for(i=0; i<20 ; i++){
            s.sign[i]={'\0'};
        }

    }
    return 0;
}
