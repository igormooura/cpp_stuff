#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v1(m);
        vector<int> v2(n);

        for (int i = 0; i < m; i++) {
            v1[i] = nums1[i];
        }
        for (int j = 0; j < n; j++) {
            v2[j] = nums2[j];
        }

        int k = 0;
        int i = 0;
        int j = 0;
        vector<int> resultado(v1.size() + v2.size());

        while (i < v1.size() && j < v2.size()) {
            if (v1[i] <= v2[j]) {
                resultado[k++] = v1[i++];
            } else {
                resultado[k++] = v2[j++];
            }
        }

        while (i < v1.size()) resultado[k++] = v1[i++];
        while (j < v2.size()) resultado[k++] = v2[j++];

        for (int x = 0; x < resultado.size(); x++) {
            nums1[x] = resultado[x];
        }
    }
};

// AI GENERATED ABAIXO

int main() {
    Solution sol;

    // Exemplo 1
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    sol.merge(nums1, m, nums2, n);

    cout << "Resultado: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
