#include "Header.h"

//Bikin List
void CreateList(ListSpesifik &L){
    first(L) = NULL;
}
void CreateListParent(ListParent &L){
    head(L) = NULL;
}

//Bikin Element
adrp celmp(string kategori){
    adrp out = new parent;
    kategori(out) = kategori;
    child(out) = NULL;
    nextp(out) = NULL;
    return out;
}
adrs celms(makanan info){
    adrs out = new spesifik;
    info(out) = info;
    info(out).k = false;
    nexts(out) = NULL;
    return out;
}
//Menambah Data Child
adrc celmc(adrs pointer){
    adrc out = new childparent;
    pointer(out) = pointer;
    nextc(out) = NULL;
    return out;
}

//Insert Data Parent
void InsertF(ListSpesifik &L, adrs p){
    if (first(L) == NULL){
        first(L) = p;
    } else {
        nexts(p) = first(L);
        first(L) = p;
    }
}
void InsertFC(ListParent &L, adrp p){
    if (head(L) == NULL){
        head(L) = p;
        nextp(p) = p;
    } else {
        adrp q = head(L);
        nextp(p) = head(L);
        while (nextp(q) != head(L)){
            q = nextp(q);
        }
        nextp(q) = p;
        head(L) = p;
    }
}
void InsertL(ListSpesifik &L, adrs p){
    if (first(L) == NULL){
        first(L) = p;
    } else {
        adrs q = first(L);
        while (nexts(q) != NULL){
            q = nexts(q);
        }
        nexts(q) = p;
    }
}
void InsertLC(ListParent &L, adrp p){
    if (head(L) == NULL){
        head(L) = p;
        nextp(p) = p;
    } else {
        adrp q = head(L);
        while (nextp(q) != head(L)){
            q = nextp(q);
        }
        nextp(q) = p;
        nextp(p) = head(L);
    }
}

//ShowAll Parent
void ShowAll(ListSpesifik &L){
    adrs q = first(L);
    int i = 1;
    cout << "Semua Makanan: " << endl;
    while (q != NULL){
        cout << "Makanan " << i << endl;
        cout << "ID: " << info(q).ID << endl;
        cout << "Nama: " << info(q).nama << endl;
        cout << "Merek: " << info(q).merek << endl;
        cout << "Kadaluarsa: " << info(q).kadaluarsa << endl << endl;
        i++;
        q = nexts(q);
    }
    cout << endl;
}
void ShowALlC(ListParent &L){
    adrp q = head(L);
    cout << "Semua Kategori: ";
    while (nextp(q) != head(L)){
        cout << kategori(q) << " | ";
        q = nextp(q);
    }
    cout << kategori(q) << endl;
}

//Menghapus data parent beserta relasi
void DeleteKategori(ListParent &L, string kategori){
    adrp p = SearchP(L, kategori);
    adrp q = head(L);
    if (p == NULL){
        cout << "Tidak ada kategori " << kategori << "!!" << endl;
    } else {
        while (nextp(q) != p){
            q = nextp(q);
        }
        if (head(L) == p){
            head(L) = nextp(p);
        }
        nextp(q) = nextp(p);
        p = NULL;
    }
}
void DeleteSpesifik(ListParent &P, ListSpesifik &L, int id){
    adrs p = SearchS(L, id);
    adrs q = first(L);
    if (p == NULL){
        cout << "Tidak ada Makanan dengan ID " << id << "!!" << endl;
    } else if (first(L) == p){
        DeleteCID(P, id);
        first(L) = nexts(p);
        delete p;// = NULL;
    } else {
        while (nexts(q) != p){
            q = nexts(q);
        }
        DeleteCID(P, id);
        nexts(q) = nexts(p);
        delete p;// = NULL;
    }
}

//Mencari Data Parent
adrp SearchP(ListParent &L, string kategori){
    adrp p = head(L);
    while (nextp(p) != head(L) && kategori(p) != kategori){
        p = nextp(p);
    }
    if (kategori(p) == kategori){
        return p;
    } else {
        return NULL;
    }
}
adrs SearchS(ListSpesifik &L, int id){
    adrs p = first(L);
    while (nexts(p) != NULL && info(p).ID != id){
        p = nexts(p);
    }
    if (info(p).ID == id){
        return p;
    } else {
        return NULL;
    }
}

