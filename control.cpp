#include <string>
#include <array>
#include <iostream>
#include <vector>
#include "leetcode_19.cpp"
using namespace std;

int main(){
    Solution19 s;
    
    std::string input_str = "23";
    std::string input_str2 = "*";
    int input_int = 2;
    vector<int> input_vector{1,-2,-5,-4,-3,3,3,5};
    vector<string> inputS_vector{"flower","flow","flight"};
    ListNode* head;
    ListNode* tempNode = new ListNode(0);
    for (int i = 0; i < 5; i++)
    {
        tempNode->next = new ListNode(i+1);
        if (i == 0)
        {
            head = tempNode->next;
        }
        tempNode = tempNode->next;
    }
    

    s.removeNthFromEnd(head,2);
    
    return 0;

}


