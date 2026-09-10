#include <bits/stdc++.h>
#define endl '\n'
#define MOD 1e9+7
using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;
using tiii = tuple<int, int, int>;
const ll INF = 4e18;

vector<vector<int>> g;
vector<bool> vis;
vector<int> pai;
int n, m;

void bfs(int s){
    queue<int> q;
    q.push(s);
    vis[s] = 1;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(auto u : g[v]){
            if(!vis[u]){
                q.push(u);
                vis[u] = 1;
                pai[u] = v;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    g.resize(n + 1);
    vis.resize(n + 1);
    pai.resize(n + 1);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    bfs(1);

    if(!vis[n]){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> caminho;
    int atual = n;

    while(atual != 0){
        caminho.push_back(atual);
        atual = pai[atual];
    }

    reverse(caminho.begin(), caminho.end());

    cout << caminho.size() << endl;

    for(auto v : caminho){
        cout << v << " ";
    }

    cout << endl;

    return 0;
}