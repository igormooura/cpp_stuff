#include <bits/stdc++.h>

#define endl '\n'
#define MOD 1e9 + 7

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;
using tiii = tuple<int, int, int>;

bool backtrack(vector<vi> &ball, int i, int j)
{
    int n = ball.size();

    if (i == n)
        return true;

    if (ball[i][j] != 0){ // se já tá preenchida, vai pro proximo
        if (j == n - 1)
            return backtrack(ball, i + 1, 0);

        return backtrack(ball, i, j + 1);
    }
    else{
        for (int valor = 1; valor <= n; valor++){
            bool valido = true;
            // linha
            for (int col = 0; col < n; col++){
                if (ball[i][col] == valor){
                    valido = false;
                    break;
                }
            }

            // coluna
            for (int row = 0; row < n && valido; row++){
                if (ball[row][j] == valor){
                    valido = false;
                    break;
                }
            }

            if (!valido)
                continue;

            ball[i][j] = valor; // faz escolha

            bool achou;

            if (j == n - 1)
                achou = backtrack(ball, i + 1, 0);
            else
                achou = backtrack(ball, i, j + 1);

            if (achou)
                return true;

            ball[i][j] = 0; // desfaz escolha
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<vi> ball(n, vi(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ball[i][j];
        }
    }

    bool backtracking = backtrack(ball, 0, 0);

    if(!backtracking) cout << "-1" << endl; 
    else 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ball[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}