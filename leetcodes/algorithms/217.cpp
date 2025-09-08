#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true; 
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 4};   // não tem duplicado
    vector<int> nums2 = {1, 2, 3, 1};   // tem duplicado

    cout << boolalpha; // imprime "true" ou "false" em vez de 1 e 0
    cout << "nums1: " << sol.containsDuplicate(nums1) << endl;
    cout << "nums2: " << sol.containsDuplicate(nums2) << endl;

    return 0;
}
