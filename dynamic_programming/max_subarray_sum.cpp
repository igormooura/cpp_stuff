#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> memo;

int solve(int i){
    if(i == 0) return v[0];

    if(memo[i] != -1) return memo[i];

    return memo[i] = max(v[i], v[i] + solve(i - 1));
}

int main() {
    int n;
    cin >> n;

    v.resize(n);
    memo.assign(n, -1);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int ans = v[0];

    for(int i = 0; i < n; i++){
        ans = max(ans, solve(i));
    }

    cout << ans << endl;

    return 0;
}