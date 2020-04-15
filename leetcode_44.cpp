#include <string>
#include <regex>
using namespace std;

class Solution44 {
public:
    bool isMatch(string s, string p) {
        int s_anchor, p_anchor = 0;

        while (s_anchor != s.length() && p_anchor != p.length())
        {
            if (s[s_anchor] != p[p_anchor] && (p[p_anchor] != (char)"?" || p[p_anchor] != (char)"*"))
            {
                return false;
            }
            else
            {
                /* code */
            }
            
            
        }
        
        


    }
};