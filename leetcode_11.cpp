#include <vector>
#include <algorithm>

using namespace std;

class Solution11 {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        
        int tempArea = 0;

        // 
        // *********** brute force ************
        // 
        // for (int i = 0; i < height.size(); i++)
        // {
        //     for (int j = i+1; j < height.size(); j++)
        //     {
        //         if (height[j] > height[i])
        //         {
        //             tempArea = (j - i) * height[i];
        //         }
        //         else
        //         {
        //             tempArea = (j - i) * height[j];
        //         }
                
        //         if (tempArea > res)
        //         {
        //             res = tempArea;
        //         }
        //     }
        // }

        int left_anchor, right_anchor;
        left_anchor = 0;
        right_anchor = height.size()-1;

        while (left_anchor != right_anchor)
        {
            tempArea = (right_anchor - left_anchor) * min(height[left_anchor],height[right_anchor]);

            if (res < tempArea)
            {
                res = tempArea;
            }
            
            if (height[left_anchor] > height[right_anchor])
            {
                right_anchor--;
            }
            else
            {
                left_anchor++;
            }
        }
        

        return res;
    }
};