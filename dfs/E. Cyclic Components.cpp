#include <bits/stdc++.h>

#define endl '\n'
#define MOD 1e9+7


using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;
using tiii = tuple<int, int, int>;
const ll INF = 4e18;

bool eh_ciclo;
vector<vi> adj;
vector<bool> vis;

void dfs(int i){
    vis[i] = true;

    if(adj[i].size() != 2) eh_ciclo = false;

    for(auto x : adj[i]){
        if(!vis[x]){
            dfs(x);
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m; 
    adj.resize(n + 1);
    vis.assign(n + 1, false);

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ciclos = 0; 
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            eh_ciclo = true; 
            dfs(i);

            if(eh_ciclo){
                ciclos++;
            }
        }
    }

    cout << ciclos << endl;
    

    return 0;
}