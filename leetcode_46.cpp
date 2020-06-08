#include <vector>
#include <algorithm>

using namespace std;


class Solution46 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res;

        if (nums.empty())
        {
            return res;
        }

        // 主處理
        Permutation(nums, nums.size(), 0, res);


        return res;
    }
    
    void Permutation(vector<int> &nums, int size, int index, vector<vector<int>> &res)
    {
        // index等同size時代表完成一組，將其push入res中
        if (index == size)
        {
            res.push_back(nums);
        }
        
        // 核心
        for (int i = index; i < size; i++)
        {
            // 交換nums內位置i 與位置index的數
            swap(nums, i, index);
            // 將index前推一格，進入下一層
            Permutation(nums, size, index+1, res);
            // 換回nums內位置i 與位置index的數
            swap(nums, i, index);
        }
    }

    void swap(vector<int> &nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};