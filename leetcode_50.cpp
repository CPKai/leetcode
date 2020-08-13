#include <math.h>

class Solution50 {
public:
    double myPow(double x, int n) {
        // 設置我們要操作的變數(不直接使用input)
        long double myN = n;

        // 如果指數值(n)<0，形同基數轉為倒數配正指數   (即x的-n次方 = 1/x的n次方)
        if (n<0)
        {
            myN=-(double)n;
            x=1/x;
        }

        // 所有數的0次方=1
        if (myN==0)
        {
            return 1;
        }
        
        // 進行遞迴，最後一輪會return 1回來(myN==0)
        double temp = myPow(x,myN/2);

        // 此時的func 是找 x的n次方，而temp出來結果是x的n/2次方
        
        // 判斷n是否被2整除，如果整除，代表x的n次方等同temp的平方
        if (n%2 == 0)
        {
            return temp*temp;
        }

        // 若未被2整除，代表前面計算temp用的myN/2會被多-1(指傳入的n值被-1)，這時我們除了temp平方外，再額外加入一個x(即x的一次方)
        return x*temp*temp;


        // 內鍵func
        // return pow(x,n);
    }
};