#include <bits/stdc++.h>

#define endl '\n'
#define MOD 1e9 + 7

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;
using tiii = tuple<int, int, int>;
const ll INF = 4e18;

vector<int> salas_gatos;
vector<vi> grafos;
vector<bool> vis;

int m;
int resposta = 0;

void dfs(int i, int consec){

    vis[i] = true;

    if(salas_gatos[i] == 1){ 
        consec++;
    } else { 
        consec = 0;
    }

    if(consec > m)  return;

    bool saida = true; 

    for (int v : grafos[i]) {
        if (!vis[v]) {
            saida = false;
            dfs(v, consec);
        }
    }

    if(saida)
        resposta++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n >> m;

    salas_gatos.resize(n + 1);
    grafos.resize(n + 1);
    vis.resize(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        cin >> salas_gatos[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, w;
        cin >> u >> w;

        grafos[u].push_back(w);
        grafos[w].push_back(u);
    }

    dfs(1, 0);

    cout << resposta << endl;

    return 0;
}