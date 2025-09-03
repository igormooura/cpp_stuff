#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        int middle = nums.size() / 2;

        if (nums.size() > 1)
        {
            vector<int> v1(middle);
            vector<int> v2(nums.size() - middle);


            // colocar os trem nos vetores
            for (int i = 0; i < middle; i++)
            {
                v1[i] = nums[i];
            }

            for (int j = middle; j < nums.size(); j++)
            {
                v2[j - middle] = nums[j];
            }

            // ordena cada metade recursivamente
            v1 = sortArray(v1);
            v2 = sortArray(v2);

            return merge(v1, v2);
        }
        return nums;
    }

private:
    vector<int> merge(vector<int> &left, vector<int> &right)
    {
        vector<int> result(left.size() + right.size());

        int i = 0, j = 0, k = 0; // i = left, j = right


        // intercala elementos dos 2 vetores enquanto eles tem elementos
        while (i < left.size() && j < right.size())
        {
            if (left[i] <= right[j])
            {
                result[k++] = left[i++];
            }
            else
            {
                result[k++] = right[j++];
            }
        }

        //adiciona os elementos restantes, no caso o haja diferença entre right e left

        while (i < left.size()){ 
            result[k++] = left[i++];
        }
        while (j < right.size()){ 
            result[k++] = right[j++];
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5, 2, 3, 1, 4};
    vector<int> sorted = s.sortArray(nums);

    cout << "Vetor ordenado: ";
    for (int n : sorted)
        cout << n << " ";
    cout << endl;

    return 0;
}
