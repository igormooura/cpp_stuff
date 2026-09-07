#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

vector<vi> cidades;
vector<bool> vis;

void dfs(int n){
    vis[n] = true;

    for(auto x : cidades[n]){
        if(!vis[x]){
            dfs(x);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cidades.resize(n);
    vis.resize(n, false);

    int v, w;

    while(cin >> v >> w){
        cidades[v].push_back(w);
        cidades[w].push_back(v);
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i);
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}