#include <vector>
#include <string>

using namespace std;

class Solution22 {
public:
    vector<string> generateParenthesis(int n) {
        
        // 將n值pass給nSize，使private func可以使用到n值
        nSize = n;
        // 初始字串
        string word = "(";
        // 開始遞迴
        generateParenthesis(word,1,0);

        return res;
    }
private:
    // 宣告nSize(用來裝題目給的n) 與 res(做為return result的變數)
    int nSize;
    vector<string> res;

    // 遞迴用主func
    void generateParenthesis(string word, int countOpen, int countClose){
        
        // 檢查左括與右括是否=n，成立則將word打入res中
        if (countOpen == nSize && countClose == nSize)
        {
            res.push_back(word);
        }
        // 當發現word中左括或右括已>n，則return，放棄此條遞迴路線
        else if (countOpen > nSize || countClose > nSize)
        {
            return;
        }

        // 未達成上面兩個條件則繼續遞迴

        // 若達成左括>右括，則新增路線：增加右括
        if (countOpen > countClose)
        {
            generateParenthesis(word+')',countOpen,countClose+1);
        }
        
        // 無條件路線：增加左括
        generateParenthesis(word+'(',countOpen+1,countClose);

    }
};