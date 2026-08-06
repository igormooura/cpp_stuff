#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;
using vll = vector<ll>;

vll a;
vll seg;
vll lazy;

/*
    seg[p]  -> soma do intervalo
    lazy[p] -> valor que ainda precisa ser propagado
*/

void build(int p, int l, int r){
    if(l == r){
        seg[p] = a[l];
        return;
    }

    int m = (l+r)/2;

    build(2*p, l, m);
    build(2*p+1, m+1, r);

    seg[p] = seg[2*p] + seg[2*p+1];
}

/*
    Empurra a atualização para os filhos
*/
void push(int p, int l, int r){

    if(lazy[p] == 0)
        return;

    seg[p] += (r-l+1) * lazy[p];

    if(l != r){
        lazy[2*p] += lazy[p];
        lazy[2*p+1] += lazy[p];
    }

    lazy[p] = 0;
}

/*
    adiciona x em [ql, qr]
*/
void update(int ql, int qr, ll x, int p, int l, int r){

    push(p,l,r);

    if(qr < l || r < ql)
        return;

    if(ql <= l && r <= qr){
        lazy[p] += x;
        push(p,l,r);
        return;
    }

    int m = (l+r)/2;

    update(ql,qr,x,2*p,l,m);
    update(ql,qr,x,2*p+1,m+1,r);

    seg[p] = seg[2*p] + seg[2*p+1];
}

ll query(int ql, int qr, int p, int l, int r){

    push(p,l,r);

    if(qr < l || r < ql)
        return 0;

    if(ql <= l && r <= qr)
        return seg[p];

    int m = (l+r)/2;

    return query(ql,qr,2*p,l,m)
         + query(ql,qr,2*p+1,m+1,r);
}