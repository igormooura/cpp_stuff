#include <bits/stdc++.h>

#define endl '\n'
#define MOD 1e9+7

using namespace std;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using ll = long long;
using tiii = tuple<int, int, int>;

vll a;
vll seg;

void build(int p, int l, int r){ 
    if(l == r) {
        seg[p] = (l == 0 ? 0 : a[l] > a[l-1]);
        return;
    }

    int m = (l + r) / 2;
    
    build(2*p, l, m);
    build(2*p + 1, m + 1, r);

    seg[p] = seg[2*p] + seg[2*p + 1];
}

ll query (int ql, int qr, int p, int l, int r){ // ql e qr são numeros que a gente recebe
    if(qr < l || r < ql) return 0;
    if(ql <= l && r<= qr) return seg[p];

    int m = (l + r)/2;

    return query(ql, qr, 2*p, l, m) + query(ql, qr, 2*p + 1, m + 1, r);
}

void update(int i, int p, int l, int r){ 
    if (l == r)
    {
        seg[p] = (i == 0 ? 0 : a[i] > a[i - 1]);
        return;
    }

    int m = (l + r) / 2;

    if (i <= m)
        update(i, 2 * p, l, m);
    else
        update(i, 2 * p + 1, m + 1, r);

    seg[p] = seg[2 * p] + seg[2 * p + 1];
}

/*
BUILD:
- É segment tree de um array implícito b[]
  onde:
      b[i] = (a[i] > a[i - 1])
- chamar após ler o array
- build(1, 0, n-1)
- cria automaticamente o array auxiliar e monta a segtree

----------------------------------------

QUERY:
- query(ql, qr, 1, 0, n-1)

- responde:
    quantas vezes a[i] > a[i-1]
    dentro do intervalo

- atenção:
    normalmente usamos l+1 na query do problema
    porque comparação depende de i-1

----------------------------------------

UPDATE:
- sempre que mudar a[i]:

    a[i] = x;
    update(i, 1, 0, n-1);

- importante:
    também atualizar i+1, se existir, porque:
    b[i+1] depende de a[i]

    if (i+1 < n)
        update(i+1, 1, 0, n-1);
*/