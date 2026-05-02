#include <bits/stdc++.h>
using namespace std;

int thue_morse(long long q, long long pot){
    if (q == 1){ 
        return 0;
    }

    if (q > pot){
        return 1 - thue_morse(q - pot, pot / 2);
    } else {
        return thue_morse(q, pot / 2);
    }
}

int main() {
    int n; 
    cin >> n;

    vector<int> results; 

    long long q; 

    for (int i = 0; i < n; i++){
        cin >> q; 

        long long pot = 1; 

        while (pot * 2 < q){
            pot *= 2;
        }

        results.push_back(thue_morse(q, pot)); 
    }

    for (int x : results){
        cout << x << '\n';
    }

    return 0;
}