//Mencari Data Child
adrc SearchC(ListParent &L, int id){
    adrp par = head(L);
    adrc ch;
    while (nextp(par) != head(L)){
        ch = child(par);
        while (ch != NULL){
            if (info(pointer(ch)).ID == id){
                return ch;
            }
            ch = nextc(ch);
        }
        par = nextp(par);
    }
    ch = child(par);
    while (ch != NULL){
        if (info(pointer(ch)).ID == id){
            return ch;
        }
        ch = nextc(ch);
    }
    return NULL;
}

//Menghubungkan Parent ke Child
void InsertChild(ListParent &L, adrp p, adrc c){
    if (child(p) == NULL) {
        child(p) = c;
    } else {
        adrc q = child(p);
        while (nextc(q) != NULL){
            q = nextc(q);
        }
        nextc(q) = c;
    }
}

//SHowAll parent child
void ShowAllPC(ListParent &L){
    adrp par = head(L);
    adrc ch;
    int i;
    cout << "===========================" << endl;
    while (nextp(par) != head(L)){
        cout << "Kategori " << kategori(par) << endl;
        ch = child(par);
        i = 1;
        while (ch != NULL){
            cout << endl;
            cout << "Makanan " << i << endl;
            cout << "ID: " << info(pointer(ch)).ID << endl;
            cout << "Nama: " << info(pointer(ch)).nama << endl;
            cout << "Merek: " << info(pointer(ch)).merek << endl;
            cout << "Kadaluarsa: " << info(pointer(ch)).kadaluarsa << endl;
            i++;
            ch = nextc(ch);
        }
        par = nextp(par);
        cout << "===========================" << endl;
    }
    cout << "Kategori " << kategori(par) << endl;
    ch = child(par);
    i = 1;
    while (ch != NULL){
        cout << endl;
        cout << "Makanan " << i << endl;
        cout << "ID: " << info(pointer(ch)).ID << endl;
        cout << "Nama: " << info(pointer(ch)).nama << endl;
        cout << "Merek: " << info(pointer(ch)).merek << endl;
        cout << "Kadaluarsa: " << info(pointer(ch)).kadaluarsa << endl;
        i++;
        ch = nextc(ch);
    }
    cout << "===========================" << endl;
}

//Mencari data child pada parent tertentu
adrc SearchCP(ListParent &L, adrp p, int id){
    adrc ch = child(p);
    while (nextc(ch) != NULL && info(pointer(ch)).ID != id){
        ch = nextc(ch);
    }
    if (info(pointer(ch)).ID == id){
        return ch;
    } else {
        return NULL;
    }
}

//Menghapus data child pada parent tertentu beserta relasinya
void DeleteChild(ListParent &L, string kategori, int id){
    adrp ph = SearchP(L, kategori);
    adrc ch = SearchCP(L, ph, id);
    if (ph == NULL){
        cout << "Tidak ada Kategori " << kategori << "!!" << endl;
    } else if (ch == NULL){
        cout << "Tidak ada makanan dengan id " << id << " di kategori "<< kategori << "!!" << endl;
    } else {
        adrc q = child(ph);
        if (q == ch){
            child(ph) = nextc(ch);
            ch = NULL;
        } else {
            while (nextc(q) != ch){
                q = nextc(q);
            }
            nextc(q) = nextc(ch);
            ch = NULL;
        }
    }
}

//Menghapus child dengan id tertentu
void DeleteCID(ListParent &L, int id){
    adrp par = head(L);
    adrc ch;
    adrc runner;
    while (nextp(par) != head(L)){
        ch = child(par);
        while (ch != NULL){
            if (info(pointer(ch)).ID == id){
                if (ch == child(par)){
                    child(par) = nextc(ch);
                    ch = NULL;
                    break;
                } else {
                    runner = child(par);
                    while (nextc(runner) != ch){
                        runner = nextc(runner);
                    }
                    nextc(runner) = nextc(ch);
                    ch = NULL;
                    break;
                }
            }
            ch = nextc(ch);
        }
        par = nextp(par);
    }
    ch = child(par);
    while (ch != NULL){
        if (info(pointer(ch)).ID == id){
            if (ch == child(par)){
                    child(par) = nextc(ch);
                    ch = NULL;
                } else {
                    runner = child(par);
                    while (nextc(runner) != ch){
                        runner = nextc(runner);
                    }
                    nextc(runner) = nextc(ch);
                    ch = NULL;
                    break;
                }
        }
        ch = nextc(ch);
    }
}

