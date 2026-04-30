#include <bits/stdc++.h>
using namespace std;

bool comparision(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int eventsSelection(vector<int> &start, vector<int> &finish)
{
    int n = start.size();

    vector<pair<int, int>> events;

    for (int i = 0; i < n; i++)
    {
        events.push_back({start[i], finish[i]});
    }

    sort(events.begin(), events.end(), comparision);

    int count = 1; // at leats 1 event will be counted
    int last = 0;

    for (int i = 1; i < n; i++)
    {
        if (events[i].first > events[last].second)
        { // > enforces a strictly later start time than the previous event's end
            count++;
            last = i;
        }
    }

    return count;
}

int main()
{
    int n;
    cin >> n;

    vector<int> start(n), finish(n);

    for (int i = 0; i < n; i++)
    {
        cin >> start[i] >> finish[i];
    }

    cout << eventsSelection(start, finish) << endl;

    return 0;
}