
#include <string>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution21 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res;
        ListNode* header = new ListNode(0);

        // header負責指向自建的頭node，res負責進while組織return 用的listnode
        res = header;
        
        // 當兩個listnode皆不為null時，持續進行while: 比較此圈l1 l2的val來決定res->next要指向l1或l2
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val)
            {
                res->next = l1;
                l1 = l1->next;
            }
            else
            {
                res->next = l2;
                l2 = l2->next;
            }

            res = res->next;
        }
        
        // 出while表示其中一個listnode為null，若l1為NULL，直接將res與l2剩餘node做掛接
        if (l1 == NULL)
        {
            res->next = l2;
        }
        else
        {
            res->next = l1;
        }

        // 組完return 用listnode後，重新將res指向頭1個node (header為自建node故忽略，從header->next開始)
        res = header->next;
        
        return res;
    }
};