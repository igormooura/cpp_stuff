#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        vector<int> aux;

        for(int i = 1; i <= n; i++){
            aux.push_back(i);
        }

        backtracking(0, k, curr, aux);

        return ans;
    }

    void backtracking(int start, int k, vector<int>& curr, vector<int>& aux){
        
        if(curr.size() == k){ 
            ans.push_back(curr);
            return;
        }

        for(int i = start; i < aux.size(); i++){ 
            
            curr.push_back(aux[i]);
            backtracking(i + 1, k, curr, aux);
            curr.pop_back();
        }
    }
};

int main() {

    Solution sol;

    int n = 4;
    int k = 2;

    vector<vector<int>> result = sol.combine(n, k);

    for(auto &combination : result){
        cout << "[ ";
        for(int x : combination){
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}