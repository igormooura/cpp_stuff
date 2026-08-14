#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

vector<vector<int>> g;
vector<bool> vis;
vector<int> traffic;

void dfs(int u)
{
    vis[u] = true;
    traffic[u] = g[u].size();

    for (int v : g[u])
    {
        if (!vis[v])
            dfs(v);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, v, teste = 1;

    while (cin >> a >> v && (a || v))
    {
        g.assign(a + 1, {});
        vis.assign(a + 1, false);
        traffic.assign(a + 1, 0);

        for (int i = 0; i < v; i++)
        {
            int x, y;
            cin >> x >> y;

            g[x].push_back(y);
            g[y].push_back(x);
        }

        for (int i = 1; i <= a; i++)
        {
            if (!vis[i])
                dfs(i);
        }

        int maior = 0;

        for (int i = 1; i <= a; i++)
        {
            maior = max(maior, traffic[i]);
        }

        cout << "Teste " << teste++ << endl;

        for (int i = 1; i <= a; i++)
        {
            if (traffic[i] == maior)
                cout << i << " ";
        }

        cout << endl
             << endl;
    }

    return 0;
}

// https://neps.academy/exercise/290