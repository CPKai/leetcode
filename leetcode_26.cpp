#include <vector>
using namespace std;

class Solution26 {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            if (i<nums.size()-1 && nums[i] == nums[i+1])
            {
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums.size();
    }
};