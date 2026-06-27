#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

bitset<2010> vis;

int n, d;

vector<pii> stars;
vector<vector<bool>> adj(2010, vector<bool>(2010, false));

int dist(int i, int j){
    int dx = stars[i].first - stars[j].first;
    int dy = stars[i].second - stars[j].second;

    return ceil(sqrt(dx * dx + dy * dy));
}

int dfs(int x){

    cout << "Visitando estrela " << x << '\n';

    vis[x] = 1;

    cout << "vis[" << x << "] agora e true\n";

    int constelation = 1;

    for (int i = 0; i < n; i++)
    {

        if (i == x || vis[i] || !adj[x][i])
            continue;

        cout << "Achei vizinho de "
             << x << ": " << i << '\n';

        constelation += dfs(i);
    }

    return constelation;
}

void solve(){

    cin >> n >> d;

    stars.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> stars[i].first >> stars[i].second;
    }

    cout << "\nCriando o grafo...\n";

    for (int i = 0; i < n; i++){

        for (int j = i + 1; j < n; j++){

            int distance = dist(i, j);

            cout << "Distancia "
                 << i << "-" << j
                 << " = "
                 << distance << '\n';

            if (distance <= d){

                cout << "Distancia valida, criando aresta\n";

                adj[i][j] = true;
                adj[j][i] = true;

                cout << "adj[" << i << "][" << j << "] = true\n";
                cout << "adj[" << j << "][" << i << "] = true\n";
            }
        }
    }

    cout << "\nResetando visitados...\n";

    vis.reset();

    cout << "Todos os vertices agora estao como nao visitados\n";

    int maxC = 0;

    for (int i = 0; i < n; i++){

        if (!vis[i]){

            cout << "\nComecando nova DFS em " << i << '\n';

            int size = dfs(i);

            cout << "Constelacao encontrada: "
                 << size << " estrelas\n";

            maxC = max(maxC, size);
        }
    }

    cout << "\nMaior constelacao: "
         << maxC << '\n';
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}