#include <iostream>
#include <vector>

using namespace std;

vector<int> memo(100, -1);
static int counter = 0;

int fib ( int n) { 
 
    counter++;
    if ( memo[n] != -1){ // por ser um vetor de "-1", se o valor for diferente, é que ele ja foi calculado
        return memo[n];
    }

    if(n == 0 || n == 1){
        return n;
    }

    memo[n] = fib(n - 1) + fib(n - 2); // armazena o resultado do cálculo para n, para que seja reutilizado posteriormente

    return memo[n]; 

}

int main() {

    cout << fib(41) << endl;
    cout << counter << endl;
    return 0;
}