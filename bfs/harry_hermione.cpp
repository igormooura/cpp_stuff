#include <bits/stdc++.h>

#define endl '\n'
#define MOD 1e9+7


using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;
using tiii = tuple<int, int, int>;
const ll INF = 4e18;
const int MAX = 110;

int n, m;
char M[MAX][MAX];
bool vis[MAX][MAX];

vector<pii> mov = {{-1, 0}, {1,0}, {0,-1}, {0,1}};

bool val(pii u){
    return u.first >= 0 and u.second >= 0 and u.first < n and
    u.second < m and M[u.first][u.second] == 'H' and !vis[u.first][u.second];
}

pii bfs(pii s){ 
    queue<pii> q;
    q.push(s), vis[s.first][s.second] = 1;

    pii v;
    while(!q.empty()){ 
        v = q.front(); q.pop();
        for(auto u : mov){
            u.first += v.first, u.second += v.second;

            if(val(u)){
                q.push(u), vis[u.first][u.second] = 1;
            }
        }
    }

    return v;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m; 

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
        cin >> M[i][j];
    
    pii s;

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(M[i][j] == 'o')
        s = {i, j};

    pii ans = bfs(s);

    cout << ans.first + 1 << ' ' << ans.second + 1 << endl;


    return 0;
}

// https://neps.academy/exercise/26