//Menghitung jumlah data child dari parent tertentu
int CountChild(ListParent &L, string kategori){
    int out = 0;
    adrc ch = child(SearchP(L, kategori));
    while (ch != NULL){
        out++;
        ch = nextc(ch);
    }
    return out;
}

int Menu(){
    system("CLS");
    cout<<"================================================"<<endl;
    cout<<"=          TUGAS BESAR STRUKTUR DATA           ="<<endl;
    cout<<"=         Pengecekan Kadaluarsa Makanan        ="<<endl;
    cout<<"=  Oleh Ibadurrahman Syahid & Ahmad Maulana I  ="<<endl;
    cout<<"=             TELKOM UNIVERSITY                ="<<endl;
    cout<<"================================================"<<endl;
    cout<<endl;
    cout<<" ______________________________________________"<<endl;
    cout<<"|     Opsi Pilihan                             |"<<endl;
    cout<<"|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|"<<endl;
    cout<<"|   1. Menambahkan Kategori Baru               |"<<endl;
    cout<<"|   2. Menambahkan Makanan Baru                |"<<endl;
    cout<<"|   3. Menambahkan Makanan Pada Kategori       |"<<endl;
    cout<<"|   4. Menghapus Kategori                      |"<<endl;
    cout<<"|   5. Menghapus Makanan                       |"<<endl;
    cout<<"|   6. Menghapus Makanan Pada Kategori         |"<<endl;
    cout<<"|   7. Cek Kategori Yang Tersedia              |"<<endl;
    cout<<"|   8. Cek Makanan Yang Tersedia               |"<<endl;
    cout<<"|   9. Cek Makanan Pada Kategori               |"<<endl;
    cout<<"|   10.Tampilkan Seluruh Kategori              |"<<endl;
    cout<<"|   11.Tampilkan Seluruh Makanan               |"<<endl;
    cout<<"|   12.Tampilkan Seluruh Kategori & Makanan    |"<<endl;
    cout<<"|   13.Tampilkan Jumlah Makanan Pada Kategori  |"<<endl;
    cout<<"|   14.Memindahkan Makanan Kadaluarsa          |"<<endl;
    cout<<"|   15.Membuang Makanan Yang Telah Kadaluarsa  |"<<endl;
    cout<<"|   0.Exit                                     |"<<endl;
    cout<<"|______________________________________________|"<<endl;
    cout<<endl;
    cout << "Pilihan Menu: ";
    int inp;
    cin >> inp;
    cout << endl;
    return inp;
}
bool Prompt(){
    bool valid = false;
    char inp;
    cout << "Kembali ke menu utama? (Y/N): ";
    cin >> inp;
    while (!valid){
        switch (inp){
        case 'Y':
            return true;
            break;
        case 'N':
            return false;
            break;
        default:
            cout << "Input tidak valid!" << endl;
            cout << "Kembali ke menu utama? (Y/N): ";
            cin >> inp;\
            break;
        }
    }
}

