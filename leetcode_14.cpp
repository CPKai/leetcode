#include <string>
#include <vector>

using namespace std;

class Solution14 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string res = "";
        int index, counter = 0;
        char compareChar = NULL;
        bool contin = true;

        // 判別strs與strs中第一字串是否為空
        if (strs.empty())
        {
            return res;
        }
        else if (strs[0].empty())
        {
            return res;
        }
        
        // contin always be true, while迴圈用來操作index值
        while (contin)
        {
            // 取得比較用字元
            compareChar = strs[0][index];

            // 對各字串進行操作
            for (int i = 0; i < strs.size(); i++)
            {   
                // 先確認index值未超過該字串的長度，超過直接return 當前res
                if (strs[i].length()-1 < index)
                {
                    return res;
                }

                // 開始比較各字串指定位子與比較用字元相比是否相同
                if (strs[i][index] == compareChar)
                {
                    if (i == strs.size()-1)
                    {
                        // 直至最後一圈(最後一個字串)都相同，則將res掛上次字元
                        res.append(strs[i].substr(index,1));
                    }
                    else
                    {
                        // 相同但非for最後一圈(即非最後一個字串)，則不做動作，繼續下一輪
                    }
                }
                else
                {
                    // 發現字元不同，直接return 當前res
                    return res;
                }
            }
            // 每輪結束將index值往前推
            index++;
        }
        return res;
    }
};