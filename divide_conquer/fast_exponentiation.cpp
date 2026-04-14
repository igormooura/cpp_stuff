#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long fast_exp(long long x, long long n){
    if (n == 0) return 1;

    long long divide = fast_exp(x, n / 2);

    if (n % 2 == 0){
        return (divide * divide) % MOD;
    } else {
        return (x % MOD * divide % MOD * divide % MOD) % MOD;
    }
} 

int main(){

    long long x, n;

    cin >> x >> n;

    cout << fast_exp(x % MOD, n) << endl;

    return 0;
}