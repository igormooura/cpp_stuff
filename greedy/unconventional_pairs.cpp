#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t;
    cin >> t;
    ll n;
    ll a;
    ll ans;

    vector<ll> results;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        vector<ll> pairs; 
        for (int j = 0; j < n; j++){
            cin >> a;
            pairs.push_back(a);
        }

        sort(pairs.begin(), pairs.end()); 
        ll maior = 0; 
        for (int i = 0; i < pairs.size(); i += 2){

            ans = abs(pairs[i] - pairs[i + 1]);
            if (ans > maior){
                maior = ans;
            }

        }

        results.push_back(maior);
    }

    for (ll x : results)
    {
        cout << x << endl;
    }

    return 0;
}