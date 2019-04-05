#ifndef MyBinaryTreeOps_h
#define MyBinaryTreeOps_h

#include "readonly/BinearyTreeOps.h"

class MyBinaryTreeOps : public BinearyTreeOps
{
public:
    Node* constructTree(Node *root, std::string treeStr)const;

    Node* deleteTree(Node *root)const;

    int treeHeight(const Node *root)const;

    int treeWeight(const Node *root)const;

    int leafNum(const Node *root)const;

    int maxPathWeight(const Node *root)const;
private:

};

#endif
