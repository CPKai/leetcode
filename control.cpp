#include <string>
#include <array>
#include <iostream>
#include <vector>
#include "leetcode_16.cpp"

int main(){
    Solution16 s;
    
    std::string input_str = "IV";
    std::string input_str2 = "*";
    int input_int = -59;
    vector<int> input_vector{13,2,0,-14,-20,19,8,-5,-13,-3,20,15,20,5,13,14,-17,-7,12,-6,0,20,-19,-1,-15,-2,8,-2,-9,13,0,-3,-18,-9,-9,-19,17,-14,-19,-4,-16,2,0,9,5,-7,-4,20,18,9,0,12,-1,10,-17,-11,16,-13,-14,-3,0,2,-18,2,8,20,-15,3,-13,-12,-2,-19,11,11,-10,1,1,-10,-2,12,0,17,-19,-7,8,-19,-17,5,-5,-10,8,0,-12,4,19,2,0,12,14,-9,15,7,0,-16,-5,16,-12,0,2,-16,14,18,12,13,5,0,5,6};
    vector<string> inputS_vector{"flower","flow","flight"};


    s.threeSumClosest(input_vector,input_int);
    
    return 0;


}


