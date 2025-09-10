#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counter1; 
        for (int num : nums) counter1[num]++;

        int n = nums.size();
        vector<vector<int>> counter2(n + 1);
        for (auto it : counter1) counter2[it.second].push_back(it.first);

        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; i--) {
            for (int num : counter2[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int k, num;

    cout << "Digite os números separados por espaço (Enter para terminar):\n";
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n') break;
    }

    cout << "Digite o valor de k:\n";
    cin >> k;

    vector<int> ans = sol.topKFrequent(nums, k);

    cout << "Top " << k << " números mais frequentes: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
