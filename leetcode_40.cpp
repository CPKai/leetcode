#include <vector>
#include <algorithm>
using namespace std;

class Solution40 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tempVec;
        // 利用39題的解，在進行作業前先sort candidates
        sort(candidates.begin(), candidates.end());
        solution(candidates, target, 0, tempVec, res);

        return res;
    }

    void solution(vector<int>& candidates, int target, int startIndex, vector<int> tempVec, vector<vector<int>>& res) {
        
        if (target == 0)
        {
            if (res.empty())
            {
                res.push_back(tempVec);
            }
            else
            {
                // 在每次加入新解前，確認與既存的解不重複
                for (int i = 0; i < res.size(); i++)
                {
                    if (res[i] == tempVec)
                    {
                        return;
                    }
                }
                res.push_back(tempVec);
            }
            return;
        }
        
        for (int i = startIndex; i < candidates.size(); i++)
        {
            if (candidates[i] <= target)
            {
                tempVec.push_back(candidates[i]);
                solution(candidates, target-candidates[i],i+1,tempVec,res);
                tempVec.pop_back();
            }
        }
    }
};