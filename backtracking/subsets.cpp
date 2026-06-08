#include <bits/stdc++.h>

#define endl '\n'
#define MOD 1e9+7

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;
using tiii = tuple<int, int, int>;

vector<vector<int>> ans;


void backtrack(int index, vector<int>& nums, vector<int>& current){
    if(index == nums.size()){
        ans.push_back(current);
        return; 
    }
    
    current.push_back(nums[index]);
    backtrack(index + 1, nums, current);
    
    current.pop_back();
    backtrack(index + 1, nums, current);
}
vector<vi> subsets(vector<int>& nums){
    vector<int> current; 

    backtrack(0, nums, current);

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<int> nums;

    nums = {1, 2 ,3 ,4, 5};

    subsets(nums);

    for (size_t i = 0; i < ans.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j];
            if (j < ans[i].size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}