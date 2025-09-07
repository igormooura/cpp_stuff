#include <iostream>
using namespace std;

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + 2 * t;
    } 
};

int main() {
    Solution sol;
    int num = 5;  
    int t = 3;    
    cout << "Resultado: " << sol.theMaximumAchievableX(num, t) << endl;
    return 0;
}
