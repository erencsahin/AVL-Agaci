#include <iostream>
#include <fstream>
#include <sstream>
#include <limits.h>
#include "avlNode.hpp"
#include "avlTree.hpp"
#include "stack.hpp"

using namespace std;

// ASCII değerini hesaplayan fonksiyon
int calculateAsciiValue(avlTree* tree) {
    int totalSum = tree->Tumdugumlertopla(tree->kokugetir());
    int leafSum = tree->yaprakdugumleritopla(tree->kokugetir());
    return (totalSum - leafSum) % (90 - 65 + 1) + 65;
}

// Ekranı temizleyen fonksiyon
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printTreesAndStacks(avlTree** agacdizisi, stack** stackdizisi, int agacsayisi) {
    //cout << "agac:" << endl;
    for (int i = 0; i < agacsayisi; ++i) {
        if (agacdizisi[i] != nullptr) {
            int ascii = calculateAsciiValue(agacdizisi[i]);
            cout << char(ascii);
        }
    }

    //cout << "Stack'ler:" << endl;
    /*for (int i = 0; i < agacsayisi; ++i) {
        //cout << "Stack " << i + 1 << ": ";
        if (stackdizisi[i] != nullptr && !stackdizisi[i]->bosmu()) {
            cout << stackdizisi[i]->top();
        }
        cout << endl;
    }*/
}

int main() {
    ifstream dosya("sayilar.txt");
    string satir;
    const int agacsayisikapasitesi = 500;
    avlTree** agacdizisi = new avlTree*[agacsayisikapasitesi];
    stack** stackdizisi = new stack*[agacsayisikapasitesi];
    avlTree avl;

    for (int i = 0; i < agacsayisikapasitesi; i++) {
        agacdizisi[i] = nullptr;
        stackdizisi[i] = nullptr;
    }

    int agacindex = 0;

    while (getline(dosya, satir)) {
        istringstream ss(satir);
        int sayi;

        agacdizisi[agacindex] = new avlTree();
        stackdizisi[agacindex] = new stack();

        while (ss >> sayi) {
            agacdizisi[agacindex]->ekle(sayi);
        }

        int ascii = calculateAsciiValue(agacdizisi[agacindex]);
        cout << char(ascii);

        agacdizisi[agacindex]->yaprakDugumleriBulVeStackeEkle(*stackdizisi[agacindex]);
        agacindex = (agacindex + 1) % agacsayisikapasitesi;
    }
    cout << endl;

    bool devam = true;
    while (devam) {
        int enkucuk = INT_MAX;
        int enbuyuk = INT_MIN;
        int bosStackSayisi = 0;
        int silinenAgacIndex = -1;

        // Tüm stack'lerin en üstündeki değerleri karşılaştırma
        for (int i = 0; i < agacsayisikapasitesi; ++i) {
            if (stackdizisi[i] != nullptr && !stackdizisi[i]->bosmu()) {
                int tepeDeger = stackdizisi[i]->top();
                enkucuk = min(enkucuk, tepeDeger);
                enbuyuk = max(enbuyuk, tepeDeger);
            } else {
                bosStackSayisi++;
            }
        }

        // Tüm stack'ler boşsa döngüden çık
        if (bosStackSayisi == agacsayisikapasitesi) {
            break;
        }

        // En küçüğü ve en büyüğü çıkarma
        for (int i = 0; i < agacsayisikapasitesi; ++i) {
            if (stackdizisi[i] != nullptr && !stackdizisi[i]->bosmu() && stackdizisi[i]->top() == enkucuk) {
                stackdizisi[i]->pop();
                cout << " " << i + 1 << ". indisten cikarilan ENKUCUK deger: " << enkucuk << endl;
                if (stackdizisi[i]->bosmu()) {
                    // Stack boşsa ağacı sil
                    silinenAgacIndex = i;
                    delete agacdizisi[silinenAgacIndex];
                    agacdizisi[silinenAgacIndex] = nullptr;
                }
                break;
            }
        }

        for (int i = 0; i < agacsayisikapasitesi; ++i) {
            if (stackdizisi[i] != nullptr && !stackdizisi[i]->bosmu() && stackdizisi[i]->top() == enbuyuk) {
                stackdizisi[i]->pop();
                cout << " " << i + 1 << ". indisten cikarilan enbuyuk deger: " << enbuyuk << endl;
                if (stackdizisi[i]->bosmu()) {
                    // Stack boşsa ağacı sil
                    silinenAgacIndex = i;
                    delete agacdizisi[silinenAgacIndex];
                    agacdizisi[silinenAgacIndex] = nullptr;
                }
                break;
            }
        }

        // Herhangi bir stack boşsa döngüden çık
        devam = false;
        for (int i = 0; i < agacsayisikapasitesi; ++i) {
            if (stackdizisi[i] != nullptr && !stackdizisi[i]->bosmu()) {
                devam = true;
                break;
            }
        }

        // Ekranı temizleme işlemi
        clearScreen();

        // Silinen ağacı hariç tüm ağaçları ve stack'leri yazdırma
        printTreesAndStacks(agacdizisi, stackdizisi, agacsayisikapasitesi);
        //_sleep(2000);
    }

    // Belleği temizle
    for (int i = 0; i < agacsayisikapasitesi; ++i) {
        delete agacdizisi[i];
        delete stackdizisi[i];
    }

    delete[] agacdizisi;
    delete[] stackdizisi;

    dosya.close();
    return 0;
}