bool CheckKadaluarsa(makanan m, string date){
    //DD/MM/YY
    //01234567
    //string temp = m.kadaluarsa;
    string myy = (m.kadaluarsa).substr(6,2);
    //cout << stoi(myy) << endl;
    string mmm = (m.kadaluarsa).substr(3,2);
    //cout << stoi(mmm) << endl;
    string mdd = (m.kadaluarsa).substr(0,2);
    //cout << stoi(mdd) << endl;
    string yy = date.substr(6,2);
    //cout << stoi(yy) << endl;
    string mm = date.substr(3,2);
    //cout << stoi(mm) << endl;
    string dd = date.substr(0,2);
    //cout << stoi(dd) << endl;

    if (stoi(myy) > stoi (yy)){
        return false;
    } else if (stoi (myy) < stoi(yy)){
        return true;
    } else {
        if (stoi(mmm) > stoi (mm)){
            return false;
        } else if (stoi(mmm) < stoi(mm)){
            return true;
        } else {
            if (stoi(mdd) > stoi(dd)){
                return false;
            } else {
                return true;
            }
        }
    }

}
void KumpulKadaluarsa(ListParent &L, string date){
    adrp kad = SearchP(L, "Kadaluarsa");
    adrp p = head(L);
    adrc ch;
    adrc runner;
    while (nextp(p) != head(L)){
        ch = child(p);
        while (ch != NULL){
            if (CheckKadaluarsa(info(pointer(ch)),date)){
                if (ch == child(p)){
                    child(p) = nextc(ch);
                    info(pointer(ch)).k = true;
                    //cout << 1 << endl;
                    nextc(ch) = NULL;
                    InsertChild(L, kad, ch);
                    ch = child(p);
                    //cout << 1 << endl;
                } else {
                    //cout << 2 << endl;
                    runner = child(p);
                    info(pointer(ch)).k = true;
                    while (nextc(runner) != ch){
                        runner = nextc(runner);
                    }
                    //cout << 2 << endl;
                    nextc(runner) = nextc(ch);
                    nextc(ch) = NULL;
                    InsertChild(L, kad, ch);
                    ch = nextc(runner);
                    //cout << 2 << endl;
                }
            } else {
                ch = nextc(ch);
            }
        }
        p = nextp(p);
    }
}
void BuangKadaluarsa(ListSpesifik &L){
    adrs p = first(L);
    adrs q;
    while (p != NULL){
        if (info(p).k){
            if (p = first(L)){
                first(L) = nexts(p);
                p = NULL;
                p = first(L);
            } else {
                q = first(L);
                while(nexts(q) != p){
                    q = nexts(q);
                }
                nexts(q) = nexts(p);
                p = NULL;
                p = nexts(q);
            }
        } else {
            p = nexts(p);
        }
    }
}

