#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;

        for (int i = 0; i < grid.size(); ++i) {
            int left = 0, right = grid[i].size() - 1;

            while (left <= right) {
                int mid = (left + right) / 2;

                if (grid[i][mid] >= 0)
                    left = mid + 1;
                else
                    right = mid - 1;
            }

            count += grid[i].size() - left;
        }

        return count;
    }
};


// deixando de antemao q eu consegui fazer esse exercício com o codigo abaixo, 0 ms

// class Solution {
// public:
//     int countNegatives(vector<vector<int>>& grid) {
//         int output= 0;
        
//         for(int i = 0; i < grid.size(); i++){
//             for( int j = 0; j < grid[i].size(); j++){ 
//                 if ( grid[i][j] < 0){
//                     output++;
//                 }
//             }
//         }
//         return output;
//     }
// };

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {5, 1, 0},
        {2, -1, -3},
        {-1, -2, -3}
    };

    int result = sol.countNegatives(grid);
    cout << "Número de negativos: " << result << endl;

    return 0;
}
