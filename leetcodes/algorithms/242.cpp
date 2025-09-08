#include <iostream>
#include <string>
#include <algorithm> // sort

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if (s == t) return true;
        return false;
    }
};

int main() {
    Solution sol;

    string s1 = "anagram", t1 = "nagaram";
    string s2 = "rat", t2 = "car";

    cout << boolalpha; // imprime true/false em vez de 1/0
    cout << "s1 & t1 -> " << sol.isAnagram(s1, t1) << endl; // true
    cout << "s2 & t2 -> " << sol.isAnagram(s2, t2) << endl; // false

    return 0;
}
