#include <vector>
#include <algorithm>
using namespace std;

class Solution33 {
public:
    int search(vector<int>& nums, int target) {
        
        // nums為空處理
        if (nums.size() <= 0)
        {
            return -1;
        }
        
        // 取得max value的index 將nums看成兩段已排列過的數列
        int maxIndex = max_element(nums.begin(),nums.end()) - nums.begin();

        // 找出要使用左還右數列
        int left_anchor, right_anchor;
        if (target > nums[nums.size()-1])
        {
            left_anchor = 0;
            right_anchor = maxIndex;
        }
        else
        {
            // 當maxIndex=最後一位，nums等同一段數列，未被切分為兩段數列
            if (maxIndex == nums.size()-1)
            {
                left_anchor = 0;
                right_anchor = maxIndex;
            }
            else
            {
                left_anchor = maxIndex + 1;
                right_anchor = nums.size()-1;
            }
        }
        
        // 取得中央點
        int current_anchor = (right_anchor+left_anchor)/2;


        // binary search
        while (true)
        {
            if (nums[current_anchor] == target)
            {
                return current_anchor;
            }
            else if (nums[current_anchor] > target)
            {
                right_anchor = current_anchor - 1;
                current_anchor = (right_anchor+left_anchor)/2;
            }
            else if (nums[current_anchor] < target)
            {
                left_anchor = current_anchor + 1;
                current_anchor = (right_anchor+left_anchor)/2;
            }

            
            if (right_anchor < left_anchor)
            {
                return -1;
            }
        }
        
    }
};