#include <iostream>
#include <vector>
using namespace std;

// this solution is slow as fuck btw 

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        vector<int> v;
        while (x > 0) {
            v.push_back(x % 10);
            x /= 10;
        }

        int i = 0, j = v.size() - 1;
        while (i < j) {
            if (v[i] != v[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};

// ====================AI GENERATED===========================


int main() {
    Solution sol;
    
    int num;
    cout << "Digite um numero: ";
    cin >> num;

    if (sol.isPalindrome(num)) {
        cout << num << " é um palíndromo ✅" << endl;
    } else {
        cout << num << " não é um palíndromo ❌" << endl;
    }

    return 0;
}
