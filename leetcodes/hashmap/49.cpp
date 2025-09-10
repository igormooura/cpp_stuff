#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        int n = s.size();
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < n; i++) {
            string temp = s[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s[i]);
        }

        vector<vector<string>> ans;
        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> words;
    string word;

    cout << "Digite as palavras separadas por espaço (pressione Enter quando terminar):\n";
    while (cin >> word) {
        words.push_back(word);
        if (cin.peek() == '\n') break;
    }

    vector<vector<string>> groups = sol.groupAnagrams(words);

    cout << "\nGrupos de anagramas encontrados:\n";
    int groupNumber = 1;
    for (auto& group : groups) {
        cout << "Grupo " << groupNumber++ << ": ";
        for (auto& w : group) {
            cout << w << " ";
        }
        cout << endl;
    }

    cout << "\nTotal de grupos: " << groups.size() << endl;

    return 0;
}
