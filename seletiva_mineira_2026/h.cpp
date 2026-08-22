#include <bits/stdc++.h>

#define endl '\n'
#define MOD 1e9+7


using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;
using tiii = tuple<int, int, int>;
const ll INF = 4e18;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<string> numeros(3);

    for(int i = 0; i < 3; i++){ 
        cin >> numeros[i];
    }

    int p1= 0, p2 = 0, p3 = 0;

    int n1 = numeros[0].size();
    int n2 = numeros[1].size();
    int n3 = numeros[2].size();

    string ans = "";

    while(p1 < n1 || p2 < n2 || p3 < n3){
        if (numeros[1][p2] == '1' && numeros[2][p3] == '1') {
            ans += '1';
            p2++;
            p3++;
        } else if (numeros[0][p1] == '2' && numeros[2][p3] == '2') {
            ans += '2';
            p1++;
            p3++;
        } else {
            ans += '3';
            p1++;
            p2++;
        }
    }

    cout << ans << endl;

    return 0;
}