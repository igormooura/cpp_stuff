#include <bits/stdc++.h>

#define endl '\n'
#define MOD 1e9+7

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;
using tiii = tuple<int, int, int>;

void backtracking(vector<string>& res, string input,int index, string combination, unordered_map<char, string>& letterCombinations){

    if(input.size() == index){
        res.push_back(combination);
        return;
    }

    string letters = letterCombinations[input[index]];

    for(int i = 0; i < letters.size(); i++){
        backtracking(res, input, index + 1, combination + letters[i], letterCombinations);
    }
}

void letterCombinations(string digits)
{
    vector<string> res;

    unordered_map<char, string> digitsToNumber = {
        {'1', ""},
        {'2', "abc"}, 
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"}, 
        {'9', "wxyz"}
    };

    backtracking(res, digits, 0, "", digitsToNumber);    

    for (string s : res) {
        cout << s << " ";
    }
    cout << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    letterCombinations("23");
    
    return 0;
}