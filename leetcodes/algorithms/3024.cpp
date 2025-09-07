#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        string resposta;

        if (nums[0] + nums[1] <= nums[2] || 
            nums[0] + nums[2] <= nums[1] ||
            nums[1] + nums[2] <= nums[0]) {
            return "none";
        }

        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            resposta = "equilateral";
        } 
        else if (nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) {
            resposta = "isosceles";
        } 
        else {
            resposta = "scalene";
        }

        return resposta;
    }
};

int main() {
    Solution sol;

    vector<int> t1 = {3, 3, 3};   // equilátero
    vector<int> t2 = {3, 4, 4};   // isósceles
    vector<int> t3 = {3, 4, 5};   // escaleno
    vector<int> t4 = {1, 2, 3};   // não forma triângulo

    cout << sol.triangleType(t1) << endl;
    cout << sol.triangleType(t2) << endl;
    cout << sol.triangleType(t3) << endl;
    cout << sol.triangleType(t4) << endl;

    return 0;
}
