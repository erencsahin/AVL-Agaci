#include "avlNode.hpp"
#include "avlTree.hpp"
#include <iostream>
#include <cmath>
#include "fstream"
#include "sstream"
#include <string>
using namespace std;

avlTree::avlTree()
{
    kok = nullptr;
}

void avlTree::ekle(const int &item)
{
    if (!ara(item))
    {
        kok=araveekle(kok,item);
    }
}

avlNode *avlTree::araveekle(avlNode *altdugum, const int &item)
{
    if (altdugum == NULL)
        altdugum = new avlNode(item);
    else if (item < altdugum->data)
    {
        altdugum->sol = araveekle(altdugum->sol, item);
        if (height(altdugum->sol) == height(altdugum->sag) + 2)
        {
            if (item < altdugum->sol->data)
            {
                altdugum = solcocukladegis(altdugum);
            }
            else
            {
                altdugum->sol = sagcocukladegis(altdugum->sol);
                altdugum = solcocukladegis(altdugum);
            }
        }
    }
    else if (item > altdugum->data)
    {
        altdugum->sag = araveekle(altdugum->sag, item);
        if (height(altdugum->sag) == height(altdugum->sol) + 2)
        {
            if (item > altdugum->sag->data)
            {
                altdugum = sagcocukladegis(altdugum);
            }
            else
            {
                altdugum->sag = solcocukladegis(altdugum->sag);
                altdugum = sagcocukladegis(altdugum);
            }
        }
    }

    return altdugum;
}

avlNode *avlTree::solcocukladegis(avlNode *altdugum)
{
    avlNode *tmp = altdugum->sol;
    altdugum->sol = tmp->sag;
    tmp->sag = altdugum;

    altdugum->height = height(altdugum);
    tmp->height = 1 + max(height(tmp->sol), altdugum->height);

    return tmp;
}

avlNode *avlTree::sagcocukladegis(avlNode *altdugum)
{
    avlNode *tmp = altdugum->sag;
    altdugum->sag = tmp->sol;
    tmp->sol = altdugum;

    altdugum->height = height(altdugum);
    tmp->height = 1 + max(height(tmp->sag), altdugum->height);
}

int avlTree::height(avlNode *altdugum)
{
    if (altdugum == NULL)
        return -1;
    return 1 + max(height(altdugum->sol), height(altdugum->sag));
}

void avlTree::postorder(avlNode *altdugum)
{
    if (altdugum != nullptr)
    {
        postorder(altdugum->sol);
        postorder(altdugum->sag);
        cout << altdugum->data << " ";
    }
}

bool avlTree::bosmu() const
{
    return kok == nullptr;
}

void avlTree::clear()
{
    while (bosmu() == true)
    {
        postorder(kok);
        kok = nullptr;
    }
}

avlNode *avlTree::kokugetir()
{
    return kok;
}

void avlTree::readData(const string &fileName, avlTree &agac)
{
    ifstream file(fileName); // Dosyayı aç
    if (file.is_open())
    {                // Dosya açıldıysa
        string line; // Her satırı tutacak değişken
        while (getline(file, line))
        {                          // Satır satır oku
            stringstream ss(line); // Satırı bir akışa dönüştür
            int key;               // Anahtar değeri tutacak değişken
            while (ss >> key)
            {                   // Akıştan anahtar değerini oku
                agac.ekle(key); // AVL ağacına ekle
            }
        }
        file.close();        // Dosyayı kapat
        agac.postorder(kok); // Postorder gezinme yap
        cout << endl;
    }
}

void avlTree::postorderyazdir()
{
    postorder(kok);
    cout << endl;
}

void avlTree::yaprakDugumleribul(avlNode *altdugum, stack &yaprakdugumler)
{
    if (altdugum == nullptr)
    {
        return;
    }
    if (altdugum->sol == nullptr && altdugum->sag == nullptr)
    {
        yaprakdugumler.push(altdugum->data);
    }
    yaprakDugumleribul(altdugum->sol, yaprakdugumler);
    yaprakDugumleribul(altdugum->sag, yaprakdugumler);
}

void avlTree::yaprakDugumleriBulVeStackeEkle(stack &yaprakdugumler)
{
    avlTree::yaprakDugumleribul(kok, yaprakdugumler);
}

bool avlTree::ara(const int& item)
{
    return araHelper(kok, item);
}

bool avlTree::araHelper(avlNode* altdugum, const int& item)
{
    if (altdugum == nullptr)
    {
        return false;
    }

    if (item == altdugum->data)
    {
        return true;
    }
    else if (item < altdugum->data)
    {
        return araHelper(altdugum->sol, item);
    }
    else
    {
        return araHelper(altdugum->sag, item);
    }
}

int avlTree::yaprakDugumuOlmayanToplam()
{
    return yaprakDugumuOlmayanToplamHelper(kok);
}

int avlTree::yaprakDugumuOlmayanToplamHelper(avlNode* altdugum)
{
    if (altdugum == nullptr) {
        return 0;
    }

    if (altdugum->sol == nullptr && altdugum->sag == nullptr) {
        return 0; // Yaprak düğüm olduğu için 0 döndürüyoruz
    }

    // Yaprak düğüm olmayan toplamı hesapla
    int solToplam = yaprakDugumuOlmayanToplamHelper(altdugum->sol);
    int sagToplam = yaprakDugumuOlmayanToplamHelper(altdugum->sag);

    return altdugum->data + solToplam + sagToplam;
}