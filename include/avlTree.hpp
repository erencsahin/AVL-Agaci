#ifndef avlTree_hpp
#define avlTree_hpp
#include "avlNode.hpp"
#include "stack.hpp"
#include <string>
using namespace std;


class avlTree
{
private:
    
    avlNode* araveekle(avlNode*, const int&);
    avlNode* solcocukladegis(avlNode*);
    avlNode* sagcocukladegis(avlNode*);
    int height(avlNode*);
    
    
public:
    avlNode *kok;
    stack yaprakstack;
    avlTree();
    bool bosmu()const;
    void ekle(const int&);
    void clear();
    void readData(const string& fileName, avlTree &tree);
    void postorder(avlNode*);
    avlNode* kokugetir();
    int Tumdugumlertopla(avlNode* kok);
    int yaprakdugumleritopla(avlNode* kok);
    void postorderyazdir();
    void yaprakDugumleribul(avlNode*,stack&);
    void yaprakDugumleriBulVeStackeEkle(stack&);
    bool ara(const int &item);
    bool araHelper(avlNode *altdugum, const int &item);
    int yaprakDugumuOlmayanToplam();
    int yaprakDugumuOlmayanToplamHelper(avlNode* altdugum);
    int enkucukcikar(stack** stackdizisi, avlTree**& agacdizisi, int& agacsayisi);
    int enbuyukcikar(stack** stackdizisi, avlTree**& agacdizisi, int& agacsayisi);
    void stackiSil(avlTree**& agacdizisi, stack**& stackdizisi, int& agacsayisi, int silinecekIndex);
    
};

#endif