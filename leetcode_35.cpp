#include <vector>
using namespace std;

class Solution35 {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                return i;
            }
            else if (nums[i] > target)
            {
                return i;
            }
            else if (i == nums.size()-1)
            {
                return i+1;
            }
        }

        // nums為空的情況
        return 0;
    }
};