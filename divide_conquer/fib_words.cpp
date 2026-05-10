#include <bits/stdc++.h>
using namespace std;

vector<unsigned long long> fib;
vector<char> ans;

char fibWord(unsigned long long q, int n){
    if(n == 0) return 'a';
    if(n == 1) return 'b';

    if(q < fib[n - 1]){
        return fibWord(q, n - 1);
    }

    return fibWord(q - fib[n - 1], n - 2);
}

int main() {
    fib.push_back(1);
    fib.push_back(1);

    while(fib.back() <= 1e18){
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        unsigned long long q;
        cin >> q;

        int n = 2;

        while(fib[n] <= q){
            n++;
        }

        ans.push_back(fibWord(q, n));
    }

    for(char c : ans){
        cout << c << '\n';
    }

    return 0;
}