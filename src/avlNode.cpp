#include "avlNode.hpp"

avlNode::avlNode(const int data, avlNode* solcocuk, avlNode *sagcocuk)
{
    this->data=data;
    this->sag=sagcocuk;
    this->sol=solcocuk;
    height=0;
}