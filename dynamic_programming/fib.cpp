#include <iostream>

using namespace std;
static int counter = 0;

int fib(int n) {

    counter++;
    if (n == 0 || n == 1) {
        return n;
    }

    int result = fib(n - 1) + fib(n - 2);
    
    return result;
}


int main(){

    cout << fib(41) << endl;
    cout << counter << endl;
    return 0;

}