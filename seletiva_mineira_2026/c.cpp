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
    int q, s, l;
    cin>> q >> s >> l;
    int total;

    if(l >= 2){

         total = q*2 + s*2 + 3 + ((l-2)/2)*3;
    } else { 
        total = q * 2;
    }

    cout << total;
    return 0;
}