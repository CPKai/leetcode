#include <limits>
class Solution29 {
public:
    int divide(int dividend, int divisor) {
        long int res = dividend / divisor;
        if (res > INT_MAX)
        {
            return INT_MAX;
        }
        else if (res < INT_MIN)
        {
            return INT_MIN;
        }
        
        
        return res;
    }
};