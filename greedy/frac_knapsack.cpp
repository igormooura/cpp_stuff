#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool comp(pair<ll,ll> a, pair<ll,ll> b){

    // a.first  = value
    // a.second = weight

    return a.first * b.second > b.first * a.second;
}

int main() {

    int n;
    double capacity;

    cin >> n >> capacity;

    vector<pair<ll,ll>> itens(n);

    for(int i = 0; i < n; i++){

        ll value, weight;
        cin >> value >> weight;

        itens[i] = {value, weight};
    }

    sort(itens.begin(), itens.end(), comp);

    double ans = 0;

    for(int i = 0; i < n; i++){

        ll value = itens[i].first;
        ll weight = itens[i].second;

        // cabe inteiro
        if(capacity >= weight){

            ans += value;
            capacity -= weight;
        }

        // pega fração
        else{

            ans += value * (capacity / weight);
            break;
        }
    }

    cout << fixed << setprecision(10) << ans << endl;
}