#include <bits/stdc++.h>

#define endl '\n'
#define MOD 1e9+7

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;
using tiii = tuple<int, int, int>;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    

    int n; cin >> n;

    if(n == 2 || n == 3 ){
        cout << "NO SOLUTION";
        return 0;
    }

    // if( n == 4) { 
    //     cout << "2 4 1 3" << endl;; q nojeira
    //     return 0 ;
    // }

    for(int i = 1; i <= n; i++){
        if(i % 2 == 0){
            cout << i << " ";
        } 
    }

    for(int i = 1; i <= n; i++){
        if(i % 2 == 1){
            cout << i << " ";
        } 
    }

    cout << endl;

    return 0;
}