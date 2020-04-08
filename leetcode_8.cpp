#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Solution8 {
public:
    int myAtoi(string str) {
        int res = 0;
        try
        {
            // 會自動處理 非int值 & 超過int 上下限情況視同上下限
            std::istringstream(str) >> res;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        return res;
    }
};