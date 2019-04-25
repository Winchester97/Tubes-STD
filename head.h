#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include <cstddef>
#include <string>
#include <iostream>
#include <stdlib.h>

#define mfirst(L) L.mfirst
#define kfirst(L) L.kfirst
#define k_info(L) L->k_info
#define m_info(L) L->m_info
#define d_mnext(L) L->d_mnext
#define s_mnext(L) L->s_mnext
#define d_knext(L) L->d_knext
#define s_knext(L) L->s_knext
#define s_rnext(L) L->s_rnext
#define d_rnext(L) L->d_rnext
#define prev(L) L->prev
#define NIL NULL

using namespace std;

typedef string infotype;
typedef struct elm_mbl *m_adr;
typedef struct elm_kry *k_adr;
typedef struct elm_rls *r_adr;

struct elm_mbl {
    infotype m_info;
    m_adr d_mnext;
    r_adr s_mnext;
};

struct elm_kry {
    infotype k_info;
    k_adr d_knext;
};

struct elm_rls {
    k_adr d_rnext;
    r_adr s_rnext;
};

struct mList{
    m_adr mfirst;
};

struct kList{
    k_adr kfirst;
};

void Menu();
void Header();
void printInfo(mList L, kList K);
void createRel (mList L, kList K, infotype mobil, infotype montir);
k_adr kSearch (infotype montir, kList L);
m_adr mSearch (infotype mobil, mList L);
void k_insert (kList &L, k_adr P);
void m_insert (mList &L, m_adr P);
void createkList(kList &L);
void createmList(mList &L);
k_adr k_Allocation(infotype X);
m_adr m_Allocation(infotype X);
r_adr r_Allocation();
bool ismEmpty (mList L);
bool iskEmpty (kList L);
void k_MostFix (mList L, kList K,k_adr &sMax);
void del_Mobil (mList &L,infotype mobil, m_adr &Q);
void del_Montir (mList &L2, kList &L, infotype montir, k_adr &Q);
void printCarofMech (mList L, kList K, infotype montir);
void printCarof2Mech(mList L, kList K);
void showData(mList L, kList K);
void showData(mList L, kList K);
void menuKerusakan (mList L, kList K);

#endif // HEAD_H_INCLUDED
