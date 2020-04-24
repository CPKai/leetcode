#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution23 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int index = 0;
        int thisRoundWinner = 0;
        ListNode* res;
        ListNode* header = new ListNode(0);
        res = header;

        while (true)
        {   
            // lists清空則跳出while
            if (lists.size() == 0)
            {
                break;
            }

            // lists[index]為NULL時清除該listNode*，扣除index後直接往下一圈
            if (lists[index] == NULL)
            {
                if (index == lists.size()-1)
                {
                    // 若index為最後一個，則砍完listnode後直接除置index
                    lists.erase(lists.begin()+index);
                    index = 0;
                    continue;
                }
                else
                {   
                    // 若非最後一個，砍完listnode後進入下一輪(因砍完node後，後排的會向前遞補，故index維持原值)
                    lists.erase(lists.begin()+index);
                    continue;
                }
            }
            
            
            // lists[index]值 < res->next值則置換，並記錄當前winner index
            if (res->next == NULL || res->next->val > lists[index]->val)
            {
                res->next = lists[index];
                thisRoundWinner = index;
            }
            // 當index達到盡頭，res向前移，winner也向前移，index重置
            if (index == lists.size()-1)
            {
                res = res->next;
                lists[thisRoundWinner] = lists[thisRoundWinner]->next;
                index = -1;
            }
            
            index++;
        }
        
        res = header->next;

        return res;
    }
};