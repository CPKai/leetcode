#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;


class Solution7 {
public:
    int reverse(int x) {
        
        int res = 0;
        long long temp = 0;

        // 一律切為正數做處理
        if (x < 0)
        {
            // 在case -2147483648 中，-x=2147483648 超過int 32的最大值，故此解不使用temp = -x，改為兩部驟來轉換x值至temp
            temp = x;
            temp = -temp;
        }
        else
        {
            temp = x;
        }
        
        // 將數字寫入字串中
        string x_str = to_string(temp);

        // 將字串反轉
        std::reverse(x_str.begin(),x_str.end());

        try
        {
            // 將反轉後的字串寫回temp中
            std::istringstream(x_str) >> temp;
            
            // 若反轉後的值超過int 32最大值則回傳0
            if (temp > 2147483647)
            {
                return 0;
            }

            // 將答案寫入res
            if (x < 0)
            {
                res = -temp;
            }
            else
            {
                res = temp;
            }
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        return res;
    }
};