void Inisialisasi(ListParent &p, ListSpesifik &s){
    CreateListParent(p);
    CreateList(s);
    adrp pp;
    adrs ps;
    adrc pc;
    makanan m;

    //Kategori
    pp = celmp("Instant");
    InsertFC(p, pp);
    pp = celmp("Snack");
    InsertFC(p, pp);
    pp = celmp("Minuman");
    InsertLC(p, pp);
    pp = celmp("Permen");
    InsertLC(p, pp);
    pp = celmp("Coklat");
    InsertLC(p, pp);
    pp = celmp("Kadaluarsa");
    InsertLC(p, pp);

    //Spesifik
    m.ID = 1;
    m.nama = "Sprite";
    m.merek = "Coca-Cola";
    m.kadaluarsa = "30/12/22";
    ps = celms(m);
    InsertL(s, ps);

    m.ID = 2;
    m.nama = "Fanta";
    m.merek = "Coca-Cola";
    m.kadaluarsa = "30/12/23";
    ps = celms(m);
    InsertL(s, ps);

    m.ID = 3;
    m.nama = "BIG_Blueberry";
    m.merek = "BIG_Soda";
    m.kadaluarsa = "30/12/22";
    ps = celms(m);
    InsertL(s, ps);

    //Child
    ps = SearchS(s, 1);
    pc = celmc(ps);
    pp = SearchP(p, "Minuman");
    InsertChild(p, pp, pc);

    ps = SearchS(s, 2);
    pc = celmc(ps);
    pp = SearchP(p, "Minuman");
    InsertChild(p, pp, pc);

    ps = SearchS(s, 3);
    pc = celmc(ps);
    pp = SearchP(p, "Minuman");
    InsertChild(p, pp, pc);

    m.ID = 4;
    m.nama = "Zuperr_keju";
    m.merek = "Zuperr";
    m.kadaluarsa = "30/12/22";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 4);
    pc = celmc(ps);
    pp = SearchP(p, "Snack");
    InsertChild(p, pp, pc);

    m.ID = 5;
    m.nama = "Beng-beng_Karamel";
    m.merek = "Beng-beng";
    m.kadaluarsa = "29/08/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 5);
    pc = celmc(ps);
    pp = SearchP(p, "Snack");
    InsertChild(p, pp, pc);

    m.ID = 6;
    m.nama = "Beng-beng_Hazelnut";
    m.merek = "Beng-beng";
    m.kadaluarsa = "29/08/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 6);
    pc = celmc(ps);
    pp = SearchP(p, "Snack");
    InsertChild(p, pp, pc);

    m.ID = 7;
    m.nama = "Piattoz_bbq";
    m.merek = "Piattoz";
    m.kadaluarsa = "16/02/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 7);
    pc = celmc(ps);
    pp = SearchP(p, "Snack");
    InsertChild(p, pp, pc);

    m.ID = 8;
    m.nama = "Piattoz_Sapi_Panggang";
    m.merek = "Piattoz";
    m.kadaluarsa = "16/02/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 8);
    pc = celmc(ps);
    pp = SearchP(p, "Snack");
    InsertChild(p, pp, pc);

    m.ID = 9;
    m.nama = "Richeese_nabati";
    m.merek = "Richeese";
    m.kadaluarsa = "22/02/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 9);
    pc = celmc(ps);
    pp = SearchP(p, "Snack");
    InsertChild(p, pp, pc);

    m.ID = 10;
    m.nama = "Richeese_nabati_Banana";
    m.merek = "Richeese";
    m.kadaluarsa = "22/02/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 10);
    pc = celmc(ps);
    pp = SearchP(p, "Snack");
    InsertChild(p, pp, pc);

    m.ID = 11;
    m.nama = "Fullo_Twist";
    m.merek = "Fullo";
    m.kadaluarsa = "14/11/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 11);
    pc = celmc(ps);
    pp = SearchP(p, "Snack");
    InsertChild(p, pp, pc);

    m.ID = 12;
    m.nama = "Fullo_Vanilla";
    m.merek = "Fullo";
    m.kadaluarsa = "14/11/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 12);
    pc = celmc(ps);
    pp = SearchP(p, "Snack");
    InsertChild(p, pp, pc);

    m.ID = 13;
    m.nama = "Good_time";
    m.merek = "Good_time";
    m.kadaluarsa = "19/01/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 13);
    pc = celmc(ps);
    pp = SearchP(p, "Snack");
    InsertChild(p, pp, pc);

    m.ID = 14;
    m.nama = "Good_time";
    m.merek = "Good_time";
    m.kadaluarsa = "19/01/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 14);
    pc = celmc(ps);
    pp = SearchP(p, "Snack");
    InsertChild(p, pp, pc);

    m.ID = 15;
    m.nama = "Roma_biscuit_kelapa";
    m.merek = "Roma";
    m.kadaluarsa = "29/12/22";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 15);
    pc = celmc(ps);
    pp = SearchP(p, "Snack");
    InsertChild(p, pp, pc);


    m.ID = 16;
    m.nama = "Malkist_crackers";
    m.merek = "Malkist";
    m.kadaluarsa = "02/09/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 16);
    pc = celmc(ps);
    pp = SearchP(p, "Snack");
    InsertChild(p, pp, pc);


    m.ID = 17;
    m.nama = "Malkist_abon";
    m.merek = "Malkist";
    m.kadaluarsa = "02/09/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 17);
    pc = celmc(ps);
    pp = SearchP(p, "Snack");
    InsertChild(p, pp, pc);


    m.ID = 18;
    m.nama = "Morillo_balado";
    m.merek = "Morillo";
    m.kadaluarsa = "20/06/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 18);
    pc = celmc(ps);
    pp = SearchP(p, "Snack");
    InsertChild(p, pp, pc);

    m.ID = 19;
    m.nama = "Morillo_cream";
    m.merek = "Morillo";
    m.kadaluarsa = "20/06/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 19);
    pc = celmc(ps);
    pp = SearchP(p, "Snack");
    InsertChild(p, pp, pc);

