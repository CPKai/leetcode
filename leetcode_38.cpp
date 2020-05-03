#include <string>

using namespace std;
class Solution38 {
public:
    string countAndSay(int n) {
        // n=1直接return "1"  這是基底
        if (n == 1)
        {
            return "1";
        }
        else
        {
            // 非1時需要先取得n-1的值，這裡使用遞迴
            string input = countAndSay(n-1);


            string res = "";
            int count = 0;
            int value = 0;

            // 拿到n-1的字串後開始用for轉換成n的字串
            for (int i = 0; i < input.length(); i++)
            {
                // 只有第一圈會出現value==0
                if (value == 0)
                {
                    value = input[i] - '0';
                    count++;
                }
                else if (value == input[i] - '0')
                {
                    // 當value相等，出現次數++
                    count++;
                }
                else if (value != input[i] - '0')
                {
                    // value不同，push當前出現次數與value
                    res.push_back(count+'0');
                    res.push_back(value+'0');

                    // 更新出現次數與value
                    count = 1;
                    value = input[i] - '0';
                }
                
                if (i == input.length()-1)
                {
                    // 如果是最後一圈，把現存的count和value push入
                    res.push_back(count+'0');
                    res.push_back(value+'0');
                }
            }

            return res;
        }
    }
};