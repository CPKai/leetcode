#include <vector>
#include <algorithm>
using namespace std;

class Solution34 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> res{-1,-1};

        // nums為空處理
        if (nums.size() <= 0)
        {
            return res;
        }

        int left_anchor, right_anchor;
        left_anchor = 0;
        right_anchor = nums.size()-1;
        int current_anchor = (right_anchor+left_anchor)/2;

        // binary search
        while (true)
        {
            if (nums[current_anchor] == target)
            {
                // 找到target後，將左右錨賦值：當前targetIndex，再將左右錨分別向左右外推，最後停下的位子就是最左、右的targetIndex
                left_anchor = current_anchor;
                right_anchor = current_anchor;
                while (true)
                {
                    if (left_anchor-1 > -1 && nums[left_anchor-1] == target)
                    {
                        left_anchor--;
                    }
                    else if (right_anchor+1 < nums.size() && nums[right_anchor+1] == target)
                    {
                        right_anchor++;
                    }
                    else
                    {
                        res = {left_anchor,right_anchor};
                        return res;
                    }
                }
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
                return res;
            }
        }
    }
};