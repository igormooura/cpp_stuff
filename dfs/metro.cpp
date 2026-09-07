#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grafo;
vector<int> visitado, pai;
vector<bool> no_ciclo;

void dfs(int v, int p) {
    visitado[v] = 1;
    pai[v] = p;

    for (int u : grafo[v]) {
        if (u == p) continue;

        if (visitado[u] == 0) {
            dfs(u, v);
        } else if (visitado[u] == 1) {
            int atual = v;

            while (atual != u) {
                no_ciclo[atual] = true;
                atual = pai[atual];
            }

            no_ciclo[u] = true;
        }
    }

    visitado[v] = 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    grafo.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int P, Q;
        cin >> P >> Q;
        grafo[P].push_back(Q);
        grafo[Q].push_back(P);
    }

    int centro = -1;
    for (int i = 1; i <= N; i++) {
        if (grafo[i].size() >= 5) {
            centro = i;
            break;
        }
    }

    visitado.assign(N + 1, 0);
    pai.assign(N + 1, -1);
    no_ciclo.assign(N + 1, false);

    visitado[centro] = 2;

    for (int u : grafo[centro])
        if (!visitado[u])
            dfs(u, centro);

    int resposta = 0;
    for (int i = 1; i <= N; i++)
        resposta += no_ciclo[i];

    cout << resposta << '\n';

    return 0;
}