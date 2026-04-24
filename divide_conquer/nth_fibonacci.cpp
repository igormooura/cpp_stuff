#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1000000007;

pair<ll, ll> fib(ll n) {
    if (n == 0) return {0, 1};

    auto [a, b] = fib(n / 2); 

    ll c = (a * ((2 * b % MOD - a + MOD) % MOD)) % MOD; 
    ll d = ( (a * a) % MOD + (b * b) % MOD ) % MOD;     

    if (n % 2 == 0)
        return {c, d};
    else
        return {d, (c + d) % MOD};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    cout << fib(n).first << '\n';
    return 0;
}