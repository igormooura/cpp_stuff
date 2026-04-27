#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1000000007;

// pair<ll, ll> fib(ll n) {
//     if (n == 0) return {0, 1};

//     auto [a, b] = fib(n / 2); 

//     ll c = (a * ((2 * b % MOD - a + MOD) % MOD)) % MOD; 
//     ll d = ( (a * a) % MOD + (b * b) % MOD ) % MOD;     

//     if (n % 2 == 0)
//         return {c, d};
//     else
//         return {d, (c + d) % MOD};
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     ll n;
//     cin >> n;

//     cout << fib(n).first << '\n';
//     return 0;
// }

vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> base){
    vector<vector<ll>> result(2, vector<ll>(2, 0));

    for(int row = 0; row < 2; row++){
        for(int col = 0; col < 2; col++){
            for(int d = 0; d < 2; d++){
                result[row][col] = (result[row][col] + A[row][d] * base[d][col]) % MOD;
            }
        }
    }
    return result;
}


vector<vector<ll>> fast_expo(ll exp){
    vector<vector<ll>> result{{1,0},{0,1}};
    vector<vector<ll>> base{{1,1},{1,0}};

    while(exp > 0){
        if(exp % 2 == 1){
            result = multiply(result, base);
        }

        base = multiply(base, base);
        exp = exp / 2;
    }

    return result;
}

int main() {
    long long n;
    cin >> n;

    vector<vector<ll>> res = fast_expo(n - 1);

    cout << res[0][0] << "\n";

    return 0;
}