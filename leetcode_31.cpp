#include <vector>
#include <algorithm>
using namespace std;

class Solution31 {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
};