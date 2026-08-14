#include <bits/stdc++.h>

#define endl '\n'
#define MOD 1e9+7


using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;
using tiii = tuple<int, int, int>;
const ll INF = 4e18;

const int MAX = 1e3+10;

vector<vi> g(MAX);
vector<bool> vis(MAX);

void dfs(int v){

    vis[v] = true;

    for(auto w : g[v]){
        if(!vis[w]){
            dfs(w);
        }
    }

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;

    for(int k = 0; k < m; k++){
        int i, j; cin >> i >> j; i--, j--;
    
        // por nao ser direcionado
        g[i].push_back(j);
        g[j].push_back(i);
    }
    
    int times = 0;

    for(int i = 0; i< n; i++) if(!vis[i]){ 
        dfs(i);
        times++;
    }

    cout << times << endl;

    return 0;
}

//https://olimpiada.ic.unicamp.br/pratique/pj/2011/f2/gincana/