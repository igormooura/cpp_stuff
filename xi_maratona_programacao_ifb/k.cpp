#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

bitset<2010> vis;
vector<pii> stars;
vector<vector<bool>> adj(2010, vector<bool>(2010));

int n, d;

int dist(int i, int j) {
    int dx = stars[i].first - stars[j].first;
    int dy = stars[i].second - stars[j].second;

    return ceil(sqrt(dx * dx + dy * dy));
}

int dfs(int x) {
    vis[x] = 1;

    int constellation = 1;

    for (int i = 0; i < n; i++) {
        if (i == x || vis[i] || !adj[x][i])
            continue;

        constellation += dfs(i);
    }

    return constellation;
}

void solve() {
    cin >> n >> d;

    stars.resize(n);

    for (int i = 0; i < n; i++)
        cin >> stars[i].first >> stars[i].second;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dist(i, j) <= d) {
                adj[i][j] = true;
                adj[j][i] = true;
            }
        }
    }

    vis.reset();

    int maxC = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i])
            maxC = max(maxC, dfs(i));
    }

    cout << maxC << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}