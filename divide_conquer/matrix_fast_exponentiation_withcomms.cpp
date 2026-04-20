#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;

void printMatrix(vector<vector<long long>> &M, string name){
    int k = M.size();
    cout << "\n=== " << name << " ===\n";
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "=====================\n";
}

vector<vector<long long>> multiply(vector<vector<long long>> &A, vector<vector<long long>> &B){
    int k = A.size();

    vector<vector<long long>> result(k, vector<long long>(k, 0));

    cout << "\n>>> MULTIPLY <<<\n";
    printMatrix(A, "Matrix A");
    printMatrix(B, "Matrix B");

    for (int row = 0; row < k; row++){
        for (int col = 0; col < k; col++){
            for (int d = 0; d < k; d++){
                long long mult = (A[row][d] * B[d][col]) % MOD;
                result[row][col] = (result[row][col] + mult) % MOD;

                cout << "result[" << row << "][" << col << "] += "
                     << A[row][d] << " * " << B[d][col]
                     << " = " << mult
                     << " -> " << result[row][col] << "\n";
            }
        }
    }

    printMatrix(result, "Result of Multiply");
    return result;
}

vector<vector<long long>> fast_expo_matrix(vector<vector<long long>> base, long long n){

    int k = base.size();

    vector<vector<long long>> identity_matrix(k, vector<long long>(k, 0));

    for (int i = 0; i < k; i++){
        identity_matrix[i][i] = 1;
    }

    int step = 0;

    while (n > 0){
        cout << "\n#############################\n";
        cout << "STEP " << step++ << " | n = " << n << "\n";

        printMatrix(identity_matrix, "Current RESULT");
        printMatrix(base, "Current BASE");

        if (n % 2){
            cout << "\n-- n is ODD → RESULT = RESULT * BASE --\n";
            identity_matrix = multiply(identity_matrix, base);
        }

        cout << "\n-- BASE = BASE * BASE --\n";
        base = multiply(base, base);

        n /= 2;
    }

    cout << "\n===== FINAL RESULT =====\n";
    printMatrix(identity_matrix, "M^n");

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

    cout << "\n===== INPUT MATRIX =====\n";
    printMatrix(M, "Original Matrix");

    vector<vector<long long>> ans = fast_expo_matrix(M, n);

    cout << "\n===== OUTPUT =====\n";
    for (int i = 0; i < k; i++){
        for (int j = 0; j < k; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}