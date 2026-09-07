#include <bits/stdc++.h>

#define endl '\n'
#define MOD 1e9+7

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;
using tiii = tuple<int, int, int>;

const ll INF = 4e18;

vi seg;
vi a;

ll build(ll p, ll l, ll r){ 
    if( l == r) return seg[p] = a[l];

    ll m = (r + l)/2;

    return seg[p] = min(build(2*p, l, m), build(2*p+1, m +1, r));
}

ll query(ll a, ll b, ll p, ll l, ll r){
    if(b < l || r < a) return INF;
    if(a <= l && r <= b) return seg[p];

    ll m = (r+l)/2;

    return min(query(a, b, 2*p,l,m), query(a,b,2*p+1, m + 1, r));
}

ll update(ll i, ll x, ll p, ll l, ll r){ 
    if(i < l || r < i) return seg[p];
    if(l == r) return seg[p] = x; 

    ll m = (r + l )/2;

    return seg[p] = min(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m + 1, r));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    a.resize(n);
    seg.assign(4*n, 0);
    
    for(int i = 0; i < n; i++) cin >> a[i];
    
    build(1,0,n-1);
    ll op, v1, v2;

    while(m--){
        cin >> op >> v1 >> v2;

        if(op == 1){ 
            update(v1,v2, 1, 0, n - 1);    
        } else  {
            cout << query(v1, v2 - 1, 1, 0, n - 1) << '\n';
        }
    }
    
    return 0;
}