#include <iostream>
#include <string>
// 
// 2. Add Two Numbers
// 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* resultListNode = NULL;
        ListNode** node = &resultListNode;

        // 建立計算tempSum，tempSum % 10為加總後的個位數。tempSum / 10為加總後的10位數(即進位)，會於下一輪while計算
        int tempSum = 0;

        // l1, l2, tempSum有1者不為0則仍有數需進行計算
        while (l1 != NULL || l2 != NULL || tempSum != 0)
        {
            if (l1 != NULL)
            {
                tempSum += l1->val;
                
                // 需在if內執行，否則可能出現 「l1已為NULL仍執行l1->next」而報出error
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                tempSum += l2->val;

                // 需在if內執行，理由同l1
                l2 = l2->next;
            }
            
            // 猜測
            // 呼叫var時，若content是「指向某address的pointer」，會自動取得該address的值
            // 而此處若用**會去改寫到某個content為NULL的位置(可能為不可寫區域)
            // 若不加**也不加*則是「指向某address的pointer」，取用address指向位置的內容，但該內容也為指向某處address的pointer，會造成=左右格式不符
            // 加*則往上返一層，content一樣為指向某address的pointer，但這時調整pointer指向new listnode
            *node = new ListNode(tempSum % 10);
            tempSum = tempSum / 10;
            
            node = &((*node)->next);
        }
        
        return resultListNode;
        
    }
};