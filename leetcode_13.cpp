#include <string>

using namespace std;

class Solution13 {
public:
    int romanToInt(string s) {
        int res = 0;

        // I = 1
        // V = 5 / IV = 4
        // X = 10 / IX = 9
        // L = 50 / XL = 40
        // C = 100 / XC = 90
        // D = 500 / CD = 400
        // M = 1000 / CM = 900

        int s_index = 0;
        char* compareChar = NULL;

        while (s_index < s.length())
        {
            if (s[s_index] == 'M')
            {
                res += 1000;
                s_index++;
            }
            else if (s[s_index] == 'D')
            {
                res += 500;
                s_index++;
            }
            else if (s[s_index] == 'C')
            {
                if (s_index + 1 < s.length())
                {
                    if (s[s_index+1] == 'M')
                    {
                        res += 900;
                        s_index += 2;
                    }
                    else if (s[s_index+1] == 'D')
                    {
                        res += 400;
                        s_index += 2;
                    }
                    else
                    {
                        res += 100;
                        s_index++;
                    }
                }
                else
                {
                    res += 100;
                    s_index++;
                }
            }
            else if (s[s_index] == 'L')
            {
                res += 50;
                s_index++;
            }
            else if (s[s_index] == 'X')
            {
                if (s_index + 1 < s.length())
                {
                    if (s[s_index+1] == 'C')
                    {
                        res += 90;
                        s_index += 2;
                    }
                    else if (s[s_index+1] == 'L')
                    {
                        res += 40;
                        s_index += 2;
                    }
                    else
                    {
                        res += 10;
                        s_index++;
                    }
                }
                else
                {
                    res += 10;
                    s_index++;
                }
            }
            else if (s[s_index] == 'V')
            {
                res += 5;
                s_index++;
            }
            else if (s[s_index] == 'I')
            {
                if (s_index + 1 < s.length())
                {
                    if (s[s_index+1] == 'X')
                    {
                        res += 9;
                        s_index += 2;
                    }
                    else if (s[s_index+1] == 'V')
                    {
                        res += 4;
                        s_index += 2;
                    }
                    else
                    {
                        res += 1;
                        s_index++;
                    }
                }
                else
                {
                    res += 1;
                    s_index++;
                }
            }
            else
            {
                // something going wrong
                return 0;
            }
            
        }
        
        return res;
    }
};