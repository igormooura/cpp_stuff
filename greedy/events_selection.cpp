#include <bits/stdc++.h>
using namespace std;

int eventsSelection(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    
    vector<pair<int,int>> events;

    for (int i = 0; i < n; i++) {
        events.push_back({start[i], finish[i]});
    }

    sort(events.begin(), events.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.second < b.second;
    });

    int count = 1;
    int last = 0;

    for (int i = 1; i < n; i++) {
        if (events[i].first >= events[last].second) {
            count++;
            last = i;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> start(n), finish(n);

    for (int i = 0; i < n; i++) {
        cin >> start[i] >> finish[i];
    }

    cout << eventsSelection(start, finish) << endl;

    return 0;
}