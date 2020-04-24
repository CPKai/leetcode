#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution24 {
public:
    ListNode* swapPairs(ListNode* head) {

        // 處理head == NULL 與 head只有1個node的情況
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        
        ListNode* res = head->next;
        ListNode* temp = NULL;
        ListNode* temp2 = NULL;

        
        while(head->next != NULL)
        {
            // 第一圈temp為null不處理，第二圈開始上一圈完成排列後的第二node指向這一圈的第二node(當此圈走完會轉為第一node)
            if (temp != NULL)
            {
                // 此時temp仍為上一圈的值
                temp->next->next = head->next;
            }
            
            // 建立要使用的暫用node
            temp = head->next;
            temp2 = temp->next;
            //  1               2             3             4             NULL
            //  --------        ------        -------        ------- 
            // | header |  ->  | temp |  ->  | temp2 |  ->  |       | -> 
            //  --------        ------        -------        -------


            // 改始改變指向
            temp->next = head;
            head->next = temp2;
            head = temp2;
            //  2               1             3             4             NULL
            //  ------        ------        --------        ------- 
            // | temp |  ->  |      |  ->  | temp2  |  ->  |       |  -> 
            // |      |  ->  |      |  ->  | header |  ->  |       |  
            //  ------        ------        --------        -------


            // 確保下一圈的起始head != NULL
            if (head == NULL)
            {
                break;
            }
        }

        return res;
    }
};