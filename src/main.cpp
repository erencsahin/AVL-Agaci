
/*

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
    const int agacsayisikapasitesi = 500;
    int agacsayisi=0;
    avlTree** agacdizisi= new avlTree*[agacsayisikapasitesi];
    stack** stackdizisi=new stack*[agacsayisikapasitesi];
    
    avlTree avl;
    for (int i = 0; i < agacsayisi; i++) {
        agacdizisi[i] = new avlTree();
        stackdizisi[i] = new stack();
    }

    int agacindex = 0;

    while (getline(dosya, satir)) {
        istringstream ss(satir);
        int sayi;
        
        

        if (agacsayisi==agacsayisikapasitesi)
        {
            const int agacsayisikapasitesi = agacsayisikapasitesi*2;
            avlTree** tmp_agacdizisi=new avlTree*[agacsayisikapasitesi];
            stack** tmp_stackdizisi=new stack*[agacsayisikapasitesi];
            for (int i = 0; i < agacsayisi; ++i)
            {
                tmp_agacdizisi[i]=agacdizisi[i];
                tmp_stackdizisi[i]=stackdizisi[i];
            }
            delete[] agacdizisi;
            delete[] stackdizisi;

            agacdizisi=tmp_agacdizisi;
            stackdizisi=tmp_stackdizisi;            
        }
        agacdizisi[agacindex]=new avlTree();
        stackdizisi[agacindex]=new stack();

        while (ss >> sayi) {
            agacdizisi[agacindex]->ekle(sayi);
            
        }
        int tumtoplam=avl.Tumdugumlertopla(avl.kok);
        int yapraktoplam= avl.yaprakdugumleritopla(avl.kok);
        int ascii=tumtoplam-yapraktoplam%(90-65+1)+65;
        cout<< char(ascii);

        agacdizisi[agacindex]->yaprakDugumleriBulVeStackeEkle(*stackdizisi[agacindex]);
        agacindex = (agacindex + 1) % agacsayisikapasitesi;
        ++agacsayisi;
        
    }

    
    int silinecekIndex=0;
    while (true)
    {
        int cikarilandeger=agacdizisi[silinecekIndex]->enkucukcikar(stackdizisi,agacsayisi);
        if (cikarilandeger==0)
        {
            avl.stackiSil(agacdizisi, stackdizisi, agacsayisi, silinecekIndex);
            break;
        }
        else
        {
            cout<<"cikarilan deger: "<<cikarilandeger<<endl;
        }
    }

    for (int i = 0; i < agacsayisi; i++) {
        if (!stackdizisi[i]->bosmu()) {
            cout << "Stack " << i + 1 << ": " << stackdizisi[i]->top() << endl;
        }
    }
    
    delete[] agacdizisi;
    delete[] stackdizisi;
    
    
    dosya.close();
    return 0;
}
*/
// main.cpp
// main.cpp
#include <iostream>
#include "avlNode.hpp"
#include "avlTree.hpp"
#include <sstream>
#include <fstream>
#include "stack.hpp"

using namespace std;

int main()
{
    ifstream dosya("vsd.txt");
    string satir;
    const int agacsayisikapasitesi = 500;
    int agacsayisi = 0;
    avlTree **agacdizisi = new avlTree *[agacsayisikapasitesi];
    stack **stackdizisi = new stack *[agacsayisikapasitesi];

    avlTree avl;
    for (int i = 0; i < agacsayisikapasitesi; i++)
    {
        agacdizisi[i] = new avlTree();
        stackdizisi[i] = new stack();
    }

    int agacindex = 0;

    while (getline(dosya, satir))
    {
        istringstream ss(satir);
        int sayi;

        
        if (agacsayisi == agacsayisikapasitesi)
        {
            const int agacsayisikapasitesi = agacsayisikapasitesi * 2;
            avlTree **tmp_agacdizisi = new avlTree *[agacsayisikapasitesi];
            stack **tmp_stackdizisi = new stack *[agacsayisikapasitesi];
            for (int i = 0; i < agacsayisi; ++i)
            {
                tmp_agacdizisi[i] = agacdizisi[i];
                tmp_stackdizisi[i] = stackdizisi[i];
            }
            delete[] agacdizisi;
            delete[] stackdizisi;

            agacdizisi = tmp_agacdizisi;
            stackdizisi = tmp_stackdizisi;
        }
        
        //agacdizisi[agacindex] = new avlTree();
        //stackdizisi[agacindex] = new stack();
        

        while (ss >> sayi)
        {
            agacdizisi[agacindex]->ekle(sayi);
        }

        int tumtoplam = agacdizisi[agacindex]->Tumdugumlertopla(agacdizisi[agacindex]->kokugetir());
int yapraktoplam = agacdizisi[agacindex]->yaprakdugumleritopla(agacdizisi[agacindex]->kokugetir()); 
        int ascii = (tumtoplam - yapraktoplam) % (90 - 65 + 1) + 65;
        cout << char(ascii);


        cout<< "kacinciagac: " <<agacindex << " agacin koku: " << agacdizisi[agacindex]->kokugetir()->data << ", ASCII Degeri: " << char(ascii) << endl;
       
        agacdizisi[agacindex]->yaprakDugumleriBulVeStackeEkle(*stackdizisi[agacindex]);
        agacindex = (agacindex + 1) % agacsayisikapasitesi;
        ++agacsayisi;
    }

    int silinecekIndex = 0;
    while (true)
    {
        int cikarilandeger = agacdizisi[silinecekIndex]->enkucukcikar(stackdizisi, agacsayisi);
        if (cikarilandeger == 0)
        {
            avl.stackiSil(agacdizisi, stackdizisi, agacsayisi, silinecekIndex);
            break;
        }
        else
        {
            //cout << "cikarilan deger: " << cikarilandeger << endl;
        }
    }

    for (int i = 0; i < agacsayisi; i++)
    {
        if (!stackdizisi[i]->bosmu())
        {
            //cout << "Stack " << i + 1 << ": " << stackdizisi[i]->top() << endl;
        }
    }

    delete[] agacdizisi;
    delete[] stackdizisi;

    dosya.close();
    return 0;
}
