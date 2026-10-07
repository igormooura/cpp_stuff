#include <bits/stdc++.h>

#define endl '\n'
#define MOD 1e9+7
using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;
using tiii = tuple<int, int, int>;
const ll INF = 4e18;

vector<vector<char>> coast;
vector<vector<bool>> vis;

void dfs(int x, int y){ 
    vis[x][y] = true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m ; 
    cin >> n >> m; 

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> coast[i][j];
        }
    }

    return 0;
}