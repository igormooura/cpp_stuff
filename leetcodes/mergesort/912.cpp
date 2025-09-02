#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int middle = nums.size() / 2;

        if (nums.size() > 1) {
            vector<int> v1(middle);
            vector<int> v2(nums.size() - middle);

            for (int i = 0; i < middle; i++) {
                v1[i] = nums[i];
            }
            for (int j = middle; j < nums.size(); j++) {
                v2[j - middle] = nums[j];
            }

            v1 = sortArray(v1);
            v2 = sortArray(v2);

            return merge(v1, v2);
        }
        return nums;
    }

private:
    vector<int> merge(vector<int>& left, vector<int>& right) {
        vector<int> result;

        int i = 0;
        int j = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                result.push_back(left[i++]);
            } else {
                result.push_back(right[j++]);
            }
        }

        while (i < left.size()) {
            result.push_back(left[i++]);
        }
        while (j < right.size()) {
            result.push_back(right[j++]);
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 2, 3, 1, 4};
    vector<int> sorted = s.sortArray(nums);

    cout << "Vetor ordenado: ";
    for (int n : sorted) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
