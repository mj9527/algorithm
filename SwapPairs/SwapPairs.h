//
// Created by mjzheng on 2021/3/2.
//

#ifndef ALGORITHM_SWAPPARIS_H
#define ALGORITHM_SWAPPARIS_H

namespace SwapPairs {
    /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
    class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            if (head == NULL || head->next == NULL) {
                return head;
            }

            ListNode* p = head;
            ListNode* q = head->next;
            p->next = swapPairs(q->next);
            q->next = p;
            return q;
        }
    };
}

#endif //ALGORITHM_SWAPPARIS_H
