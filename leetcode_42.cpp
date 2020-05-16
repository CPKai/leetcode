#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution42 {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int res = 0;
        int leftHeight = 0;

        // 用以計算「右側高於左側」時的狀況
        for (int i = 0; i < height.size(); i++)
        {
            if (height[i] >= leftHeight && leftHeight != 0)
            {
                // 右側高於左側，且左側高度不為0，代表是一個合格的蓄水區
                while (st.top() != leftHeight)
                {
                    // 蓄水的高度 = 左側高 - 中間各格的高度
                    res = res + (leftHeight - st.top());
                    st.pop();
                }
                // 清空stack，確保第一位是新的左側高
                while (!st.empty())
                {
                    st.pop();
                }
                st.push(height[i]);
                leftHeight = height[i];
            }
            else if (height[i] >= leftHeight && leftHeight == 0)
            {
                // 右側高於左側，但左側高為0，無法形成蓄水區
                // 清空stack，確保第一位是新的左側高
                while (!st.empty())
                {
                    st.pop();
                }
                st.push(height[i]);
                leftHeight = height[i];
            }
            else if (height[i] < leftHeight)
            {
                // 左側高度>現在高度，先丟入stack看看後續會不會出現合格的右側高
                st.push(height[i]);
            }
        }

        // 最後一區可能發生左側高>右側高的蓄水區，但上方計算式無法計算，故確認現存stack有多少int值
        if (st.size() > 1)
        {
            vector<int> bonusVec;

            // stack中數值夠，則將內容全倒進新的vector，新的vector與原本數列排序相反(即原本左高右低，會轉為右高左低)
            while (!st.empty())
            {
                bonusVec.push_back(st.top());
                st.pop();
            }
            
            // 取得最後一個蓄水區的蓄水量再加入res中
            int bonus = trap(bonusVec);
            res = res + bonus;
        }
        
        return res;
    }
};