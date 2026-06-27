#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> seg;
vector<ll> a;

void build(int p, int l, int r)
{
    if (l == r)
    {
        seg[p] = (l == 0 ? 0 : a[l] > a[l - 1]);
        return;
    }

    int m = (l + r) / 2;

    build(2 * p, l, m);
    build(2 * p + 1, m + 1, r);

    seg[p] = seg[2 * p] + seg[2 * p + 1];
}

ll query(int ql, int qr, int p, int l, int r)
{
    if (qr < l || r < ql)
        return 0;

    if (ql <= l && r <= qr)
        return seg[p];

    int m = (l + r) / 2;

    return query(ql, qr, 2 * p, l, m) +
           query(ql, qr, 2 * p + 1, m + 1, r);
}

void update(int i, int p, int l, int r)
{
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    a.resize(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    seg.assign(4 * n, 0);

    build(1, 0, n - 1);

    vector<ll> ans;

    while (q--)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            int l, r;
            cin >> l >> r;

            l--;
            r--;

            if (l == r)
            {
                ans.push_back(0);
                continue;
            }

            ans.push_back(query(l + 1, r, 1, 0, n - 1));
        }
        else
        {
            int i;
            ll x;

            cin >> i >> x;

            i--;

            a[i] = x;

            update(i, 1, 0, n - 1);

            if (i + 1 < n)
                update(i + 1, 1, 0, n - 1);
        }
    }

    for (auto x : ans)
        cout << x << endl;
}
