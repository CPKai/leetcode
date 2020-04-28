#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution25 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=0, i=0;
        ListNode *prev, *Curr, *curr, *next, *Prev=NULL, *ans=NULL;
        Curr=head;
        
        // 取得ListNode長度
        while(Curr){
            len++;
            Curr=Curr->next;
        }

        // k>len or k==1直接回傳head
        if(k>len || k==1)
        {
            return head;
        }
            

        // 重置Curr
        Curr=head;
        
        // 迴圈處理各個group (殘group未在處理範圍)
        while(Curr && i<len/k){
            
            // 初始化count，用於group內的處理
            int cnt=0;

            // 建立小prev用來group內處理
            prev=NULL;
            
            // 建立小curr用來group內處理
            curr=Curr;
            
            // group內處理
            while(cnt<k){
                // 為next賦值
                next=curr->next;
                
                // 改變小curr的指向
                curr->next=prev;
                
                // 將prev與小curr向右移一node  (將原始node看成是由左向右排列的話)
                prev=curr;
                curr=next;
                
                cnt++;
            }

            // 當大prev不為null時，大prev-next賦與小prev
            if(Prev)
            {
                Prev->next=prev;
            }
            
            // 當ans為null時，ans賦與小prev，僅第一圈會執行到，確立答案的第一個node
            if(!ans)
            {
                ans=prev;
            }
            

            // 為下一group準備的賦值
            // 大prev賦與大Curr
            Prev=Curr;
            // 大Curr賦與next
            Curr=next;

            // 計算group數
            i++;
        }

        // 計算是否有殘group
        if(len%k)
        {
            // 有殘group則將大prev指向next(為殘group第一node)
            Prev->next=next;
        }
           
        return ans;
    }
};