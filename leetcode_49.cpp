#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution49 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        // 以unordered_map記錄所有string的配組 (因sort過後，string相等則為同組)
        unordered_map<string, vector<string>> map;
        string tempStr;

        for (size_t i = 0; i < strs.size(); i++)
        {
            // 暫存該string
            tempStr = strs[i];
            // 將該string排列
            sort(strs[i].begin(),strs[i].end());
            // 輸入map中
            map[strs[i]].push_back(tempStr);
        }
        
        // 將各組倒出
        for (unordered_map<string, vector<string>>::iterator it = map.begin(); it != map.end(); it++)
        {
            res.push_back(it->second);
        }
        
        return res;
    }
};