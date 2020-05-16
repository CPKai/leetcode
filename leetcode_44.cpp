#include <string>
#include <vector>
using namespace std;

class Solution44 {
public:
    bool isMatch(string s, string p) {

        // 建立一個二維棋盤，行數為p.size()+1，使行數最後一個index=p.size()
        // 每行會裝一個vector<bool>，欄數為s.size()+1，最後一個index=s.size()，內容則全設false
        vector<vector<bool>> board(p.size()+1,vector<bool>(s.size()+1,false));

        // 將起點設為true
        board[0][0] = true;

        // 假使輸入s=adceb，p=*a*b
        // 棋盤意義可視為
        // 
        //      0   a   d   c   e   b
        //  0   T
        //  *
        //  a
        //  *
        //  b

        // 判斷第一欄是否需要為true
        int index = 0;
        while (p[index]=='*')
        {
            // 不可使用index++，是要先進行index+法後再執行此行
            board[++index][0] = true;
        }
        
        // 假使輸入s=adceb，p=*a*b
        // 棋盤意義可視為
        // 
        //      0   a   d   c   e   b
        //  0   T
        //  *   T
        //  a
        //  *
        //  b

        // 核心for，i,j分別對應到p與s的index，來了解比對到哪個char
        // 而在棋盤上，p[i]與s[j]的比對格子剛好會是board[i+1][j+1]
        for (int i = 0; i < p.size(); i++)
        {
            for (int j = 0; j < s.size(); j++)
            {
                if (p[i] == s[j] || p[i] == '?')
                {
                    // 當字母相同或p='?'，則視為該格合格，可以繼承上一步的結果，上一步為true，則此為true
                    // 由於字母或是'?'都是只能單一配對(意即不像*可以對應到0~n個字)，故上一步一定是左上方(-1,-1)那格
                    board[i+1][j+1] = board[i][j];
                }
                else if (p[i] == '*')
                {
                    // 當p='*'時，視上一步內容而定，上一步可能為「左、左上、上」三格
                    // 可能為左：即上一個s內的char比對到此p char *，s的index++了(即右移一欄到此格)，而p的index未移動(仍在此行，因*可以應到多個字)
                    // 可能為左上：即上一個字母比對完後，p與s的index都移動到下一位的情況
                    // 可能為上：即s的index沒動，p的index卻動了，此情況只有p上一步是*才有可能達成
                    board[i+1][j+1] = board[i][j] || board[i+1][j] || board[i][j+1];
                }
            }
        }

        // 假使輸入s=adceb，p=*a*b
        // 棋盤意義可視為
        // 
        //      0   a   d   c   e   b
        //  0   T
        //  *   T   T   T   T   T   T
        //  a       T
        //  *       T   T   T   T   T
        //  b                       T


        // 最後return，此位子等同比對指針已指到p[p.size()-1], s[s.size()-1]
        return board[p.size()][s.size()];
    }
};