#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;

vector<vector<long long>> multiply(vector<vector<long long>> &A, vector<vector<long long>> &B){
    int k = A.size();

    vector<vector<long long>> result(k, vector<long long>(k, 0));

    for (int row = 0; row < k; row++){
        for (int col = 0; col < k; col++){
            for (int dimension = 0; dimension < k; dimension++){
                result[row][col] = (result[row][col] + A[row][dimension] * B[dimension][col] % MOD) % MOD;
            }
        }
    }

    return result;
}

vector<vector<long long>> fast_expo_matrix(vector<vector<long long>> base, long long n){

    int k = base.size();

    vector<vector<long long>> identity_matrix(k, vector<long long>(k, 0));

    for (int i = 0; i < k; i++){
        identity_matrix[i][i] = 1;
    }

    while ( n > 0){
        if( n % 2){
            identity_matrix = multiply(identity_matrix, base);
        }
        base = multiply(base, base);
        n /= 2;
    }

    return identity_matrix;

}

int main(){

    int k; 
    long long n;

    cin >> k >> n;

    vector<vector<long long>> M(k, vector<long long>(k));

    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            cin >> M[i][j];
        }
    }

    vector<vector<long long>> ans = fast_expo_matrix(M, n);

    for (int i = 0; i < k; i++){
        for (int j = 0; j < k; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;

}