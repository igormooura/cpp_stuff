#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n; cin >> n; 

    vector<int> toupeiras(n);
    vector<int> buracos(n);

    for(int i = 0; i < n; i++){
        cin>> toupeiras[i];
    }
    for(int j = 0; j < n; j++){
        cin>> buracos[j];
    }

    sort(toupeiras.begin(), toupeiras.end());
    sort(buracos.begin(), buracos.end());

    int valorMax = 0; 

    for(int i = 0; i < n; i++){

        if(abs(toupeiras[i] - buracos[i]) > valorMax){
            valorMax = abs(toupeiras[i] - buracos[i]);
        }
    }

    cout << valorMax;

    return 0;
}