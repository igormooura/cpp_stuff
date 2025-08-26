#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int odd = 1;
        int even = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                nums[i] = even;
            } else {
                nums[i] = odd;
            }
        }

        // bubble sort
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = 0; j < nums.size() - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    int temp = nums[j];   // guarda o valor do lugar atual
                    nums[j] = nums[j + 1]; // atrela o valor atual com o do próximo
                    nums[j + 1] = temp; // atrela o valor do próximo com o antigo
                }
            }
        }

        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 2, 9, 8, 3, 4};

    vector<int> result = sol.transformArray(nums);

    cout << "Resultado: ";
    for (int n : result) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
