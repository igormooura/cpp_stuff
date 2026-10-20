#include <bits/stdc++.h>
using namespace std;

vector<int> temp;
vector<int> fen;

void update(int i, int x) {
    while (i < (int)fen.size()) {
        fen[i] += x;
        i += (i & (-i));
    }
}

int sum(int i) {
    int s = 0;

    while (i > 0) {
        s += fen[i];
        i -= (i & (-i));
    }

    return s;
}

void build() {
    fen = temp;

    for (int i = 1; i < (int)fen.size(); i++) {
        int p = i + (i & (-i));

        if (p < (int)fen.size()) {
            fen[p] += fen[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    temp.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> temp[i];
    }

    build();

    int m;
    cin >> m;

    cout << fixed << setprecision(8);

    for (int i = 0; i < m; i++) {
        char first;
        int a, b;

        cin >> first >> a >> b;

        if (first == 'Q') {
            double media = double(sum(b) - sum(a - 1)) / (b - a + 1);
            cout << media << '\n';
        }
        else if (first == 'U') {
            update(a, b);
        }
    }

    return 0;
}
