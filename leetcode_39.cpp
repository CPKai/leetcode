#include <vector>
using namespace std;

class Solution39 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;

        int divVal = 0;
        int restVal = 0;
        for (int i = candidates.size()-1; i >= 0; i--)
        {
            divVal = target / candidates[i];
            restVal = target % candidates[i];

            if (restVal == 0)
            {
                res.push_back(vector<int>(divVal,candidates[i]));
            }
            
        }
        
        return res;
    }

    void smallerSet(vector<int> inputVec, int target) {
        
    }
};