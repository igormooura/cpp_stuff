#include <bits/stdc++.h>
using namespace std;

int main() {
        priority_queue<int> pq;

        pq.push(20);
        pq.push(5);
        pq.push(10);


    while (!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }


    priority_queue<int, vector<int>, greater<int>> pq2;

    pq2.push(10);
    pq2.push(5);
    pq2.push(20);

    while (!pq2.empty()) {
        cout << pq2.top() << " ";
        pq2.pop();
    }
    return 0;
}