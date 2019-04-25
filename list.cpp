#include "head.h"
void Header() {
    cout<<"     |=======================================================|\n";
    cout<<"     |                                                       |\n";
    cout<<"     |            BENGKEL MOBIL HASIL ABADI                  |\n";
    cout<<"     |                                                       |\n";
    cout<<"     |_______________________________________________________|\n\n\n";
}

void Menu() {
    cout<<"     |=======================================================|\n";
    cout<<"     |                                                       |\n";
    cout<<"     |            BENGKEL MOBIL HASIL ABADI                  |\n";
    cout<<"     |                                                       |\n";
    cout<<"     |_______________________________________________________|\n";
    cout<<"     |No.|                       Menu                        |\n";
    cout<<"     |---|---------------------------------------------------|\n";
    cout<<"     |1. | Menambahkan Montir Baru                           |\n";
    cout<<"     |2. | Menambahkan Mobil Baru                            |\n";
    cout<<"     |3. | Menambahkan Hubungan antara mobil dan montir      |\n";
    cout<<"     |4. | Menghapus Montir                                  |\n";
    cout<<"     |5. | Menghapus Mobil                                   |\n";
    cout<<"     |6. | Menampilkan daftar hubungannya antara mobil dan   |\n";
    cout<<"     |   | montir                                            |\n";
    cout<<"     |7. | Menampilkan montir yang paling banyak memperbaiki |\n";
    cout<<"     |   | mobil                                             |\n";
    cout<<"     |8. | Menambahkan daftar mobil yang pernah diperbaiki   |\n";
    cout<<"     |   | oleh montir tertentu                              |\n";
    cout<<"     |9. | Menampilkan daftar mobil yang pernah diperbaiki   |\n";
    cout<<"     |   | oleh lebih dari satu montir                       |\n";
    cout<<"     |10.| Menampilkan daftar mobil dan montir               |\n";
    cout<<"     |===|===================================================|\n";
    cout<<"     |0. | Exit                                              |\n";
    cout<<"     |___|___________________________________________________|\n";
}

void createmList(mList &L) {
    mfirst(L) = NULL;
}

void createkList(kList &L) {
    kfirst(L) = NULL;
}

bool ismEmpty (mList L) {
    if (mfirst(L) == NULL)
        return true;
    else
        return false;
}

bool iskEmpty (kList L) {
    if (kfirst(L) == NULL)
        return true;
    else
        return false;
}

r_adr r_Allocation(infotype X) {
    r_adr P = new elm_rls;
    s_rnext(P) = NULL;
    d_rnext(P) = NULL;
    return P;
}

m_adr m_Allocation(infotype X) {
    m_adr P = new elm_mbl;
    m_info(P) = X;
    d_mnext(P) = NULL;
    s_mnext(P) = NULL;
    return P;
}

k_adr k_Allocation(infotype X) {
    k_adr P = new elm_kry;
    k_info(P) = X;
    d_knext(P) = NULL;
    return P;
}

void m_insert (mList &L, m_adr P) {
    if (ismEmpty(L)) {
        mfirst(L) = P;
    } else {
        m_adr Q = mfirst(L);
        while (d_mnext(Q) != NULL) {
            Q = d_mnext(Q);
        } d_mnext(Q) = P;
    }
}

void k_insert (kList &L, k_adr P) {
    if (iskEmpty(L)) {
        kfirst(L) = P;
    } else {
        k_adr Q;
        Q = kfirst(L);
        while (d_knext(Q) != NULL) {
            Q = d_knext(Q);
        } d_knext(Q) = P;
    }
}

m_adr mSearch (infotype mobil, mList L) {
    m_adr P = mfirst(L);
    while ((m_info(P) != mobil) && (d_mnext(P) != NULL)) {
        P = d_mnext(P);
    } if (m_info(P) == mobil) {
        return P;
    } else {
        return NULL;
    }
}

k_adr kSearch (infotype montir, kList L) {
    k_adr P = kfirst(L);
    while ((k_info(P) != montir) && (d_knext(P) != NULL)) {
        P = d_knext(P);
    } if (k_info(P) == montir) {
        return P;
    } else {
        return NULL;
    }
}

