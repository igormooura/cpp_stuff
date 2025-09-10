#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (auto c : s) { 
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (c == ')' && !st.empty() && st.top() == '(') {
                    st.pop();
                } else if (c == '}' && !st.empty() && st.top() == '{') {
                    st.pop();
                } else if (c == ']' && !st.empty() && st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

int main() {
    Solution sol;
    string s;

    cout << "Digite a string de parenteses: ";
    cin >> s;

    if (sol.isValid(s)) {
        cout << "Valido ✅" << endl;
    } else {
        cout << "Invalido ❌" << endl;
    }

    return 0;
}
