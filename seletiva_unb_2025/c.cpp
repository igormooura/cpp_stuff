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
    ll n, k, v;
    cin >> n >> k >> v;
    vector<ll>xicaras(n); 

    for(int i = 0; i < n; i++){ 
        cin >> xicaras[i];
    }

    sort(xicaras.begin(), xicaras.end());


    ll menor_copo = xicaras[n - k];

    ll limite_cafe = v / k;


    cout << min(menor_copo, limite_cafe) << endl;

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();

    return 0;
}