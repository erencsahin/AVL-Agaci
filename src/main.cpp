#include <iostream>
#include "avlNode.hpp"
#include "avlTree.hpp"
#include <sstream>
#include <fstream>

using namespace std;
int main()
{
    /*ifstream dosya("sayilar.txt");
    string satir;
    const int agacsayisi=500;
    avlTree* agacdizisi[agacsayisi];
    stack* stackdizisi[agacsayisi];

    for (int i = 0; i < agacsayisi; i++)
    {
        agacdizisi[i]=new avlTree();
        stackdizisi[i]=new stack();
    }
    int agacindex=0;

    // Dosyadan her satırı oku
    while (getline(dosya, satir)) {
        istringstream ss(satir);
        int sayi;
    
        agacdizisi[agacindex]=new avlTree();

        // Satırdaki her sayıyı AVL ağacına ekle
        while (ss >> sayi) {
            agacdizisi[agacindex]->ekle(sayi);
        }
        agacdizisi[agacindex]->yaprakDugumleriBulVeStackeEkle(*stackdizisi[agacindex]);
        agacindex=(agacindex+1)%agacsayisi;
    }
    cout<<endl;
    for (int i = 0; i < agacsayisi; i++)
    {
        int avldekitoplam=agacdizisi[i]->yaprakDugumuOlmayanToplam();
        //cout << "Agac: " << i + 1 << " Yaprak Dugumu Olmayan Toplam: " << avldekitoplam << endl;
        int ascii = avldekitoplam%(90-65 + 1) + 65;
        cout<<char(ascii);
    }

    for (int i = 0; i < agacsayisi; i++)
    {
        cout<<"agac: "<<i+1<<" yaprakdugumler: ";
        while (!stackdizisi[i]->bosmu())
        {
            cout<< " || "<<stackdizisi[i]->pop();
        }
        cout<<endl;
    }
    dosya.close();
    return 0;*/
    ifstream dosya("vsd.txt");
    string satir;
    const int agacsayisi = 3; // Örneğinizdeki ağaç sayısı
    avlTree* agacdizisi[agacsayisi];
    stack* stackdizisi[agacsayisi];

    for (int i = 0; i < agacsayisi; i++) {
        agacdizisi[i] = new avlTree();
        stackdizisi[i] = new stack();
    }

    int agacindex = 0;

    // Dosyadan her satırı oku
    while (getline(dosya, satir)) {
        istringstream ss(satir);
        int sayi;

        // Her yeni satır için yeni ağaç oluştur
        agacdizisi[agacindex]->clear();

        // Satırdaki her sayıyı AVL ağacına ekle
        while (ss >> sayi) {
            agacdizisi[agacindex]->ekle(sayi);
        }

        // Yaprak düğümleri bul ve stack'e ekle
        agacdizisi[agacindex]->yaprakDugumleriBulVeStackeEkle(*stackdizisi[agacindex]);

        agacindex = (agacindex + 1) % agacsayisi;
    }

    while (true) {
        // Her döngü başında tüm stacklerin durumunu kontrol et
        bool herhangiBirStackBos = false;

        for (int i = 0; i < agacsayisi; i++) {
            if (stackdizisi[i]->bosmu()) {
                herhangiBirStackBos = true;
                break;
            }
        }

        if (herhangiBirStackBos) {
            // Herhangi bir stack boş değilse devam et
            int enKucukIndex = -1;
            int enKucuk = numeric_limits<int>::max();

            int enBuyukIndex = -1;
            int enBuyuk = numeric_limits<int>::min();

            // En küçük ve en büyük sayıları bulma
            for (int i = 0; i < agacsayisi; i++) {
                if (!stackdizisi[i]->bosmu()) {
                    int eleman = stackdizisi[i]->top();

                    if (eleman < enKucuk) {
                        enKucuk = eleman;
                        enKucukIndex = i;
                    }

                    if (eleman > enBuyuk) {
                        enBuyuk = eleman;
                        enBuyukIndex = i;
                    }
                }
            }

            // En küçük sayıyı olan stackten çıkar
            // Eğer stack boşaldıysa, ilgili ağacı da sil
            if (enKucukIndex != -1 && !stackdizisi[enKucukIndex]->bosmu()) {
                stackdizisi[enKucukIndex]->pop();
            }

            if (enKucukIndex != -1 && stackdizisi[enKucukIndex]->bosmu()) {
                delete agacdizisi[enKucukIndex];
                agacdizisi[enKucukIndex] = nullptr;
            }

            // En büyük sayıyı olan stackten çıkar
            // Eğer stack boşaldıysa, ilgili ağacı da sil
            if (enBuyukIndex != -1 && !stackdizisi[enBuyukIndex]->bosmu()) {
                stackdizisi[enBuyukIndex]->pop();
            }

            if (enBuyukIndex != -1 && stackdizisi[enBuyukIndex]->bosmu()) {
                delete agacdizisi[enBuyukIndex];
                agacdizisi[enBuyukIndex] = nullptr;
            }
        } else {
            // Herhangi bir stack boş değilse döngüyü sonlandır
            break;
        }
    }

    // Tüm stackleri yazdır
    for (int i = 0; i < agacsayisi; i++) {
        cout << "Stack " << i + 1 << ": ";
        while (!stackdizisi[i]->bosmu()) {
            cout << stackdizisi[i]->pop() << " ";
        }
        cout << endl;
    }

    // Belleği temizle
    for (int i = 0; i < agacsayisi; i++) {
        delete agacdizisi[i];
        delete stackdizisi[i];
    }

    dosya.close();
    return 0;
}
