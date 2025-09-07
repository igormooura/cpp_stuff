#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int counter = 0;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] < target) {
                    counter++;
                }
            }
        }
        return counter;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 8, 2, 7, 4, 6, 1, 9, 5, 10};
    int target = 8;

    cout << "Numero de pares: " << sol.countPairs(nums, target) << endl;

    return 0;
}


