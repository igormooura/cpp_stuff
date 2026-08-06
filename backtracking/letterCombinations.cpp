#include <bits/stdc++.h>
#define endl '\n'
#define MOD 1e9+7

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;
using tiii = tuple<int, int, int>;
const ll INF = 4e18;

// void backtrack(string& digits, int idx, string combination,
//                vector<string>& res,
//                const unordered_map<char, string>& digitToLetters) {

//     if (idx == digits.length()) {
//         res.push_back(combination);
//         return;
//     }

//     string letters = digitToLetters.at(digits[idx]);

//     for (int i = 0; i < letters.size(); i++) {
//     char letter = letters[i];
//     backtrack(digits, idx + 1, combination + letter, res, digitToLetters);
// }
// }

// vector<string> letterCombinations(string digits) {
//     vector<string> res;

//     if (digits.empty()) return res;

//     unordered_map<char, string> digitToLetters = {
//         {'2', "abc"},
//         {'3', "def"},
//         {'4', "ghi"},
//         {'5', "jkl"},
//         {'6', "mno"},
//         {'7', "pqrs"},
//         {'8', "tuv"},
//         {'9', "wxyz"}
//     };

//     backtrack(digits, 0, "", res, digitToLetters);

//     return res;
// }

void backtracking(string& digits, int idx, string combination, vector<string>& res, unordered_map<char, string>& digitsToLetters  );
vector<string> letterCombs(string digits);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string digits = "23";
    vector<string> ans = letterCombs(digits);

    for (auto &s : ans) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}


void backtracking(string& digits, int idx, string combination, vector<string>& res, unordered_map<char, string>& digitsToLetters  ){

        if(digits.size() == idx){
            res.push_back(combination);
            return;
        }

        string letters = digitsToLetters.at(digits[idx]);

        for(int i = 0; i < letters.size(); i++){
            char letter = letters[i];
            backtracking(digits, idx + 1, letter + combination, res, digitsToLetters);
        }


}

vector<string> letterCombs(string digits){

    vector<string> res;

    if(digits.empty()) return res;
    
    unordered_map<char, string> digitsToLetters = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    backtracking(digits, 0, "", res, digitsToLetters);


    return res;

}