#include <iostream>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
       int digit = 0, sumResult = 0, multiResult = 1;
       while (n > 0) {
            digit = n % 10;
            multiResult *= digit;
            sumResult += digit;
            n /= 10;
       }
       return multiResult - sumResult;
    } 
};

int main() {
    Solution sol;
    int n = 234;  // teste
    cout << "Resultado: " << sol.subtractProductAndSum(n) << endl;
    return 0;
}
