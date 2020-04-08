#include <string>
#include <algorithm>

using namespace std;

class Solution9 {
public:
    bool isPalindrome(int x) {
        bool res = false;

        long long temp = x;

         // 將數字寫入字串中
        string x_str = to_string(temp);
        string ans_str = to_string(temp);

        // 將字串反轉
        std::reverse(x_str.begin(),x_str.end());

        if (x_str == ans_str)
        {
            res = true;
        }

        return res;
    }
};