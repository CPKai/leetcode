#include <string>
#include <regex>

using namespace std;

class Solution10 {
public:
    bool isMatch(string s, string p) {
        regex reg(p);

        if (regex_match(s,reg))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};