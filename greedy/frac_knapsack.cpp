#include <bits/stdc++.h>
using namespace std;

vector<double> value, weight;

bool comp(int a, int b) {
    return value[a] * weight[b] > value[b] * weight[a];
}

int main() {
    int n;
    double capacity;
    cin >> n >> capacity;

    value = vector<double>(n);
    weight = vector<double>(n);

    for (int i = 0; i < n; i++) {
        cin >> value[i] >> weight[i];
    }

    vector<int> item(n);
    for (int i = 0; i < n; i++) item[i] = i;

    sort(item.begin(), item.end(), comp);

    double totalValue = 0;

    for (int i = 0; i < n; i++) {
        int id = item[i];

        if (capacity >= weight[id]) {
            totalValue += value[id];
            capacity -= weight[id];
        } else {
            totalValue += value[id] * (capacity / weight[id]);
            break;
        }
    }

    cout << fixed << setprecision(10) << totalValue << endl;

    return 0;
}