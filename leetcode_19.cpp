#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution19 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* res = head;
        int length = 0 ;
        while (head != NULL)
        {
            length++;
            head = head->next;
        }
        
        int target = length - n + 1;
        int index = 1;
        head = res;

        if (target == 1)
        {
            res = res->next;
            return res;
        }
        
        
        ListNode* preserveNode;
        while (index < target)
        {
            preserveNode = head;
            if (index + 1 == target)
            {
                head = head->next;
                preserveNode->next = head->next;
                break;
            }
            head = head->next;
            index++;
        }
        

        return res;
    }
};