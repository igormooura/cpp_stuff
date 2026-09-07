#include <bits/stdc++.h>

#define endl '\n'
#define MOD 1e9+7

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;
using tiii = tuple<int, int, int>;

vector<ll> seg;
vector<ll> a;

ll build(ll p, ll l, ll r){
    if( l == r) return seg[p] = a[l];
    
    int m = (l + r) / 2;

    build(2*p, l, m);
    build(2*p+1, m + 1, r);

    return seg[p] = seg[p*2] + seg[p*2+1];
}

ll query(ll a, ll b, ll p, ll l, ll r){ 
    if(b< l || r < a) return 0;
    if(a <= l && r <= b) return seg[p];

    int m = (l + r )/2;

    return query(a, b, 2*p, l, m) + query(a, b, 2*p + 1, m+1, r);

}

ll update(ll i, ll x, ll p, ll l, ll r){
    if(i < l || r < i)
        return seg[p];

    if(l == r)
        return seg[p] = x;

    int m = (l + r) / 2;

    update(i, x, 2*p, l, m);
    update(i, x, 2*p+1, m+1, r);

    return seg[p] = seg[2*p] + seg[2*p+1];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    a.resize(n);
    seg.assign(4*n, 0);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    build(1, 0, n-1);

    ll op, x, y;

    while(m--){
        cin >> op >> x >> y;

        if(op == 1){
            update(x, y, 1, 0, n-1);
        }
        else{
            cout << query(x, y - 1, 1, 0, n-1) << endl;
        }
    }

    return 0;
}