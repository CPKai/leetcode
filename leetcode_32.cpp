#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution32 {
public:
    int longestValidParentheses(string s) {

        int res = 0;
        if (s.length() == 0)
        {
            return res;
        }

        stack<int> st;
        st.push(-1);

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                // 打入左括位子
                st.push(i);
            }
            else
            {
                // 先將最後的左括pop掉
                st.pop();
                if (!st.empty())
                {
                    // 若非empty，現在長度應為 i(當前右括位子) - st.top() (由於配對用的左括被pop掉，這是前一個左括的位子，相減得到長度)
                    // 將當前長度與max比較，取max值為res;
                    res = max(res,i-st.top());
                }
                else
                {
                    // 若stack為空放入當前位子
                    st.push(i);
                }
            }
        }
        
        return res;

    }
};