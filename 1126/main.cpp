#include <iostream>
#include "tree.h"
#include <stdlib.h>
#define MAX_SIZE 50000
using namespace std;
string treeStr;
int num, maxi=0;
Node* LookFor(Node* currentNode, Node* thisNode){
    if(currentNode){
        if(currentNode->left==thisNode){
            return currentNode;
        }
        else if(currentNode->right==thisNode){
            return currentNode;
        }
        else{
            Node* tmp;
            tmp = LookFor(currentNode->left, thisNode);
            if (tmp==NULL){
                return LookFor(currentNode->right, thisNode);
            }
            else
                return tmp;
        }
    }
    else
        return NULL;
}
void Print(Node* currentNode){
    if(currentNode){
        Print(currentNode->left);
        cout<< currentNode->weight << endl;
        Print(currentNode->right);
    }
}
int treeHeight(Node* root){
    if(root==NULL)
        return 0;
    cout << "------------------------------" << endl;
    cout <<"ROOT: "<< root->weight << endl;
    return (max(treeHeight(root->left), treeHeight(root->right))+1);
}
int treeWeight(const Node *root){
    if(root==NULL)
        return 0;
    int leftweight = treeWeight(root->left);
    int rightweight = treeWeight(root->right);
    return leftweight + rightweight + root->weight;
}
int leafNum(const Node *root){
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    int leftleaf = leafNum(root->left);
    int rightleaf= leafNum(root->right);
    return leftleaf + rightleaf;
}
int maxPathWeight(const Node *root){
    if(root==NULL)
        return 0;
    int leftpath= maxPathWeight(root->left);
    int rightpath= maxPathWeight(root->right);
    if(root->left==NULL){
        return rightpath + root->weight;
    }
    else if(root->right==NULL){
        return leftpath + root->weight;
    }
    else
        return max(leftpath, rightpath) + root->weight;
}
Node* deleteTree(Node *root){
    if(root==NULL){
        return NULL;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    root=NULL;
    delete root;
     if(root==NULL)
        cout << "SUCCESS" << endl;
    else
        cout << "FAIL" << endl;
    return NULL;
}
int main()
{
    cin >> treeStr;
    Node* root = new Node();
    int i=1;
    int control=2;
    int kcg = 1;
    Node* ptr=root;
    Node* now=root;
    char mid[MAX_SIZE];
    if (treeStr[0]=='(' && treeStr[1]==')'){
        kcg = 0;
        root = NULL;
    }
    while(treeStr[i] && kcg){
        cout << "------------------------------" << endl;
        cout << "i: " << i << "****************" << treeStr[i] << endl;
        //cout <<"Now: "<< now->weight <<  ";Ptr: " << ptr->weight << endl<< endl;
        cout << "CONTROL: "<< control << endl;
        if(treeStr[i]=='('){
            if(treeStr[i-1]==')' && treeStr[i+1]!=')'){
                ptr->right=new Node(NULL);
                if(control!=2){
                    now=ptr;
                    ptr=ptr->right;
                }
                else{
                    control=1;
//                    now=now;
                    ptr=ptr->right;
                }
                cout << "Moving To Right" << endl;
            }
            else if(treeStr[i-1]!=')'&& treeStr[i+1]!=')'){
                ptr->left=new Node(NULL);
                if(control!=2){
                    now=ptr;
                    ptr=ptr->left;
                }
                else{
                    control=1;
//                    now=now;
                    ptr=ptr->left;
                }
                cout << "Moving To Left" <<endl;
            }
        }
        else if(treeStr[i]==')'){
            if(treeStr[i-1]!='('){
                ptr=now;
                if(ptr!=root){
                    now=LookFor(root, ptr);
                }
                else{
                    now=root;
                    control=2;
                }
                cout << "No Sutree Here ";
                cout << ptr->weight << endl;
            }
        }
        else{
            int k=i;
            for(int j=0; mid[j]!='\0'; j++)
                mid[j]='\0';
            while(treeStr[i]!='(' && treeStr[i]!=')'){
                cout << i<< " " << treeStr[i] <<"~~~~~~" << endl;
                mid[i-k]=treeStr[i];
                if(treeStr[i+1]!='(' && treeStr[i+1]!=')'){
                    i++;
//                    cout << i << endl;
                }
                else{
                    break;
                }
            }
            ptr->weight=atoi(mid);
            cout << "NODE: " << ptr->weight << endl;
        }
        i++;
    }
    cout << "Find The Height " << endl;
    cout << treeHeight(root) << endl;
    cout << "Sum The Weight: " << endl;
    cout << treeWeight(root)<< endl;
    cout << "Leaf Numbers: " << endl;
    cout << leafNum(root) << endl;
    cout << "MaxPathWeight: " << endl;
    cout << maxPathWeight(root) << endl;
    deleteTree(root);
    cout << "DELETE!" << endl;
    if(root==NULL)
        cout << "SUCCESS" << endl;
    else{
        cout << root->weight << endl;
        cout << "FAIL" << endl;
    }
    return 0;
}
