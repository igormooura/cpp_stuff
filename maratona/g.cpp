#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n, m; 
    cin >> n >> m; 

    vector<int> finolia(n);
    vector<int> herm(m);

    for(int i = 0; i < n; i++){
        cin >> finolia[i];;
    }

    for(int i = 0; i < m; i++){ 
        cin >> herm[i];
    }

    int somaA = 0; 
    int somaB = 0; 

    for(int i = 0; i < n; i++){ 
        somaA += finolia[i];
    }
    for(int i = 0; i < m; i++){ 
        somaB += herm[i];
    }

    
    int diff = abs(somaA - somaB) / 2;
    int best = 0;

    for(int i = 0; i < n; i++){ 
        for(int j = 0; j < m; j++){
        int aux = abs(finolia[i] - herm[j]);
            if(aux <= diff && aux > best){ 
                best = aux;
            }
        }
    }
    //cout << best << endl;
    cout << (max(somaA, somaB) - best) - (best + min(somaA, somaB))<< endl; 
    

    return 0;
}