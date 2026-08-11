#include <bits/stdc++.h>

#define endl '\n'
#define MOD 1e9+7

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using ll = long long;
using tiii = tuple<int, int, int>;

void solve()
{
   ll n; cin >> n;
   vll rats(n);
    vll holes(n+1);
   for(int i = 0; i < n; i++) cin>> rats[i];
   for(int i =0; i < n+1; i++) cin >> holes[i];

   int j = -1;
   ll soma = 0;

   for(int i =0; i < n; i++){ 
    int next = j+1, nextt = j+2;

    if(next >= n + 1){ 
        nextt = INT_MAX;
        soma += (abs(rats[i] - holes[next]));
        break;
    }

    if(abs(rats[i] - holes[next]) < abs(rats[i] - holes[nextt])){
        j = next;
    } else { 
        j = nextt;
    }
    soma += min(abs(rats[i] - holes[next]), abs(rats[i] - holes[nextt]));
}
cout << soma;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}