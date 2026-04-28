#include <iostream>

using namespace std;

int main(){

    int n;
    int result = 1;
    cin >> n;

    if( n <= 12 && n >= 0){
        for( int i = n; i > 0; i--){
            
            result *= i;
        
        }
    }

    cout << result << endl;
    return 0;
}
