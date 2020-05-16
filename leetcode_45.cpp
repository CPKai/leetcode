#include <vector>

using namespace std;

class Solution45 {
public:
    int jump(vector<int>& nums) {
        int res = 0;

        // 當前index
        int currentIndex = 0;
        // 下一跳落點
        int predictIndex = 0;
        // 下一跳落點+落點值
        int maxDistance = 0;
        // 當前index value
        int currentValue = 0;

        // 還沒跳到終點前一直loop
        while (currentIndex < nums.size()-1)
        {
            // 設定當前value
            currentValue = nums[currentIndex];
            // 初始化maxDis等等for要使用
            maxDistance = 0;
            
            // 最高能前進currentValue個點
            for (int i = 1; i <= currentValue; i++)
            {
                // 如果currentIndex+i(即預測落點)+落點值超過nums.size()-1 (即這回跳完，下回可以close game)
                if ((currentIndex+i)+nums[currentIndex+i] >= nums.size()-1)
                {
                    // 預測落點選為此點
                    predictIndex = currentIndex+i;
                    // 跳到的最遠落點直接設為nums.size()-1 (最高不會超過此值)
                    maxDistance = nums.size()-1;
                    break;
                }
                
                // 如果currentIndex+i(即預測落點)+落點值超過maxDistance，則開始更新maxDistance
                if ((i+currentIndex)+nums[currentIndex+i] >= maxDistance)
                {
                    // 預測落點選為此點
                    predictIndex = currentIndex+i;
                    // 跳到最遠距=預測落點的index+落點值
                    maxDistance = predictIndex+nums[predictIndex];
                    
                    // 如果最遠距>=nums.size()-1，將最遠距設為nums.size()-1後直接出for
                    if (maxDistance >= nums.size()-1)
                    {
                        maxDistance = nums.size()-1;
                        break;
                    }
                }
            }

            // 如果maxDistance <= 當前值可跳的最遠距
            if (maxDistance <= currentIndex+currentValue)
            {
                // 預測落點直接採用當前值的最遠距 (因路上的預測落點值都無法超越當前值)
                // 即 當前點+值的距離 >= 預測點+預測點的值
                predictIndex = currentIndex+currentValue;
            }

            // 檢測完要跳到哪個index才是max值
            currentIndex = predictIndex;
            res++;
        }
        
        return res;
    }
};