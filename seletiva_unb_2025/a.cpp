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
    int vels;

    cin >> n;

    while(cin >> vels){

        if(vels > n + (n * 0.05)){ 
            cout << "Athelera, fera!" << endl;
        } 
        else if (vels < n - (n * 0.05)) {
            cout << "Calma que ainda tem o returno." << endl;
        } 
        else {
            cout << "Boa! Merece cafe e pao de queijo." << endl;
        }
    }

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    solve();

    return 0;
}