#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result; 
        
        for(int i = 0; i < nums.size(); i++) {
            int smallercount = 0; 
            
            for(int j = 0; j < nums.size(); j++) {
                if(nums[i] > nums[j]) {
                    smallercount++;
                }
            }
            
            result.push_back(smallercount); 
        }
        
        return result; 
    }
};

int main() {
    Solution sol;
    
    vector<int> nums = {8, 1, 2, 2, 3};
    vector<int> result = sol.smallerNumbersThanCurrent(nums);
    
    cout << "Resultado: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