void menuKerusakan (mList L, kList K) {
    int pil,loop,i;
    infotype mobil, montir;
    i = 1;
    cout<<"      _______________________________________________________\n";
    cout<<"     |No.|                  Tipe Kerusakan                   |\n";
    cout<<"     |---|---------------------------------------------------|\n";
    cout<<"     |1. | Wajar                                             |\n";
    cout<<"     |2. | Parah                                             |\n";
    cout<<"     |3. | Sangat parah                                      |\n";
    cout<<"     |___|___________________________________________________|\n";
    cout<<"     Pilihan(nomor) : ";
    cin>>pil;
    if (pil == 1) {
        cout<<"~~~~~~~~~  Mekanik yang dibutuhkan hanya 1  ~~~~~~~~~\n";
        cout<<"Merk Mobil : ";
        cin>>mobil;
        cout<<"Mobil "<<mobil<<" akan diperbaiki oleh: ";
        cin>>montir;
        createRel(L, K, mobil, montir);
    } else if (pil == 2) {
        cout<<"~~~~~~~~~  Mekanik yang dibutuhkan  ada  2  ~~~~~~~~~\n";
        do {
            cout<<"Merk Mobil : ";
            cin>>mobil;
            cout<<"Mobil "<<mobil<<" akan diperbaiki oleh: ";
            cin>>montir;
            createRel(L, K, mobil, montir);
            i++;
        } while (i <= 2);
    } else if (pil == 3) {
        cout<<"Masukkan mekanik yang dibutuhkan: ";
        cin>>loop;
        cout<<"\n~~~~~~~~~  Mekanik yang dibutuhkan  ada  "<<loop<<" ~~~~~~~\n";
        do {
            cout<<"Merk Mobil : ";
            cin>>mobil;
            cout<<"Mobil "<<mobil<<" akan diperbaiki oleh: ";
            cin>>montir;
            createRel(L, K, mobil, montir);
            i++;
        } while (i <= loop);
    } else cout<<"tidak ada pilihan"<<pil;
}

void createRel (mList L, kList K, infotype mobil, infotype montir) {
    if (!ismEmpty(L) && !iskEmpty(K)) {
        if (kSearch(montir, K) == NULL) {
            cout<<"Tidak ada montir dengan nama tsb \n";
        } if (mSearch(mobil, L) == NULL) {
            cout<<"Tidak ada mobil dengan merk tersebut \n";
        } else if ((kSearch(montir, K) != NULL) && (mSearch(mobil, L) != NULL)) {
            r_adr S = new elm_rls;
            r_adr Q = s_mnext(mSearch(mobil, L));
            if (Q != NULL) {
                while (s_rnext(Q) != NULL) {
                    Q = s_rnext(Q);
                }
                s_rnext(Q) = S;
            } else {
                s_mnext(mSearch(mobil,L)) = S;
            }
            d_rnext(S) = (kSearch(montir, K));
            s_rnext(S) = NULL;
        }
    } else {
        cout<<"List Empty \n";
    }
}

void showData(mList L, kList K) {
    if ((iskEmpty(K)) && (ismEmpty(L))) {
        cout<<"List mekanik & mobil masih kosong \n";
    } else {
        m_adr P = mfirst(L);
        k_adr S = kfirst(K);
        int i = 1;
        cout<<"             ______________________\n";
        cout<<"            |       ISI LIST       |\n";
        cout<<"            |______________________|\n\n";
        cout<<"          MOBIL: \n";
        cout<<"          _______________________\n";
        while (P != NULL) {
            cout<<"         |"<<i<<". |"<<m_info(P)<<"\t\t| "<<endl;
            P = d_mnext(P);
            i++;
        }cout<<"         |___|__________________|\n\n";
        cout<<"          MONTIR: \n";
        i = 1;
        cout<<"          _______________________\n";
        while (S != NULL) {
            cout<<"         |"<<i<<". |"<<k_info(S)<<"\t\t| "<<endl;
            S = d_knext(S);
            i++;
        } cout<<"         |___|__________________|\n";
    }
}

void printInfo(mList L, kList K) {
    if ((iskEmpty(K)) || (ismEmpty(L))) {
        cout<<"List mekanik / mobil masih kosong \n";
    } else {
        m_adr P = mfirst(L);
        r_adr J;
        int i = 1;
        while (P != NULL) {
            cout<<i<<".  Mobil  : "<<m_info(P);
            i++;
            J = s_mnext(P);
            if (J != NULL) {
                cout<<"\t | Montir : "<<k_info(d_rnext(J))<<endl;
                J = s_rnext(J);
            }
            while (J != NULL) {
                cout<<"\t\t\t |          "<<k_info(d_rnext(J))<<endl;
                J = s_rnext(J);
            } cout<<endl;
            P = d_mnext(P);
        }
    }
}

void del_Mobil (mList &L,infotype mobil, m_adr &Q) {
    r_adr R;
    r_adr Prec2;
    m_adr P = mfirst(L);
    m_adr Prec = mSearch(mobil, L);
    if (ismEmpty(L)) {
        cout<<"List masih belum terisi \n";
    } else {
        if (Prec == NULL){
            Q = NULL;
            cout<<"Tidak ada mobil dengan merk tsb \n";
        } else {
            R = s_mnext(Prec);
            while(R != NULL){
                Prec2 = R;
                R = s_rnext(R);
                delete Prec2;
            }
            if (P == Prec ) {
                mfirst(L) = d_mnext(P);
                d_mnext(P) = NULL;
            } else {
                if (d_mnext(Prec) == NULL) {
                    while (d_mnext(P) != Prec) {
                        P = d_mnext(P);
                    } d_mnext(P) = NULL;
                    P = Prec;
                } else {
                    while (d_mnext(P) != Prec) {
                        P = d_mnext(P);
                    } d_mnext(P) = d_mnext(Prec);
                    d_mnext(Prec) = NULL;
                    P = Prec;
                }
            } Q = P;
        }
    }
}

