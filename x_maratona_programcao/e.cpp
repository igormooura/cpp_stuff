#include <bits/stdc++.h>

#define endl '\n'
#define MOD 1e9+7

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;
using tiii = tuple<int, int, int>;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m; 

    vector<int> vetoraux(1e5 + 1, 0);

    for(int i = 0; i < n; i++){
        int a;

        cin >> a; 

        vetoraux[a] = 1;
    }
    for(int i = 0; i < m; i++){ 
        int a; 

        cin >> a; 

        vetoraux[a] = 1;
    }

    for(int i = 0; i < 1e5 + 1; i++){
        if(vetoraux[i] == 1){
            cout << i << " ";
        }
    }

    cout << endl;
    
    return 0;
}