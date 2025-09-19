#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {

        stack<char> p1;
        int idx = -1; 

        for (int i = 0; i < word.size(); i++) {
            p1.push(word[i]);
            if (word[i] == ch) {
                idx = i; // pra indicar se achou
                break;
            }
        }

        if (idx == -1) return word; 

         // desempilha e sobrescreve a string até o índice idx
        for (int i = 0; i <= idx; i++) {
            word[i] = p1.top(); // usa e descarta a letra
            p1.pop();
        }

        return word;
    }
};

// empilha até a letra -> desempilha e concatena com oq sobrou
// class Solution {
// public:
//     string reversePrefix(string word, char ch) {
//         stack<char> p1;
//         int idx = -1;

//         for (int i = 0; i < word.size(); i++) {
//             p1.push(word[i]);
//             if (word[i] == ch) {
//                 idx = i; 
//                 break;
//             }
//         }

//         if (idx == -1) return word;

//         string result = "";
//         while (!p1.empty()) {
//             result += p1.top();
//             p1.pop();
//         }

//         result += word.substr(idx + 1);

//         return result;
//     }
// };


int main() {
    Solution sol;
    
    string word;
    char ch;

    cout << "Digite a palavra: ";
    cin >> word;
    cout << "Digite o caractere: ";
    cin >> ch;

    string result = sol.reversePrefix(word, ch);
    cout << "Resultado: " << result << endl;

    return 0;
}