//Instant

    m.ID = 20;
    m.nama = "Samyang_curry";
    m.merek = "Samyang";
    m.kadaluarsa = "27/09/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 20);
    pc = celmc(ps);
    pp = SearchP(p, "Instant");
    InsertChild(p, pp, pc);

    m.ID = 21;
    m.nama = "Pisang_lumer";
    m.merek = "pisang_lumer";
    m.kadaluarsa = "15/02/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 21);
    pc = celmc(ps);
    pp = SearchP(p, "Instant");
    InsertChild(p, pp, pc);


    m.ID = 22;
    m.nama = "Fiesta_chicken_nugget";
    m.merek = "Fiesta";
    m.kadaluarsa = "08/01/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 22);
    pc = celmc(ps);
    pp = SearchP(p, "Instant");
    InsertChild(p, pp, pc);


    m.ID = 23;
    m.nama = "Fiesta_spicy_wings";
    m.merek = "Fiesta";
    m.kadaluarsa = "07/01/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 23);
    pc = celmc(ps);
    pp = SearchP(p, "Instant");
    InsertChild(p, pp, pc);

    m.ID = 24;
    m.nama = "Fiesta_stikie";
    m.merek = "Fiesta";
    m.kadaluarsa = "09/01/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 24);
    pc = celmc(ps);
    pp = SearchP(p, "Instant");
    InsertChild(p, pp, pc);


    m.ID = 25;
    m.nama = "Indomie_goreng";
    m.merek = "Indomie";
    m.kadaluarsa = "26/07/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 25);
    pc = celmc(ps);
    pp = SearchP(p, "Instant");
    InsertChild(p, pp, pc);


    m.ID = 26;
    m.nama = "Indomie_kuah_kari_ayam";
    m.merek = "Indomie";
    m.kadaluarsa = "26/04/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 26);
    pc = celmc(ps);
    pp = SearchP(p, "Instant");
    InsertChild(p, pp, pc);

    m.ID = 27;
    m.nama = "Indomie_kuah_soto";
    m.merek = "Indomie";
    m.kadaluarsa = "26/04/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 27);
    pc = celmc(ps);
    pp = SearchP(p, "Instant");
    InsertChild(p, pp, pc);

    m.ID = 28;
    m.nama = "Mie_sedaap_goreng";
    m.merek = "Mie_sedaap";
    m.kadaluarsa = "16/11/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 28);
    pc = celmc(ps);
    pp = SearchP(p, "Instant");
    InsertChild(p, pp, pc);

    m.ID = 29;
    m.nama = "Mie_sedaap_cup";
    m.merek = "Mie_sedaap";
    m.kadaluarsa = "06/05/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 29);
    pc = celmc(ps);
    pp = SearchP(p, "Instant");
    InsertChild(p, pp, pc);

