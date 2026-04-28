#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n <= 1) {
        cout << "nao" << endl;
        return 0;
    }

    for (long long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cout << "nao" << endl;
            return 0;
        }
    }

    cout << "sim" << endl;
    return 0;
}