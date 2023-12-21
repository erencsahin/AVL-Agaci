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
    for (int i = 0; i < agacsayisi; i++) {
        if (!stackdizisi[i]->bosmu()) {
            cout << "Stack " << i + 1 << ": " << stackdizisi[i]->pop() << endl;
        }
    }
    
    

    dosya.close();
    return 0;
}
