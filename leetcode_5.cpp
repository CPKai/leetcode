#include <string>
using namespace std;

class Solution5 {
public:
    string longestPalindrome(string s) {

        string result = "";
        int result_left_index, result_right_index = 0;
        int leftIndex, rightIndex = 0;
        // 當input字串長度<=1，則直接回傳input string
        if (s.length() <= 1)
        {
            return s;
        }
        
        // i為左index值，只到最後一位的前一位index
        for (int i = 0; i < s.length()-1; i++)
        {
            if (s.length() - i < result_right_index - result_left_index + 1)
            {
                // i只會越來越大，條件式左側值只會越來越小，當左已<右直接跳脫i for
                break;
            }
            
            // j為右index值，只到i右一位
            for (int j = s.length()-1; j > i; j--)
            {
                // 比對既有答案的長度，若已大於預比較的組別(j-1+1)則直接break此j for (長度為j-i+1，只是條件式兩邊都+1故省略)
                if (j-i > result_right_index-result_left_index)
                {
                    // 遞迴func為true則代表成功找到一組回文
                    // if (matchingStr(s, i, j))
                    // {
                    //     result_left_index = i;
                    //     result_right_index = j;
                    //     result = s.substr(i,j-i+1);
                    // }


                    // 遞迴用法會被leetcode標為Time Limit Exceeded，改以while來實作遞迴func的邏輯。
                    // 遞迴效能 412 ms | while效能 8, 4 ms
                    leftIndex = i;
                    rightIndex = j;
                    while (leftIndex <= rightIndex)
                    {
                        // 確認當前比對的兩個字姆是否相符
                        if (s.at(leftIndex) == s.at(rightIndex))
                        {
                            // 相符後確認兩著index差距是否為2以上，true則讓兩個index繼續靠攏
                            if (rightIndex-leftIndex > 1)
                            {
                                leftIndex = leftIndex + 1;
                                rightIndex = rightIndex - 1;
                            }
                            else
                            {
                                // 字姆相符且差距為1 or 0時，代表字串已成功找到
                                result_left_index = i;
                                result_right_index = j;
                                result = s.substr(i,j-i+1);
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    

                }
                else
                {
                    break;
                }
            }
        }
        
        if (result == "")
        {
            // input str長度>=2，但仍未找到任一回文，則代表所有字姆皆相異，取第一字姆做為解答
            result = s[0];
            return result;
        }
        else
        {
            return result;
        }
    }

    // bool matchingStr(string s, int leftIndex, int rightIndex){

    //     // 確認當前比對的兩個字姆是否相符
    //     if (s.at(leftIndex) == s.at(rightIndex))
    //     {
    //         // 相符後確認兩著index差距是否為2以上，true則讓兩個index繼續靠攏
    //         if (rightIndex-leftIndex > 1)
    //         {
    //             return matchingStr(s,leftIndex+1, rightIndex-1);
    //         }
    //         else
    //         {
    //             // 字姆相符且差距為1 or 0時，代表字串已成功找到
    //             return true;
    //         }
    //     }
    //     else
    //     {
    //         return false;
    //     }
    // }
};