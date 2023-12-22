#include <iostream>
#include "avlNode.hpp"
#include "avlTree.hpp"
#include <sstream>
#include <fstream>

using namespace std;
int main()
{
    ifstream dosya("vsd.txt");
    string satir;
    const int agacsayisi = 500;
    avlTree* agacdizisi[agacsayisi];
    stack* stackdizisi[agacsayisi];

    for (int i = 0; i < agacsayisi; i++) {
        agacdizisi[i] = new avlTree();
        stackdizisi[i] = new stack();
    }

    int agacindex = 0;

    while (getline(dosya, satir)) {
        istringstream ss(satir);
        int sayi;


        while (ss >> sayi) {
            agacdizisi[agacindex]->ekle(sayi);
        }
        agacdizisi[agacindex]->yaprakDugumleriBulVeStackeEkle(*stackdizisi[agacindex]);

        agacindex = (agacindex + 1) % agacsayisi;
    }
    avlTree avl;
    int silinecekIndex=0;
    while (true)
    {
        int cikarilandeger=agacdizisi[silinecekIndex]->enkucukcikar(stackdizisi,agacsayisi);
        if (cikarilandeger==0)
        {
            agacdizisi[silinecekIndex]->stackiSil(stackdizisi, agacdizisi, agacindex, silinecekIndex);
            break;
        }
        
    }
    /*while (true) {
        int cikarilandeger = agacdizisi[silinecekIndex]->enkucukcikar(stackdizisi, agacsayisi);

        if (cikarilandeger == 0) {
            cout << "Stack silindi." << endl;
            stackiSil(stackdizisi, agacdizisi, agacsayisi, silinecekIndex);
            break;
        }
        else {
            cout << "Cikarilan deger: " << cikarilandeger << endl;
        }
    }*/
    


    for (int i = 0; i < 4; i++) {
        if (!stackdizisi[i]->bosmu()) {
            cout << "Stack " << i + 1 << ": " << stackdizisi[i]->top() << endl;
            stackdizisi[i]->top();
        }
        else
        {
            break;
        }
        
    }
    
   /* int enkücük=0;
    for (int i = 0; i < 500; i++)
    {
        if (stackdizisi[i]->pop()<enkücük)
        {
            
        }
        
    }*/
    

    dosya.close();
    return 0;
}
