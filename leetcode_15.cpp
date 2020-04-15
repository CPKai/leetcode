#include <vector>
#include <algorithm>

using namespace std;
class Solution15 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res{};

        // 先將input排序，之後好處理
        sort(nums.begin(),nums.end());

        // 當 nums為空 || nums中最小數>0 || nums中最大數<0 直接回傳空的res
        if (nums.empty() || nums.front() > 0 || nums.back() < 0 || nums.size() < 3)
        {
            return res;
        }
        
        // 初始化左右錨點
        int j,k;

        // i為固定住的值(fix value)，從最左側開始
        for (int i = 0; i < nums.size()-2; i++)
        {
            // 定出左右錨點位置
            j = i + 1;
            k = nums.size()-1;

            // 當右錨仍在左錨的右側
            while (k - j > 0)
            {
                // (nums[j]+nums[k]) == -nums[i] 即3者相加為0
                if ((nums[j]+nums[k]) == -nums[i])
                {
                    // 新增result
                    res.push_back(vector<int> {nums[i],nums[j],nums[k]});

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
                else if ((nums[j]+nums[k]) < -nums[i])
                {
                    // 左錨點向右移(增值)，進下一圈while
                    j++;
                }
                else if ((nums[j]+nums[k]) > -nums[i])
                {
                    // 右錨點向左移(減值)，進下一圈while
                    k--;
                }
            }

            // 推進i至相同數值的最後一個，待for的i++後會走到第一個相異數
            while (nums[i] == nums[i+1] && i+1 < nums.size()-1)
            {
                i++;
            }
            
        }
        

        return res;
    }
};