//Permen

    m.ID = 30;
    m.nama = "Fox's";
    m.merek = "Fox's";
    m.kadaluarsa = "11/12/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 30);
    pc = celmc(ps);
    pp = SearchP(p, "Permen");
    InsertChild(p, pp, pc);

    m.ID = 31;
    m.nama = "Chupa_Chups";
    m.merek = "Chupa_Chups";
    m.kadaluarsa = "20/03/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 31);
    pc = celmc(ps);
    pp = SearchP(p, "Permen");
    InsertChild(p, pp, pc); //gak usah digant

    m.ID = 32;
    m.nama = "Mentos_rainbow";
    m.merek = "Mentos";
    m.kadaluarsa = "11/02/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 32);
    pc = celmc(ps);
    pp = SearchP(p, "Permen");
    InsertChild(p, pp, pc);

    m.ID = 33;
    m.nama = "Mentos_mint";
    m.merek = "Mentos";
    m.kadaluarsa = "11/02/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 33);
    pc = celmc(ps);
    pp = SearchP(p, "Permen");
    InsertChild(p, pp, pc);


    m.ID = 34;
    m.nama = "Milkita_strawberry";
    m.merek = "Milkita";
    m.kadaluarsa = "04/05/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 34);
    pc = celmc(ps);
    pp = SearchP(p, "Permen");
    InsertChild(p, pp, pc);

    m.ID = 35;
    m.nama = "Milkita_chocolate";
    m.merek = "Milkita";
    m.kadaluarsa = "04/05/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 35);
    pc = celmc(ps);
    pp = SearchP(p, "Permen");
    InsertChild(p, pp, pc);

    m.ID = 36;
    m.nama = "Milkita_vanilla";
    m.merek = "Milkita";
    m.kadaluarsa = "04/05/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 36);
    pc = celmc(ps);
    pp = SearchP(p, "Permen");
    InsertChild(p, pp, pc);

    m.ID = 37;
    m.nama = "Kopiko";
    m.merek = "Kopiko";
    m.kadaluarsa = "07/04/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 37);
    pc = celmc(ps);
    pp = SearchP(p, "Permen");
    InsertChild(p, pp, pc);

    m.ID = 38;
    m.nama = "Yupi_baby_bears";
    m.merek = "Yupi";
    m.kadaluarsa = "02/03/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 38);
    pc = celmc(ps);
    pp = SearchP(p, "Permen");
    InsertChild(p, pp, pc);

    m.ID = 39;
    m.nama = "Fisherman_cherry";
    m.merek = "Fisherman";
    m.kadaluarsa = "07/04/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 39);
    pc = celmc(ps);
    pp = SearchP(p, "Permen");
    InsertChild(p, pp, pc);

    m.ID = 40;
    m.nama = "Yupi_burger";
    m.merek = "Yupi";
    m.kadaluarsa = "02/03/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 40);
    pc = celmc(ps);
    pp = SearchP(p, "Permen");
    InsertChild(p, pp, pc);

    m.ID = 41;
    m.nama = "Fisherman_original";
    m.merek = "Fisherman";
    m.kadaluarsa = "17/06/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 41);
    pc = celmc(ps);
    pp = SearchP(p, "Permen");
    InsertChild(p, pp, pc);

    m.ID = 42;
    m.nama = "Fisherman_citrus";
    m.merek = "Fisherman";
    m.kadaluarsa = "17/05/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 42);
    pc = celmc(ps);
    pp = SearchP(p, "Permen");
    InsertChild(p, pp, pc);

// Coklat

    m.ID = 43;
    m.nama = "Toblerone_chocolate";
    m.merek = "Toblerone";
    m.kadaluarsa = "22/03/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 43);
    pc = celmc(ps);
    pp = SearchP(p, "Coklat");
    InsertChild(p, pp, pc);

    m.ID = 44;
    m.nama = "Toblerone_white_chocolate";
    m.merek = "Toblerone";
    m.kadaluarsa = "22/03/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 44);
    pc = celmc(ps);
    pp = SearchP(p, "Coklat");
    InsertChild(p, pp, pc);


    m.ID = 45;
    m.nama = "Hershey's_milk_chocolate";
    m.merek = "Hershey's";
    m.kadaluarsa = "13/04/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 45);
    pc = celmc(ps);
    pp = SearchP(p, "Coklat");
    InsertChild(p, pp, pc);

    m.ID = 46;
    m.nama = "Hershey's_dark_chocolate";
    m.merek = "Hershey's";
    m.kadaluarsa = "13/04/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 46);
    pc = celmc(ps);
    pp = SearchP(p, "Coklat");
    InsertChild(p, pp, pc);

    m.ID = 47;
    m.nama = "Ferrero_Rocher";
    m.merek = "Ferrero_Rocher";
    m.kadaluarsa = "14/02/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 47);
    pc = celmc(ps);
    pp = SearchP(p, "Coklat");
    InsertChild(p, pp, pc);

    m.ID = 48;
    m.nama = "SilverQueen_ChunkyBar";
    m.merek = "SilverQueen";
    m.kadaluarsa = "03/03/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 48);
    pc = celmc(ps);
    pp = SearchP(p, "Coklat");
    InsertChild(p, pp, pc);

    m.ID = 49;
    m.nama = "SilverQueen_bites";
    m.merek = "SilverQueen";
    m.kadaluarsa = "03/06/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 49);
    pc = celmc(ps);
    pp = SearchP(p, "Coklat");
    InsertChild(p, pp, pc);

    m.ID = 50;
    m.nama = "SilverQueen_Rock'R";
    m.merek = "SilverQueen";
    m.kadaluarsa = "03/06/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 50);
    pc = celmc(ps);
    pp = SearchP(p, "Coklat");
    InsertChild(p, pp, pc);

    m.ID = 51;
    m.nama = "Cadbury_dairy_milk";
    m.merek = "Cadbury";
    m.kadaluarsa = "25/01/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 51);
    pc = celmc(ps);
    pp = SearchP(p, "Coklat");
    InsertChild(p, pp, pc);

    m.ID = 52;
    m.nama = "Cadbury_hazelnut";
    m.merek = "Cadbury";
    m.kadaluarsa = "26/01/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 52);
    pc = celmc(ps);
    pp = SearchP(p, "Coklat");
    InsertChild(p, pp, pc);

