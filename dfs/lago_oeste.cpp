#include <bits/stdc++.h>

#define endl '\n'
#define MOD 1e9+7


using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;
using tiii = tuple<int, int, int>;
const ll INF = 4e18;

vector<vector<char>> floresta;
void dfs(int x, int y){

    floresta[x][y] = '#';

    if(y + 1 < floresta[0].size() && floresta[x][y + 1] == 'F') dfs(x, y + 1);
    if (y - 1 >= 0 && floresta[x][y - 1] == 'F' ) dfs(x, y - 1);
    if (x - 1 >= 0 && floresta[x - 1][y] == 'F' ) dfs(x -1, y);
    if (x + 1 < floresta.size() && floresta[x + 1][y] == 'F') dfs(x + 1, y);
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    int viagens = 0;
    floresta.resize(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> floresta[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(floresta[i][j] == 'F'){
                dfs(i, j);
                viagens++;
            }
        }
    }

    cout << viagens << endl;

    return 0;
}