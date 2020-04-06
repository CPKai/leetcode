#include <iostream>
#include <string>
using namespace std;

class Solution3 {
public:
    int lengthOfLongestSubstring(std::string s) {
        int max_length = 1;
        std::string tempString, compareString = "";

        int left_anchor = 0;

        // 空字串預先例外處理
        if (s=="")
        {
            return 0;
        }
        
        // 設計三個錨點left, right, pare
        // 外for為右錨值，從position 1開始一直推進到字串最後一位
        // 內for為pare錨值，依每輪left_anchor值做為起點，推進到right_anchor - 1
        // 當內for成功跑到right_anchor - 1 ，代表當前字串中最後一個字符跟先前任何字符相異，此時計算總字串長(right_anchor - left_anchor + 1)，並與已儲存之max_length比較，將較大者寫入max_length
        // 若找到字符(pare_anchor處)與最後一個字符(right_anchor處)相等，則將left_anchor設為pare_anchor + 1並離開內for

        for (int right_anchor = 1; right_anchor < s.length(); right_anchor++)
        {
            for (int pare_anchor = left_anchor; pare_anchor < right_anchor; pare_anchor++)
            {
                compareString = s.substr(pare_anchor,1);
                tempString = s.substr(right_anchor,1);
                if (compareString == tempString)
                {
                    left_anchor = pare_anchor + 1;
                    break;
                }
                else if (pare_anchor == right_anchor-1)
                {
                    if (max_length < (right_anchor - left_anchor + 1)) //012  2-0=2 實際長度為3 故+1
                    {
                        max_length = (right_anchor - left_anchor + 1);
                    }
                }
            }
        }
        return max_length;
    }

    
};