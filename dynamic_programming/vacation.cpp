#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }


    vector<vector<int>> dp(n + 1, vector<int>(3, 101));

    // dia 1
    dp[1][0] = 1;
    dp[1][1] = (a[1] == 1 || a[1] == 3) ? 0 : 101;
    dp[1][2] = (a[1] == 2 || a[1] == 3) ? 0 : 101;

    for(int i = 2; i <= n; i++) {

        // descanso
        dp[i][0] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) + 1;

        // competição
        if(a[i] == 1 || a[i] == 3)
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);

        // academia 
        if(a[i] == 2 || a[i] == 3)
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
    }

    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << "\n";

    return 0;
}