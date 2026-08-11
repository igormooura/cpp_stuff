#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve(string s)
{
    unordered_map<char, int> mp = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int ans = 0;

    for (int i = 0; i < s.size(); i++) {
        if (i + 1 < s.size() && mp[s[i]] < mp[s[i + 1]]) {
            ans -= mp[s[i]];
        } else {
            ans += mp[s[i]];
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve("IV") << endl; 
    cout << solve("VI") << endl;
    cout << solve("MCMXCIV") << endl;  // 1994

    return 0;
}


