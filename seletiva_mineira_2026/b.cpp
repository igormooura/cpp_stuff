#include <bits/stdc++.h>

#define endl '\n'
#define MOD 1e9+7


using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;
using tiii = tuple<int, int, int>;
const ll INF = 4e18;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k; cin >> n >> k;

    vector<int> cnt(n + 1);

    for(int i = 0; i < n; i++){
        int x; 
        cin >> x; 
        cnt[x]++;
    }

    int ans = 0;
    int minimo = n;

    for(int i = 0; i < n; i++){ 
        minimo = min(minimo, cnt[i]);

        if (minimo == 0) break;

        ans += min(minimo, k);
    }

    cout << ans;

    return 0;
}