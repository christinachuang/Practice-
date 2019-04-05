#include <iostream>
#include <stdlib.h>
#include "tree.h"
using namespace std;
//extern int h=0;

template < class T>
void Tree<T>::Inorder(TreeNode<T>* currentNode){
    if(currentNode){
        Inorder(currentNode->leftchild);
        cout << currentNode->data << " ";
        Inorder(currentNode->rightchild);
    }
}
/*template <class T>
void Tree<T>::Height(TreeNode<T>* currentNode,int maxi){
    h++;
    if(h>maxi){
        maxi=h;
        cout << maxi << endl;
    }
    if(currentNode->leftchild){
        Height(currentNode->leftchild, maxi);
    }
    if(currentNode->rightchild){
        Height(currentNode->rightchild, maxi);
    }
}
*/
char input[100], mid[100], path[100];
int num;
int main()
{
    Tree<int> total;
    total.root= new TreeNode<int>(0);
    int j;
    while(cin >> input){
        int i;
        if(input[0]=='(' && input[1]==')'){
            cout << input << endl;
            total.Inorder(total.root);
//            total.Height(total.root, 0);
        }
        for(i=0; input[i]; i++){
            if(input[i]==','){
                for(j=1; j<i; j++){
                    mid[j-1]=input[j];
                }
                num=atoi(mid);
                for(int i =0;i<100;i++)
                    mid[i]=0;
                break;
            }
        }
        int a=i;
        while(input[i]){
            if(input[i]==')'){
                for(j=a+1; j<i; j++){
                    path[j-a-1]=input[j];
                }
            }
            i++;
        }
        /* ©î¸Ñ§¹²¦ */
        int k=0;
        TreeNode<int>* now= total.root;

        while(path[k]){
            if(path[k]=='L'){
                if(now->leftchild==NULL)
                    now->leftchild = new TreeNode<int>(0);
                now = now->leftchild;
                cout << "left" << endl;
            }
            else if(path[k]=='R'){
                if(now->rightchild == NULL){

                 TreeNode<int>* yo = new TreeNode<int>(2);
                   cout<<"to"<<endl;
                    now->rightchild =yo;
                }
                now=now->rightchild;
                cout << "right" << endl;
            }
            k++;
        }

        now->data=num;
        cout<< now->data<<endl;
        for(int i=0;i<100;i++)
            path[i]='/0';
    }
    return 0;
}
