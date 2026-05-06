#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n; cin >> n; 
    vector<int> v;
    int x;

    for ( int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i =0; i < v.size(); i++){
        pq.push(v[i]);
    }

    int k = 3;

    while (k-- && !pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}