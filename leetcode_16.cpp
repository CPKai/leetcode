#include <vector>
#include <algorithm>

using namespace std;
class Solution16 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0;
        
        int tempDis, disToTar = -1;

        // 先將input排序，之後好處理
        sort(nums.begin(),nums.end());

        // 當 nums為空 || nums中最小數>0 || nums中最大數<0 直接回傳空的res
        if (nums.empty() || nums.size() < 3)
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
                // 距離恆為正數，使用絕對值
                tempDis = abs(target-(nums[i]+nums[j]+nums[k]));
                
                // 當計算出來的距離<既存距離  或  既存距離<0(即初始設定值)
                if (tempDis < disToTar || disToTar < 0)
                {
                    disToTar = tempDis;
                    res = nums[i]+nums[j]+nums[k];
                }
                
                // 當target > 三者合，移動j(使3者合增大，靠向target)
                if (target-(nums[i]+nums[j]+nums[k]) > 0)
                {
                    // 左錨點向右移(增值)，進下一圈while
                    j++;
                }
                // 當target < 三者合，移動k(使3者合縮小，靠向target)
                else if (target-(nums[i]+nums[j]+nums[k]) < 0)
                {
                    // 右錨點向左移(減值)，進下一圈while
                    k--;
                }
                // 當target = 三者合，距離為0，直接返回結果
                else
                {
                    return res;
                }
            }
        }
        

        return res;
    }
};