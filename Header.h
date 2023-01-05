#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <stdlib.h>
using namespace std;

#define kategori(P) (P)->kategori
#define info(P) (P)->info
#define nextp(P) (P)->nextp
#define nextc(P) (P)->nextc
#define nexts(P) (P)->nexts
#define child(P) (P)->child
#define pointer(P) (P)->pointer
#define head(L) ((L).head)
#define first(L) ((L).first)

typedef struct parent *adrp;
typedef struct spesifik *adrs;
typedef struct childparent *adrc;

struct makanan {
    int ID;
    string nama;
    string merek;
    string kadaluarsa;
    bool k;
};

struct parent {
    string kategori;
    adrc child;
    adrp nextp;
};

struct spesifik {
    makanan info;
    adrs nexts;
};

struct childparent {
    adrs pointer;
    adrc nextc;
};

struct ListParent {
    adrp head;
};

struct ListSpesifik {
    adrs first;
};
//Bikin List
void CreateList(ListSpesifik &L);
void CreateListParent(ListParent &L);

//Bikin Element
adrp celmp(string kategori);
adrs celms(makanan info);
//Menambah Data Child
adrc celmc(adrs pointer);

//Insert Data Parent
void InsertF(ListSpesifik &L, adrs p);
void InsertFC(ListParent &L, adrp p);
void InsertL(ListSpesifik &L, adrs p);
void InsertLC(ListParent &L, adrp p);

//ShowAll Parent
void ShowAll(ListSpesifik &L);
void ShowALlC(ListParent &L);

//Menghapus data parent beserta relasi
void DeleteKategori(ListParent &L, string kategori);
void DeleteSpesifik(ListParent &P, ListSpesifik &L, int id);

//Mencari Data Parent
adrp SearchP(ListParent &L, string kategori);
adrs SearchS(ListSpesifik &L, int id);

//Mencari Data Child
adrc SearchC(ListParent &L, int id);

//Menghubungkan Parent ke Child
void InsertChild(ListParent &L, adrp p, adrc c);

//SHowAll parent child
void ShowAllPC(ListParent &L);

//Mencari data child pada parent tertentu
adrc SearchCP(ListParent &L, adrp p, int id);

//Menghapus data child pada parent tertentu beserta relasinya
void DeleteChild(ListParent &L, string kategori, int id);

//Menghapus Cgild dengan ID
void DeleteCID(ListParent &L, int id);

//Menghitung jumlah data child dari parent tertentu
int CountChild(ListParent &L, string kategori);

void Inisialisasi(ListParent &p, ListSpesifik &s);

int Menu();
bool Prompt();

bool CheckKadaluarsa(makanan m, string date);
void KumpulKadaluarsa(ListParent &L, string date);

void BuangKadaluarsa(ListSpesifik &L);
#endif // HEADER_H_INCLUDED
