#include <bits/stdc++.h>

#define endl '\n'
#define MOD 1e9+7

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;
using tiii = tuple<int, int, int>;

void solve()
{
    int n; 
    cin >> n;
    vector<int> baloes(n);
    int ans = 0;

    for(int i = 0; i < n; i++ ){
        cin>> baloes[i];
    }

    sort(baloes.begin(), baloes.end());

    for(int i = 0; i < baloes.size(); i++){ 
        ans += abs(baloes[0] - baloes[i]);
    }

    cout << ans;

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    

    solve();
    return 0;
}