//Minuman

    m.ID = 53;
    m.nama = "Sprite";
    m.merek = "Coca_Cola";
    m.kadaluarsa = "18/12/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 53);
    pc = celmc(ps);
    pp = SearchP(p, "Minuman");
    InsertChild(p, pp, pc);

    m.ID = 54;
    m.nama = "Fanta_orange";
    m.merek = "Coca_Cola";
    m.kadaluarsa = "30/12/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 54);
    pc = celmc(ps);
    pp = SearchP(p, "Minuman");
    InsertChild(p, pp, pc);


    m.ID = 55;
    m.nama = "Fanta_merah";
    m.merek = "Coca_Cola";
    m.kadaluarsa = "30/12/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 55);
    pc = celmc(ps);
    pp = SearchP(p, "Minuman");
    InsertChild(p, pp, pc);

    m.ID = 56;
    m.nama = "Coca-cola_diet_coke";
    m.merek = "Coca_Cola";
    m.kadaluarsa = "30/11/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 56);
    pc = celmc(ps);
    pp = SearchP(p, "Minuman");
    InsertChild(p, pp, pc);

    m.ID = 57;
    m.nama = "Fruit_tea_apple";
    m.merek = "Fruit_tea";
    m.kadaluarsa = "31/03/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 57);
    pc = celmc(ps);
    pp = SearchP(p, "Minuman");
    InsertChild(p, pp, pc);

    m.ID = 58;
    m.nama = "Fruit_tea_blackcurant";
    m.merek = "Fruit_tea";
    m.kadaluarsa = "31/03/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 58);
    pc = celmc(ps);
    pp = SearchP(p, "Minuman");
    InsertChild(p, pp, pc);

    m.ID = 59;
    m.nama = "Pocari_sweet";
    m.merek = "Pocari";
    m.kadaluarsa = "28/03/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 59);
    pc = celmc(ps);
    pp = SearchP(p, "Minuman");
    InsertChild(p, pp, pc);

    m.ID = 60;
    m.nama = "Aqua";
    m.merek = "Aqua";
    m.kadaluarsa = "25/03/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 60);
    pc = celmc(ps);
    pp = SearchP(p, "Minuman");
    InsertChild(p, pp, pc);

    m.ID = 61;
    m.nama = "Ultra_milk_coklat";
    m.merek = "Ultra_milk";
    m.kadaluarsa = "16/06/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 61);
    pc = celmc(ps);
    pp = SearchP(p, "Minuman");
    InsertChild(p, pp, pc);

    m.ID = 62;
    m.nama = "Ultra_milk_strawberry";
    m.merek = "Ultra_milk";
    m.kadaluarsa = "16/06/23";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 62);
    pc = celmc(ps);
    pp = SearchP(p, "Minuman");
    InsertChild(p, pp, pc);


    m.ID = 63;
    m.nama = "You_c1000_apple";
    m.merek = "You_C1000";
    m.kadaluarsa = "01/05/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 63);
    pc = celmc(ps);
    pp = SearchP(p, "Minuman");
    InsertChild(p, pp, pc);


    m.ID = 64;
    m.nama = "You_c1000_orange";
    m.merek = "You_C1000";
    m.kadaluarsa = "01/05/24";
    ps = celms(m);
    InsertL(s, ps);

    ps = SearchS(s, 64);
    pc = celmc(ps);
    pp = SearchP(p, "Minuman");
    InsertChild(p, pp, pc);
}
