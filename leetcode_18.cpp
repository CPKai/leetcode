#include <vector>
#include <algorithm>

using namespace std;

class Solution18 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        // 由第15題之邏輯進行調整所得的解法，註解部份可參考15題
        vector<vector<int>> res{};

        // 先將input排序，之後好處理
        sort(nums.begin(),nums.end());

        if (nums.empty() || nums.size() < 4)
        {
            return res;
        }
        
        // 初始化左右錨點
        int j,k;

        // x為固定住的值(fix value)，從最左側開始
        for (int x = 0; x < nums.size()-3; x++)
        {
            for (int y = nums.size()-1; y > 2; y--)
            {
                // 定出左右錨點位置
                j = x + 1;
                k = y - 1;

                // 當右錨仍在左錨的右側
                while (k - j > 0)
                {
                    if (nums[j]+nums[k]+nums[x]+nums[y] == target)
                    {
                        // 新增result
                        res.push_back(vector<int> {nums[x],nums[j],nums[k],nums[y]});

                        // 左右錨點同時向內縮，同時處理數值相同的問題(再往內縮一格)
                        while (nums[j] == nums[j+1] && j < k-1)
                        {
                            j++;
                        }
                        j++;
                        while (nums[k] == nums[k-1] && k > j+1)
                        {
                            k--;
                        }
                        k--;
                        
                        
                    }
                    else if ((nums[j]+nums[k]+nums[x]+nums[y]) < target)
                    {
                        // 左錨點向右移(增值)，進下一圈while
                        j++;
                    }
                    else if ((nums[j]+nums[k]+nums[x]+nums[y]) > target)
                    {
                        // 右錨點向左移(減值)，進下一圈while
                        k--;
                    }
                }

                while (nums[y] == nums[y-1] && y-1 > 0)
                {
                    y--;
                }
            }

            while (nums[x] == nums[x+1] && x+1 < nums.size()-1)
            {
                x++;
            }
        }
        

        return res;
    }
};