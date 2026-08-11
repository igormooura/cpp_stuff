#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

using vll = vector<long long>;

void solve()
{
    int n; 
    cin >> n;

    vll array(n + 1);
    vll arraysum(n + 1);

    array[0] = arraysum[0] = 0;

    for(int i = 1; i <= n; i++){ 
        cin >> array[i];
        arraysum[i] = arraysum[i-1] + array[i];
    }

    int q;
    cin >> q;

    int l, r;

    while(q--){
        cin >> l >> r;

        cout << arraysum[r] - arraysum[l-1] << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 

    solve();

    return 0;
}