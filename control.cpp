#include <string>
#include <array>
#include <iostream>
#include <vector>
#include "leetcode_24.cpp"
using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };


int main(){
    Solution24 s;
    
    // std::string input_str = "]";
    // std::string input_str2 = "*";
    // int input_int = 2;
    // vector<int> input_vector{1,-2,-5,-4,-3,3,3,5};
    // vector<string> inputS_vector{"flower","flow","flight"};
    // ListNode* head;
    // ListNode* tempNode = new ListNode(0);
    // for (int i = 0; i < 5; i++)
    // {
    //     tempNode->next = new ListNode(i+1);
    //     if (i == 0)
    //     {
    //         head = tempNode->next;
    //     }
    //     tempNode = tempNode->next;
    // }
    
    ListNode* LN1 = new ListNode(1);
    LN1->next = new ListNode(2);
    LN1->next->next = new ListNode(3);
    LN1->next->next->next = new ListNode(4);

    ListNode* LN2 = new ListNode(0);
    // LN2->next = new ListNode(3);
    // LN2->next->next = new ListNode(4);

    // ListNode* LN3 = new ListNode(2);
    // LN3->next = new ListNode(6);

    vector<ListNode*> inputVecLN {LN1,LN2};


    s.swapPairs(LN1);
    
    return 0;

}


