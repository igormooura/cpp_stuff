#include <bits/stdc++.h>

#define endl '\n'
#define MOD 1e9+7


using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;
using tiii = tuple<int, int, int>;
const ll INF = 4e18;

string solve(vector<string>& strs)
{
    string ans = "";
    int n = strs.size();

    sort(strs.begin(), strs.end());

    string comeco = strs[0];
    string fim = strs[n - 1];

    for(int i = 0; i < min(comeco.size(), fim.size()); i++){
        if(comeco[i] != fim[i]){
            return;
        }

        ans[i] += comeco[i];
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    return 0;
}