#include <bits/stdc++.h>

#define endl '\n'
#define MOD 1e9 + 7

using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;
using tiii = tuple<int, int, int>;

const ll INF = 4e18;

vector<vector<char>> coast;
vector<vector<bool>> vis;

int n, m;
int ans = 0;

void dfs(int x, int y)
{
    vis[x][y] = true;

    bool is_coast = false;

    if(x - 1 < 0 || coast[x - 1][y] == '.')
        is_coast = true;
    else if(!vis[x - 1][y])
        dfs(x - 1, y);

    if(x + 1 >= n || coast[x + 1][y] == '.')
        is_coast = true;
    else if(!vis[x + 1][y])
        dfs(x + 1, y);
    if(y - 1 < 0 || coast[x][y - 1] == '.')
        is_coast = true;
    else if(!vis[x][y - 1])
        dfs(x, y - 1);

    if(y + 1 >= m || coast[x][y + 1] == '.')
        is_coast = true;
    else if(!vis[x][y + 1])
        dfs(x, y + 1);

    if(is_coast)
        ans++;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    coast.resize(n, vector<char>(m));
    vis.resize(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> coast[i][j];
        }
    }

    

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(coast[i][j] == '#' && !vis[i][j]){
                dfs(i, j);
            }
        }
    }

    cout << ans << endl;

    return 0;
}

//https://neps.academy/exercise/329