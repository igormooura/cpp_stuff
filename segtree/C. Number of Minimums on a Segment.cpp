#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> a;
vector<pair<ll,ll>> seg;

pair<ll,ll> merge(pair<ll,ll> a, pair<ll,ll> b) {
    if (a.first < b.first) return a;
    if (b.first < a.first) return b;
    return {a.first, a.second + b.second};
}

void build(int p, int l, int r) {
    if (l == r) {
        seg[p] = {a[l], 1};
        return;
    }

    int m = (l + r) / 2;

    build(2*p, l, m);
    build(2*p+1, m+1, r);

    seg[p] = merge(seg[2*p], seg[2*p+1]);
}

pair<ll,ll> query(int ql, int qr, int p, int l, int r) {
    if (qr < l || r < ql)
        return {LLONG_MAX, 0};

    if (ql <= l && r <= qr)
        return seg[p];

    int m = (l + r) / 2;

    return merge(
        query(ql, qr, 2*p, l, m),
        query(ql, qr, 2*p+1, m+1, r)
    );
}

void update(int idx, ll val, int p, int l, int r) {
    if (l == r) {
        seg[p] = {val, 1};
        return;
    }

    int m = (l + r) / 2;

    if (idx <= m)
        update(idx, val, 2*p, l, m);
    else
        update(idx, val, 2*p+1, m+1, r);

    seg[p] = merge(seg[2*p], seg[2*p+1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    a.resize(n);
    seg.resize(4*n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    build(1, 0, n-1);

    while (m--) {
        int op;
        cin >> op;

        if (op == 1) {
            int i;
            ll v;

            cin >> i >> v;

            a[i] = v;
            update(i, v, 1, 0, n-1);
        }
        else {
            int l, r;
            cin >> l >> r;

            auto ans = query(l, r-1, 1, 0, n-1);

            cout << ans.first << ' ' << ans.second << '\n';
        }
    }

    return 0;
}