#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string arr){
    int left = 0;
    int right = arr.size() - 1;

    while(left < right){

        while(left < right && arr[left] == ' ')
            left++;

        while(left < right && arr[right] == ' ')
            right--;

        if(tolower(arr[left]) != tolower(arr[right])){
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main(){
    string arr = "ame o poema";

    cout << "The string is a palindrome? : "
         << (isPalindrome(arr) ? "Yes" : "No") << endl;

    return 0;
}