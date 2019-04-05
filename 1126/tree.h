#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include <string>
extern int y;
extern int num;
class Node
{
public:
    int weight; // weight can be negative!
    Node *left, *right;
    Node():weight(0),left(NULL),right(NULL){}
    Node(int d):weight(d),left(NULL),right(NULL){}
};

class BinearyTreeOps
{
public:
//----------------------------------------------------------------------
// Input a tree string in S-expression, construct the tree and
// return the pointer to its root node.
//----------------------------------------------------------------------
Node* constructTree(Node *root, std::string treeStr)const;

//----------------------------------------------------------------------
// Delete and release the memory allocation of each node, and
// return a nullptr.
//----------------------------------------------------------------------
Node* deleteTree(Node *root)const;

//----------------------------------------------------------------------
// Return the height of the tree.
//----------------------------------------------------------------------
int treeHeight(const Node *root)const;

//----------------------------------------------------------------------
// Return the sum of node weights.
//----------------------------------------------------------------------
int treeWeight(const Node *root)const;

//----------------------------------------------------------------------
// Return the number of leaf nodes.
//----------------------------------------------------------------------
int leafNum(const Node *root)const;

//----------------------------------------------------------------------
// Return the max path weight from root to leaf.
//----------------------------------------------------------------------
int maxPathWeight(const Node *root)const;
};
#endif // TREE_H_INCLUDED
