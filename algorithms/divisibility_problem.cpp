#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n = 0;
    int a, b;

    cin >> n;

    vector<int> results;

    for (int i = 0; i < n; i++){
        cin >> a >> b;

        if (a % b == 0){
            results.push_back(0);
        } else {
            results.push_back(b - (a % b));
        }
    }

    for (int x : results){
        cout << x << endl;
    }

    return 0;
}