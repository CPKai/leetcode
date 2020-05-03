#include <vector>
#include <algorithm>
using namespace std;

class Solution31 {
public:
    void nextPermutation(vector<int>& nums) {
        // leetcode will pop error
        // std::sort(nums.begin(),nums.end());

        // brute-force    error too.
        // for (int i = 0; i < nums.size()-1; i++)
        // {
        //     for (int j = i+1; j < nums.size(); j++)
        //     {
        //         if (nums[i] > nums[j])
        //         {
        //             int temp = nums[i];
        //             nums[i] = nums[j];
        //             nums[j] = temp;
        //         }
        //     }
        // }
        
        // error too.
        // ::next_permutation(nums.begin(),nums.end());
    }
};