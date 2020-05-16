#include <vector>
#include <string>
using namespace std;

class Solution43 {
public:
    string multiply(string num1, string num2) {

        string res;

        // 使用vector來儲存number，只不過為反序(方便直式乘除計算)
        // '-' - '0' = -3
        vector<int> numV_1;
        vector<int> numV_2;
        for (int i = num1.length()-1; i >= 0; i--)
        {
            if (num1[i] != '-')
            {
                numV_1.push_back(num1[i] - '0');
            }
        }
        for (int i = num2.length()-1; i >= 0; i--)
        {
            if (num2[i] != '-')
            {
                numV_2.push_back(num2[i] - '0');
            }
        }
        
        // 決定最終數為正數or負數
        if (num1[0]-'0'<0 ^ num2[0]-'0'<0)
        {
            res.push_back('-');
        }
        
        // init vector result，長度為兩個num size相加，所有內容為0
        vector<int> result(numV_1.size()+numV_2.size(),0);

        // 開始做直式乘法，最左側為個位數，往右依次十位、百位......
        // 乘完後結果依然是反序
        for (int i = 0; i < numV_1.size(); i++)
        {
            for (int j = 0; j < numV_2.size(); j++)
            {
                result[i+j] += numV_1[i] * numV_2[j];
                result[i+j+1] += result[i+j]/10;
                result[i+j] = result[i+j]%10;
            }
        }
        
        bool startPush = false;
        // 由於result是反序，從最後面開始將數字推至res
        for (int i = result.size()-1; i >= 0; i--)
        {
            // 初始startPush是false，要靠result指到非0值時轉為true
            if (startPush)
            {
                res.push_back(result[i]+'0');
            }
            else
            {
                if (result[i] != 0)
                {
                    // 非0時轉為true，同時將該數push進res
                    startPush = true;
                    res.push_back(result[i]+'0');
                }
                else if (i == 0)
                {
                    // startPush為false同時i又已指到0 (即最後一圈)，代表result全為0，push進0做為解答
                    res.push_back(result[i]+'0');
                }
            }
        }
        
        return res;

    }
};