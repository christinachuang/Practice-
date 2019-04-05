#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include <iostream>
using namespace std;
template <class T> class Tree;
template< class T >
class TreeNode{
friend class Tree <T>;
//private:
public:
    TreeNode(const T& value, TreeNode* leftchild=NULL, TreeNode* rightchild=NULL){
    data=value;
//    link=next;
    }
    T data;
    TreeNode<T>* leftchild;
    TreeNode<T>* rightchild;
};

template <class T>
class Tree{
public:
    Tree(){root=NULL;}
    void Inorder(TreeNode<T>* currentNode);
//    void Height(TreeNode<T>* currentNode,int maxi);
//private:
    TreeNode<T>* root;
};


#endif // TREE_H_INCLUDED
