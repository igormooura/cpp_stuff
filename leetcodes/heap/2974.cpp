#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void heapify(int nums[], int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && nums[left] > nums[largest])
            largest = left;
        if (right < n && nums[right] > nums[largest])
            largest = right;

        if (largest != i) {
            int temp = nums[i];
            nums[i] = nums[largest];
            nums[largest] = temp;
            heapify(nums, n, largest);
        }
    }

    void heapSort(int nums[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(nums, n, i);

        for (int i = n - 1; i > 0; i--) {
            int temp = nums[0];
            nums[0] = nums[i];
            nums[i] = temp;
            heapify(nums, i, 0);
        }
    }

    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        int* raw = nums.data();
        heapSort(raw, n);
        vector<int> arr(n);
        int k = 0;
        for (int i = 0; i < n; i += 2) {
            int alice = raw[i];
            int bob = raw[i + 1];
            arr[k++] = bob;
            arr[k++] = alice;
        }
        return arr;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {5, 4, 2, 3};
    vector<int> result = sol.numberGame(nums);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
