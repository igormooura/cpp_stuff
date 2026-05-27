#include <bits/stdc++.h>
using namespace std;

int main() {
    

    int n, capacidade; 

    cin >> n >> capacidade; 
    
    vector<pair<long long, long long>> itens(n); 
    
    for(int i = 0; i < n; i++){
        cin >> itens[i].first >> itens[i].second;
    }   
    vector<long long>dp(capacidade + 1, 0);


    for(int i = 0; i < n; i++){
        long long peso = itens[i].first;
        long long valor = itens[i].second;

        for(int w = capacidade; w >= peso; w--){
            dp[w] = max(dp[w], dp[w - peso] + valor);
        }
    }

    cout << dp[capacidade] << endl;
     

    return 0;
}