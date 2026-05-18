#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m; 

    string a1, a2;
    cin >> a1 >> a2;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a1[i - 1] == a2[j -1]){
                dp[i][j] = dp[i -1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i -1][j],dp[i][j - 1]);
            }
        }
    }

    string lcs = "";

    int i = n, j = m;

    while (i > 0 && j > 0) {
        if (a1[i - 1] == a2[j - 1]) {
            lcs += a1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());

    cout << dp[n][m] << "\n";

    if (!lcs.empty()) cout << lcs << "\n";

    
    return 0;
}