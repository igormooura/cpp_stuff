#include <bits/stdc++.h>

#define endl '\n'
#define MOD 1e9+7

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;
using tiii = tuple<int, int, int>;
const ll INF = 4e18;

void bfs(string origem, string destino){
    vector<pii> movimentos = {
        {2,1}, {2,-1}, {1,2}, {1,-2},
        {-1,2}, {-1,-2}, {-2,1}, {-2,-1}
    };

    int x = origem[0] - 'a';
    int y = origem[1] - '1';

    int destinoX = destino[0] - 'a';
    int destinoY = destino[1] - '1';

    vector<vector<int>> dist(8, vector<int>(8, -1));

    queue<pii> fila;

    fila.push({x, y});
    dist[x][y] = 0;

    while(!fila.empty()) {
        pii atual = fila.front();
        fila.pop();

        x = atual.first;
        y = atual.second;

        if(x == destinoX && y == destinoY) {
            cout << dist[x][y] << endl;
            return;
        }

        for(auto movimento : movimentos) {
            int nx = x + movimento.first;
            int ny = y + movimento.second;

            if(nx >= 0 && nx < 8 && ny >= 0 && ny < 8 &&
               dist[nx][ny] == -1) {

                dist[nx][ny] = dist[x][y] + 1;
                fila.push({nx, ny});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n; 

    for(int i = 0; i < n; i++) {        
        string origem, destino;
        cin >> origem >> destino;

        bfs(origem, destino);
    }
    
    return 0;
}