#include <vector>
#include <algorithm>
using namespace std;

class Solution41 {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        // 題目所指第一個遺失的正整數
        // 所謂第一，並非指從nums中最小正整數開始計算，而是從 "1" 來開始計算
        // 所以不論nums內數字多少，只要缺少1，答案就必定是1

        // nums為空，直接回傳1
        if (nums.size() == 0)
        {
            return 1;
        }
        
        // 建立一個bool vec，長度設成nums.size()+1，並全設fasle
        // 以此vec代表該數值是否出現過，vecBool[1] == false代表1並未出現在nums的value中
        // 設為nums.size()+1的長度是假設nums是從1開始遞增的陣列，最高數值只會到nums.size()
        // 換算到vecBool要容納nums.size()個正整數，需要nums.size()+1的長度(因vecBool有包含0)
        vector<bool> vecBool(nums.size()+1,false);

        for (int i = 0; i < nums.size(); i++)
        {
            // 確認nums[i]>0 且nums[i]的值<=nums.size()，將vecBool該index調為true，代表該值出現過
            // 因vecBool長度為nums.size()+1，故最後一個index是nums.size()
            if (nums[i]>0 && nums[i]<=nums.size())
            {
                vecBool[nums[i]] = true;
            }
        }
        
        // 從index 1開始找vecBool中第一個false(沒出現過)的正整數
        for (int i = 1; i <= nums.size(); i++)
        {
            if (vecBool[i] == false)
            {
                return i;
            }
            
        }

        // 全出現過則直接return nums.size()+1
        return nums.size()+1;
    }
};