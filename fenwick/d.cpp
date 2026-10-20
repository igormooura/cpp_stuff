
#include <bits/stdc++.h>
using namespace std;

vector<int> sal;
vector<int> fen;

int sum(int i) {
    int s = 0;

    while (i > 0) {
        s += fen[i];
        i -= (i & -i);
    }

    return s;
}

void build() {
    fen = sal;

    for (int i = 1; i < fen.size(); i++) {
        int p = i + (i & -i);

        if (p < fen.size()) {
            fen[p] += fen[i];
        }
    }
}

int main() {
    int n;
    cin >> n;

    sal.resize(50002, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sal[x + 1]++;
    }

    build();

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        cout << sum(b + 1) - sum(a) << '\n';
    }
}
