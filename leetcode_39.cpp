#include <vector>
using namespace std;

class Solution39 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tempVec;
        solution(candidates, target, 0, tempVec, res);

        return res;
    }

    void solution(vector<int>& candidates, int target, int startIndex, vector<int> tempVec, vector<vector<int>>& res) {
        
        if (target == 0)
        {
            res.push_back(tempVec);
            return;
        }
        
        for (int i = startIndex; i < candidates.size(); i++)
        {
            if (candidates[i] <= target)
            {
                tempVec.push_back(candidates[i]);
                solution(candidates, target-candidates[i],i,tempVec,res);
                tempVec.pop_back();
            }
        }
    }
};