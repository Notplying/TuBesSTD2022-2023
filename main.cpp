#include "Header.h"
#include <iostream>

using namespace std;

int main()
{
    ListParent Kat;
    ListSpesifik Spe;
    Inisialisasi(Kat, Spe);
    string inp;
    adrp pp;
    adrs ps;
    adrc pc;
    makanan m;
    int uid;
    int i;
    string ukt;
    //DeleteKategori(Kat, "Minuman");
    //DeleteKategori(Kat, "Coklat");
    //DeleteKategori(Kat, "Snack");
    //DeleteChild(Kat, "Minuman", 1);
    //DeleteChild(Kat, "Minuman", 2);
    //DeleteChild(Kat, "Minuman", 3);
    //DeleteSpesifik(Kat, Spe, 1);
    //DeleteSpesifik(Kat, Spe, 2);
    //DeleteSpesifik(Kat, Spe, 3);
    //ShowAll(Spe);
    //ShowALlC(Kat);
    //cout << info(pointer(child(SearchP(Kat, "Minuman")))).ID;
    //ShowAllPC(Kat);
    //cout << info(pointer(SearchC(Kat, 1))).nama;
    //cin >> inp;
    //cout << CheckKadaluarsa(info(pointer(SearchCP(Kat, SearchP(Kat, "Minuman"), 1))),inp);
    int pilihan = Menu();
    while (pilihan != 0){
        switch (pilihan){
        case 1:
            cout << "Masukkan nama kategori baru: ";
            cin >> inp;
            pp = celmp(inp);
            InsertFC(Kat, pp);
            break;
        case 2:
            cout << "Masukkan detail makanan baru:" << endl;
            cout << "ID Makanan: ";
            cin >> m.ID;
            cout << "Nama Makanan: ";
            cin >> m.nama;
            cout << "Merek Makanan: ";
            cin >> m.merek;
            cout << "Kadaluarsa Makanan(DD/MM/YY): ";
            cin >> m.kadaluarsa;
            ps = celms(m);
            InsertL(Spe, ps);
            break;
        case 3:
            cout << "Masukkan ID Makanan: ";
            cin >> uid;
            cout << "Masukkan Kategori: ";
            cin >> ukt;
            ps = SearchS(Spe, uid);
            pc = celmc(ps);
            pp = SearchP(Kat, ukt);
            InsertChild(Kat, pp, pc);
            break;
        case 4:
            cout << "Kategori yang akan dihapus: ";
            cin >> inp;
            DeleteKategori(Kat, inp);
            break;
        case 5:
            cout << "ID Makanan yang akan dihapus: ";
            cin >> uid;
            DeleteSpesifik(Kat, Spe, uid);
            break;
        case 6:
            cout << "ID Makanan yang akan dihapus: ";
            cin >> uid;
            cout << "Dari Kategori: ";
            cin >> inp;
            DeleteChild(Kat, inp, uid);
            break;
        case 7:
            cout << "Kategori yang dicek: ";
            cin >> inp;
            pp = SearchP(Kat, inp);
            if (pp != NULL){
                cout << endl << "Kategori " << kategori(pp) << endl;
                pc = child(pp);
                i = 1;
                while (pc != NULL){
                    cout << endl;
                    cout << "Makanan " << i << endl;
                    cout << "ID: " << info(pointer(pc)).ID << endl;
                    cout << "Nama: " << info(pointer(pc)).nama << endl;
                    cout << "Merek: " << info(pointer(pc)).merek << endl;
                    cout << "Kadaluarsa: " << info(pointer(pc)).kadaluarsa << endl;
                    i++;
                    pc = nextc(pc);
                }
            } else {
                cout << "Tidak ada kategori " << inp << endl;
            }
            break;
        case 8:
            cout << "ID Makanan yang dicek :";
            cin >> uid;
            ps = SearchS(Spe, uid);
            if (ps != NULL){
                m = info(ps);
                cout << "Makanan dengan ID " << uid << endl;
                cout << "Nama Makanan: " << m.nama << endl;
                cout << "Merek Makanan: " << m.merek << endl;
                cout << "Kadaluarsa Makanan: " << m.kadaluarsa << endl;
            } else {
                cout << "Tidak ada makanan dengan ID " << uid << endl;
            }
            break;
        case 9:
            cout << "ID Makanan yang dicek: ";
            cin >> uid;
            cout << "Dari Kategori: ";
            cin >> inp;
            pc = SearchCP(Kat, SearchP(Kat, inp), uid);
            if (pc != NULL){
                cout << "Ditemukan makanan dengan ID " << uid << " pada Kategori " << inp << endl;
                cout << "ID: " << info(pointer(pc)).ID << endl;
                cout << "Nama: " << info(pointer(pc)).nama << endl;
                cout << "Merek: " << info(pointer(pc)).merek << endl;
                cout << "Kadaluarsa: " << info(pointer(pc)).kadaluarsa << endl;
            } else {
                cout << "Tidak ditemukan makanan dengan ID " << uid << " pada Kategori " << inp << endl;
            }
            break;
        case 10:
            ShowALlC(Kat);
            break;
        case 11:
            ShowAll(Spe);
            break;
        case 12:
            ShowAllPC(Kat);
            break;
        case 13:
            cout << "Kategori yang dihitung: ";
            cin >> inp;
            cout << "Jumlah Makanan pada Kategori " << inp << ": " << CountChild(Kat, inp) << endl;
            break;
        case 14:
            cout << "Masukkan Tanggal (DD/MM/YY): ";
            cin >> inp;
            KumpulKadaluarsa(Kat, inp);
            cout << "Selesai" << endl;
            break;
        case 15:
            cout << "Membuang Makanan yang Kadaluarsa..." << endl;
            child(SearchP(Kat, "Kadaluarsa")) = NULL;
            BuangKadaluarsa(Spe);
            cout << "Selesai" << endl;
            break;
        default:
            cout << "Input Nomor yang valid!!" << endl;
            break;
        }
        switch(Prompt()){
        case true:
            cout << endl;
            pilihan = Menu();
            break;
        case false:
            pilihan = 0;
            break;
        }
    }
    return 0;
}
