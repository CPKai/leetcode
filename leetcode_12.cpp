#include <string>

using namespace std;

class Solution12 {
public:
    string intToRoman(int num) {

    	string res = "";
    	int tempNum;
        // I = 1
        // V = 5 / IV = 4
        // X = 10 / IX = 9
        // L = 50 / XL = 40
        // C = 100 / XC = 90
        // D = 500 / CD = 400
        // M = 1000 / CM = 900

        while(num != 0)
        {
        	if (num/1000 > 0)
        	{
        		tempNum = num/1000;
        		for (int i = 0; i < tempNum; ++i)
        		{
        			res.append("M");
        			num -= 1000;
        		}
        	}
        	else if (num/900 > 0)
        	{
        		tempNum = num/900;
        		for (int i = 0; i < tempNum; ++i)
        		{
        			res.append("CM");
        			num -= 900;
        		}
        			
        	}
        	else if (num/500 > 0)
        	{
        		tempNum = num/500;
        		for (int i = 0; i < tempNum; ++i)
        		{
        			res.append("D");
        			num -= 500;
        		}
        		
        	}
        	else if (num/400 > 0)
        	{
        		tempNum = num/400;
        		for (int i = 0; i < tempNum; ++i)
        		{
        			res.append("CD");
        			num -= 400;
        		}
        		
        	}
        	else if (num/100 > 0)
        	{
        		tempNum = num/100;
        		for (int i = 0; i < tempNum; ++i)
        		{
        			res.append("C");
        			num -= 100;
        		}
        		
        	}
        	else if (num/90 > 0)
        	{
        		tempNum = num/90;
        		for (int i = 0; i < tempNum; ++i)
        		{
        			res.append("XC");
        			num -= 90;
        		}

        	}
        	else if (num/50 > 0)
        	{
        		tempNum = num/50;
        		for (int i = 0; i < tempNum; ++i)
        		{
        			res.append("L");
        			num -= 50;
        		}
        		
        	}
        	else if (num/40 > 0)
        	{
        		tempNum = num/40;
        		for (int i = 0; i < tempNum; ++i)
        		{
        			res.append("XL");
        			num -= 40;
        		}
        		
        	}
        	else if (num/10 > 0)
        	{
        		tempNum = num/10;
        		for (int i = 0; i < tempNum; ++i)
        		{
        			res.append("X");
        			num -= 10;
        		}
        		
        	}
        	else if (num/9 > 0)
        	{
        		tempNum = num/9;
        		for (int i = 0; i < tempNum; ++i)
        		{
        			res.append("IX");
        			num -= 9;
        		}
        		
        	}
        	else if (num/5 > 0)
        	{
        		tempNum = num/5;
        		for (int i = 0; i < tempNum; ++i)
        		{
        			res.append("V");
        			num -= 5;
        		}
        		
        	}
        	else if (num/4 > 0)
        	{
        		tempNum = num/4;
        		for (int i = 0; i < tempNum; ++i)
        		{
        			res.append("IV");
        			num -= 4;
        		}
        		
        	}
        	else if (num/1 > 0)
        	{
        		tempNum = num/1;
        		for (int i = 0; i < tempNum; ++i)
        		{
        			res.append("I");
        			num -= 1;
        		}
        	}
        	else
        	{
        		res = "something going wrong";
        	}
        }
        
        return res;
    }
};
