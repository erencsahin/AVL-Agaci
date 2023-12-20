#ifndef avlNode_hpp
#define avlNode_hpp

class avlNode
{
public:
    int data;
    avlNode *sol;
    avlNode* sag;
    int height;
    avlNode(const int data, avlNode* solcocuk=nullptr,avlNode* sagcocuk=nullptr);
};

#endif