#include <string>
#include <stack>

using namespace std;
class Solution20 {
public:
    bool isValid(string s) {
        bool res = false;
        stack<char> box;
        int index = 0;

        if (s.length()%2 == 1)
        {
            return false;
        }
        

        while (index < s.length())
        {
            if (s[index] == '{' || s[index] == '[' || s[index] == '(')
            {
                box.push(s[index]);
            }
            else
            {
                if (s[index] == '}')
                {
                    if (!box.empty() && box.top() == '{')
                    {
                        box.pop();
                    }
                    else
                    {
                        return res;
                    }
                }
                else if (s[index] == ']')
                {
                    if (!box.empty() && box.top() == '[')
                    {
                        box.pop();
                    }
                    else
                    {
                        return res;
                    }
                }
                else if (s[index] == ')')
                {
                    if (!box.empty() && box.top() == '(')
                    {
                        box.pop();
                    }
                    else
                    {
                        return res;
                    }
                }
            }
            index++;
        }

        // empty() == true代表成功配對所有字元
        res = box.empty();
        return res;
    }
};