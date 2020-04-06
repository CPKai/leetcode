#include <cstring>
#include <string>
#include <stdlib.h>
using namespace std;

class Solution6 {
public:
    string convert(string s, int numRows) {

        // input s 為空或numRows < 1時直接回傳空值
        if (s == "" || numRows < 1)
        {
            return "";
        }

        // numRows為1時直接回傳input s
        if (numRows == 1)
        {
            return s;
        }
        
        string res = "";
        // 1 shift為1組，1組為V字。左尖端為自row 1的字姆，右尖端為row 2的字姆
        // 以abcdefghijk為例   row為5
        // a       i
        // b     h j
        // c   g   k
        // d f
        // e
        // 則時1組=a到h，1shiftSize為 (5-1)*2=8
        int shiftSize = (numRows - 1) * 2;

        // 因型別問題所建立的變數，中轉用
        char tempC;

        // i值代表當前rows，以0為起始
        for (int i = 0; i < numRows; i++)
        {
            // 在第i row的情況下，找出此row所有字姆並append至result string中
            for (int j = 0 + i; j < s.length(); j+=shiftSize)
            {
                if (i == 0 || i == numRows - 1)
                {
                    tempC = s[j];
                    res.append(1,tempC);
                }
                else
                {
                    // 非第一或最後一row的情況下，同個shift內會有兩個字姆
                    tempC = s[j];
                    res.append(1,tempC);

                    // 執行第二字姆處理前先判定該位置是否超過input s最大值。因最後一shift是未填滿的shift，可能該row該組只有1個字姆。
                    if (j+shiftSize-(i*2) < s.length())
                    {
                        // 第二個字姆處理
                        tempC = s[j+shiftSize-(i*2)];
                        res.append(1,tempC);
                    }
                }
            }
        }
        return res;
    }
};