void del_Montir (mList &L2, kList &L, infotype montir, k_adr &Q) {
    bool cek;
    r_adr R;
    r_adr Prec2;
    m_adr S = mfirst(L2);
    k_adr P = kfirst(L);
    k_adr Prec = kSearch (montir, L);
    if (iskEmpty(L)) {
        cout<<"List masih belum terisi \n";
    } else {
        if (Prec == NULL) {
            Q = NULL;
            cout<<"Tidak ada montir dengan nama tsb \n";

        } else {
            cek = false;
            while (S != NULL){
                R = s_mnext(S);
                while((R != NULL) && (cek)){
                    if(d_rnext(R) == Prec){
                        if(R == s_mnext(S)){
                            Prec2 = R;
                            R = s_rnext(R);
                        }else if(s_rnext(R) == NULL){
                            Prec2 = R;
                        }else{
                            s_rnext(Prec2) = s_rnext(R);
                            s_rnext(R) =NULL;
                        }
                        delete Prec2;
                        cek = true;
                    }else{
                        Prec2 = R;
                        R = s_rnext(R);
                    }
                }
                S = d_mnext(S);
            }
            if (P == Prec ) {
                if(d_knext(Prec)== NULL){
                    kfirst(L) = NULL;
                }else{
                    kfirst(L) = d_knext(P);
                    d_knext(P) = NULL;
                }
            } else {
                if (d_knext(Prec) == NULL) {
                    while (d_knext(P) != Prec) {
                        P = d_knext(P);
                    }
                    d_knext(P) = NULL;
                    P = Prec;
                } else {
                    while (d_knext(P) != Prec) {
                        P = d_knext(P);
                    }
                    d_knext(P) = d_knext(Prec);
                    d_knext(Prec) = NULL;
                    P = Prec;
                }
            } Q = P;
        }
    }
}

void k_MostFix (mList L, kList K,k_adr &sMax) {
    if (iskEmpty(K)) {
        cout<"List Masih Kosong \n";
    } else {
        int temp = 0;
        int maks = 0;
        m_adr P;
        k_adr S = kfirst(K);
        r_adr Y;
        bool cek = false;
        P = mfirst(L);

        while(P != NULL) {
            Y = s_mnext(P);
            while ((Y != NULL) && (cek == false))  {
                if (d_rnext(Y) == S){
                    maks = maks + 1;
                    cek = true;
                } else {
                    Y = s_rnext(Y);
                }
            } P = d_mnext(P);
        } sMax = S;
        S = d_knext(kfirst(K));
        cek = false;
        //cek list child//
        while (S != NULL) {
            P = mfirst(L);
            while(P != NULL) {
                Y = s_mnext(P);
                while ((Y != NULL) && (cek == false)) {
                    if (d_rnext(Y) == S){
                        temp = temp + 1;
                        cek = true;
                    } else {
                        Y = s_rnext(Y);
                    }
                } cek = false;
                if (temp > maks) {
                    maks = temp;
                    sMax = S;
                } P = d_mnext(P);
            } S = d_knext(S);
            temp = 0;
        } cout<<"Montir yang paling banyak memperbaiki mobil: "<<k_info(sMax)<<" Sebanyak : "<<maks<<endl;
    }
}

void printCarofMech (mList L, kList K, infotype montir) {
    if ((iskEmpty(K)) || (ismEmpty(L))) {
        cout<<"List mekanik / mobil masih kosong \n";
    } else {
        m_adr P = mfirst(L);
        k_adr S = kSearch(montir,K);
        r_adr R;
        bool cek = false;
        if (S == NULL) {
            cout<<"Tidak ada montir dengan nama tsb \n";
        } else {
            cout<<"Montir "<<k_info(S)<<" Pernah memperbaiki: \n";
            while (P != NULL) {
                R = s_mnext(P);
                while ((R != NULL) && (cek == false))  {
                    if (d_rnext(R) == S){
                        if (s_rnext(R) == NULL) cout<<m_info(P)<<".";
                        else cout<<m_info(P)<<", ";
                        cek = true;
                    } else {
                        R = s_rnext(R);
                    }
                } P = d_mnext(P);
                cek = false;
            }
        } cout<<endl;
    }
}

void printCarof2Mech(mList L, kList K) {
    if ((iskEmpty(K)) || (ismEmpty(L))) {
        cout<<"List mekanik / mobil masih kosong \n";
    } else {
        m_adr P = mfirst(L);
        k_adr S = kfirst(K);
        r_adr R;
        bool cek;
        while (P != NULL) {
            cek = false;
            R = s_mnext(P);
            if (R != NULL) {
                if (s_rnext(R) != NULL) {
                    cek = true;
                    cout<<"Mobil : "<<m_info(P)<<" Telah diperbaiki oleh lebih dari 2 montir yaitu: \n";
                }
            } while ((cek) && (R != NULL)) {
                cout<<k_info(d_rnext(R))<<", ";
                R = s_rnext(R);
                if (R == NULL) {
                    cek = false;
                }
            }
            cout<<endl;
            P = d_mnext(P);
        }
    }
}
