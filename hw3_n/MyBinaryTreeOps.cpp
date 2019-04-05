#include "MyBinaryTreeOps.h"

#include <iostream>

using namespace std;


Node* MyBinaryTreeOps::constructTree(Node *root, std::string treeStr)const
{
    Node* cur = root;
    Node* pre = 0;
    char order;
    int i;
    for(i=0;i<treeStr.size();i++){
            cout << "i: " << treeStr[i] << endl;
        order = treeStr[i];
            if(i==0){
                root = new Node(order);
                cur = root;
            }
        else{
            if(order == '('){
                if(treeStr[i+1] == ')'){
                    cur->left = NULL;
                }
                else if(treeStr[i-1] == ')'){
                    cur->right = new Node(treeStr[i+1]);
                    pre = cur;
                    cout << root->weight << endl;
                    cout << "PRE: " << pre->weight << endl;
                    cur = cur->right;
                }
                else if(treeStr[i+1] != ')'){
                    cur->left = new Node(treeStr[i+1]);
                    pre = cur;
                    cur = cur->left;
                }
            }
            else if(order == ')'){
                cout << "3" << endl;
                cur = pre;
            }
        }
    }
/*    Node* temp = root;
    while(temp){
        cout << temp->weight;
        if(temp->left != NULL){
            temp = temp->left;
            cout << temp->weight;
        }
        else{
            temp = temp->right;
        }
    }
*/
}

Node* MyBinaryTreeOps::deleteTree(Node *root)const
{
    if(root == NULL)
        return root;
    MyBinaryTreeOps::deleteTree(root->left);
    MyBinaryTreeOps::deleteTree(root->right);
    delete root;
}

int MyBinaryTreeOps::treeHeight(const Node *root)const
{
    if(root->left == NULL && root->right == NULL)
        return 0;
    else if(root->left == NULL && root->right != NULL){
        return MyBinaryTreeOps::treeHeight(root->right)+1;
        cout << MyBinaryTreeOps::treeHeight(root->right)+1 << endl;
    }
    else if(root->left != NULL && root->right == NULL)
        return MyBinaryTreeOps::treeHeight(root->left)+1;
    else
        return std::max(MyBinaryTreeOps::treeHeight(root->right)+1, MyBinaryTreeOps::treeHeight(root->left)+1);
}

int MyBinaryTreeOps::treeWeight(const Node *root)const
{
    int sum = 0;
    const Node* cur = root;
    if(root->left == NULL && root->right == NULL)
        return 0;
    else if(root->left == NULL && root->right != NULL)
        return root->weight+MyBinaryTreeOps::treeWeight(root->right);
    else if(root->left != NULL && root->right == NULL)
        return root->weight+MyBinaryTreeOps::treeWeight(root->left);
    else
        return root->weight+MyBinaryTreeOps::treeWeight(root->right)+MyBinaryTreeOps::treeWeight(root->left);

}

int MyBinaryTreeOps::leafNum(const Node *root)const
{
    int leaf = 0;
    const Node* cur = root;
    const Node* pre = 0;
    if(cur){
        if(cur->left != NULL){
            pre = cur;
            cur = cur->left;
        }
        else if(cur->right != NULL){
            pre = cur;
            cur = cur->right;
        }
        else {
            if(cur == pre->right && pre->left != NULL){
                return MyBinaryTreeOps::leafNum(pre->left)+1;
            }
            else if(cur == pre->left && pre->right != NULL){
                return MyBinaryTreeOps::leafNum(pre->right)+1;
            }
            return MyBinaryTreeOps::leafNum(pre->left)+MyBinaryTreeOps::leafNum(pre->right)+1;
        }
    }

}

int MyBinaryTreeOps::maxPathWeight(const Node *root)const
{
    int sum = 0;
    if(root->left == NULL && root->right == NULL)
        return 0;
    else if(root->left == NULL && root->right != NULL)
        return root->weight+MyBinaryTreeOps::maxPathWeight(root->right);
    else if(root->left != NULL && root->right == NULL)
        return root->weight+MyBinaryTreeOps::maxPathWeight(root->left);
    else
        return std::max(root->weight+MyBinaryTreeOps::maxPathWeight(root->right), root->weight+MyBinaryTreeOps::maxPathWeight(root->left));
}
