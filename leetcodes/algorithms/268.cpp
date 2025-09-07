#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int somaReal = 0;

        for (int i = 0; i < n; i++) {
            somaReal += nums[i];
        }

        int somaDeN = (n * (n + 1)) / 2;

        return somaDeN - somaReal;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 0, 1};
    cout << "Missing: " << sol.missingNumber(nums1) << endl; // esperado 2

    vector<int> nums2 = {0, 1};
    cout << "Missing: " << sol.missingNumber(nums2) << endl; // esperado 2

    vector<int> nums3 = {9,6,4,2,3,5,7,0,1};
    cout << "Missing: " << sol.missingNumber(nums3) << endl; // esperado 8

    return 0;
}
