#include <string>
#include <array>
#include <iostream>
#include <vector>
#include "leetcode_45.cpp"
using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };


int main(){
    Solution45 s;
    
    std::string input_str = "adceb";
    std::string input_str2 = "*a*b";
    int input_int = 0;
    vector<int> input_vector{1,2,1,1,1};
    // vector<string> inputS_vector{"foo","bar"};
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
    
    // ListNode* LN1 = new ListNode(1);
    // LN1->next = new ListNode(2);
    // LN1->next->next = new ListNode(3);
    // LN1->next->next->next = new ListNode(4);
    // LN1->next->next->next->next = new ListNode(5);

    // ListNode* LN2 = new ListNode(0);
    // // LN2->next = new ListNode(3);
    // // LN2->next->next = new ListNode(4);

    // // ListNode* LN3 = new ListNode(2);
    // // LN3->next = new ListNode(6);

    // vector<ListNode*> inputVecLN {LN1,LN2};

    // vector<vector<char>> inputVecChar{{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    s.jump(input_vector);
    
    return 0;

}


// [
//     ["5","3",".",".","7",".",".",".","."],
//     ["6",".",".","1","9","5",".",".","."],
//     [".","9","8",".",".",".",".","6","."],
//     ["8",".",".",".","6",".",".",".","3"],
//     ["4",".",".","8",".","3",".",".","1"],
//     ["7",".",".",".","2",".",".",".","6"],
//     [".","6",".",".",".",".","2","8","."],
//     [".",".",".","4","1","9",".",".","5"],
//     [".",".",".",".","8",".",".","7","9"]
// ]
// [
//     ["8","3",".",".","7",".",".",".","."],
//     ["6",".",".","1","9","5",".",".","."],
//     [".","9","8",".",".",".",".","6","."],
//     ["8",".",".",".","6",".",".",".","3"],
//     ["4",".",".","8",".","3",".",".","1"],
//     ["7",".",".",".","2",".",".",".","6"],
//     [".","6",".",".",".",".","2","8","."],
//     [".",".",".","4","1","9",".",".","5"],
//     [".",".",".",".","8",".",".","7","9"]
// ]