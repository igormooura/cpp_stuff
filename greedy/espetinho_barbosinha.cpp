#include <bits/stdc++.h>
using namespace std;

int get_time() {
    string s;
    cin >> s;

    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    int sec = stoi(s.substr(6, 2));

    return h * 3600 + m * 60 + sec;
}

int main() {
    
    int n; cin >> n; 

    priority_queue<pair<int, int>> pq;

    for(int i = 0; i < n; i++){
        int entrada = -get_time();
        int saida = -get_time();

        pq.push({entrada, saida});
    }

    size_t max_count = 0;

    priority_queue<int> saidas;

    while(!pq.empty()){
        auto [entrada, saida] = pq.top();
        pq.pop();

        while(!saidas.empty() && entrada < saidas.top()){
            saidas.pop();
        }

        saidas.push(saida);
        max_count = max(max_count, saidas.size());
    }

    cout << max_count << endl;

    return 0;
}