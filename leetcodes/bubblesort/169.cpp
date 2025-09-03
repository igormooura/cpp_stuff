#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        bool trocou;

        for (int i = 0; i < n - 1; i++) {
            trocou = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                    trocou = true;


                    // outra maneira de fazer isso sem usar temp
                    //[2 ,4 ,5 ,6 ,7] 
                    //nums[j] += nums[j+1]; 
                    // [6, 4, 5 ,6 ,7 ]
                    //nums[j + 1] = nums[j] - nums[j + 1];
                    // [6, 2, 5 ,6, 7]
                    //nums[j] -= nums[j + 1];
                    // [4, 2, 5 ,6,7 ]
                }
            }
            if (!trocou) break; // já está ordenado
        }

        return nums[n / 2];
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    int result = sol.majorityElement(nums);

    cout << "Majority Element: " << result << endl;

    return 0;
}
