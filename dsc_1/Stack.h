#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
using namespace std;
class Stack
{
public:
    void Push(const int item){
        int p;
        if(top==capacity-1)
            Setsize();
        if(item==')')
            prior[top]=0;
        words[top]=item;
        top++;
    };
    void Pop(){
        int k;
        int control=0;
        if(IsEmpty()) throw "Stack is empty. Cannot delete.";
        for(k=0; k<20; k++){
            if(sign[k]=='\0' && control==0 && words[top-1]!=')'){
                sign[k]= words[top-1];
                control=1;
            }
        }
        top--;
    };
    void Setsize(){
        int y;
        if(IsEmpty())
            words = new char[20];
        else{
            capacity+=10;
            newone = new char[capacity];
            for(y=0; y<capacity; y++){
                newone[y]=words[y];
            }
            delete[] words;
            words= newone;
        }
    };
    int IsEmpty() const{
        if(top==0)
            return 1;
        else
            return 0;
    };
    void infixtopostfix(const char number){
        int signal=0;
        int j, d;
        if(number=='+'||number=='-'){
            priority=1;
                while(top-1 >=0 && priority <= prior[top-1]){
                        Pop();
                }
            Push(number);
            prior[top-1]=priority;
        }
        else if(number=='('){
            priority=3;
                while(top-1 >=0 && priority <= prior[top-1]){
                    Pop();
                }
            Push(number);
//            prior[top-1]=priority;
        }
        else if(number=='*'||number=='/'){
            priority=2;
                while(top-1 >=0 && priority <= prior[top-1]){
                    Pop();
                }
            Push(number);
            prior[top-1]=priority;
        }
        else if(number==')'){
            for(j=top-1; words[j]!='('; j--){
                signal=0;
                Pop();
            }
            Pop();
        }
        else{ //number is an operand
            signal=0;
            for(j=0; j<20; j++){
                if(sign[j]=='\0' && signal==0){
                    sign[j]=number;
                    signal=1;
                }
            }
        }
};
    /* InfixToPrefix */
void infixtoprefix(const char number){
        int signal=0;
        int j, d;
        if(number=='+'||number=='-'){
            priority=1;
                while(top-1 >=0 && priority <= prior[top-1]){
                        Pop();
                }
            Push(number);
            prior[top-1]=priority;
        }
        else if(number==')'){
            priority=3;
                while(top-1 >=0 && priority <= prior[top-1]){
                    Pop();
                }
            Push(number);
//            prior[top-1]=priority;
        }
        else if(number=='*'||number=='/'){
            priority=2;
                while(top-1 >=0 && priority <= prior[top-1]){
                    Pop();
                }
            Push(number);
            prior[top-1]=priority;
        }
        else if(number=='('){
            for(j=top-1; words[j]!=')'; j--){
                signal=0;
                Pop();
            }
            Pop();
        }
        else{ //number is an operand
            signal=0;
            for(j=0; j<20; j++){
                if(sign[j]=='\0' && signal==0){
                    sign[j]=number;
                    signal=1;
                }
            }
        }
        cout << "Sign:";
        cout << sign << endl;
        cout << "Words:";
        cout << words << endl;
};

    int priority;
    int top;
    char* words;
    char* newone;
    char sign[20] = {'\0'};
    int prior[20]={'\0'};
    string input;
    int capacity=20;
    /* Evaluate */
/*    int evaluate(){
        for(i=0; step[i]!='\0'; i++){
            if(step[i]!='+'||step[i]!='-'||step[i]!='*'||step[i]!='/'){
                Push(step[i]);
            }
            else //step[i]==operator
                Pop();
                Pop();
                if()
        }
}
    string in;
    int a, b, operate;
*/
};

#endif // STACK_H_INCLUDED
