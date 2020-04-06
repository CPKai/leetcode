// 
// 4. Median of Two Sorted Arrays
// 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution4 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result = 0;
        vector<int> nums3;


        // judge that nums1 and nums2 empty or not
        if (nums1.empty() || nums2.empty())
        {
            if (nums1.empty())
            {
                nums3.assign(nums2.begin(),nums2.end());
            }
            else
            {
                nums3.assign(nums1.begin(),nums1.end());
            }
        }
        else
        {
            nums3.assign(nums1.begin(),nums1.end());
            nums3.insert(nums3.end(),nums2.begin(),nums2.end());
        }
        
        
        int temp = 0;

        
        // sort num3
        for (int i = 0; i < nums3.size()-1; i++)
        {
            for (int j = i+1; j < nums3.size(); j++)
            {
                if (nums3[i] > nums3[j])
                {
                    temp = nums3[j];
                    nums3[j] = nums3[i];
                    nums3[i] = temp;
                }
            }
        }

        if (nums3.size() % 2 == 1)
        {
            result = double (nums3[(nums3.size() / 2)]);  //中位數為奇數值的/2+1，但在vector中的position需-1，例：11數值中位數為11/2+1=6，為vector[5]
        }
        else
        {
            result = double (nums3[(nums3.size() / 2)] + nums3[nums3.size() / 2 - 1]) / 2;
        }

        // get result
        // cout << "********************************" << endl;
        // cout << "result is:" << result << endl;
        // cout << "********************************" << endl;
        return result;
    }
};



