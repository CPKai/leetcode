#include <string>
using namespace std;


class Solution28 {
public:
    int strStr(string haystack, string needle) {
        int res = -1;


        res = haystack.find(needle);

        if (res != string::npos)
        {
            return res;
        }
        else
        {
            return -1;
        }
        
        
    }
};