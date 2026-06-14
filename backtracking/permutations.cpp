#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> ans; 

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr; 

        backtrack(nums, curr);

        return ans;
    }

    void backtrack(vector<int>& nums, vector<int>& curr) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++){

            bool used = false;

            for (int j = 0; j < curr.size(); j++) {
                if (curr[j] == nums[i]) {
                 used = true;
                 break;
                }
            }

            if (used) {
                continue;
            }

            curr.push_back(nums[i]);

            backtrack(nums, curr);

            curr.pop_back();
        }
    }
};


int main() {

    vector<int> nums = {1, 2, 3};

    Solution sol;

    vector<vector<int>> result = sol.permute(nums);

    for (auto &perm : result) {
        cout << "[ ";
        for (int x : perm) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}