//
// Created by mjzheng on 2021/2/24.
//

#ifndef ALGORITHM_MERGETWOLISTS_H
#define ALGORITHM_MERGETWOLISTS_H


namespace MergeTwoList {
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
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode* p1 = l1;
            ListNode* p2 = l2;
            ListNode* p3 = NULL;
            ListNode* l3 = NULL;
            while (p1 != NULL && p2 != NULL) {
                if (p1->val > p2->val) {
                    if (l3 ==NULL) {
                        l3 = p2;
                        p3 = l3;
                    } else {
                        p3->next = p2;
                        p3 = p3->next;
                    }
                    p2 = p2->next;
                } else {
                    if (l3 == NULL) {
                        l3 = p1;
                        p3 = l3;
                    } else {
                        p3->next = p1;
                        p3 = p3->next;
                    }
                    p1=p1->next;
                }
            }
            if (p1 != NULL) {
                if (l3 == NULL) {
                    l3 = p1;
                } else {
                    p3->next = p1;
                }
            }

            if (p2 != NULL) {
                if (l3 == NULL) {
                    l3 = p2;
                } else {
                    p3->next = p2;
                }
            }
            return l3;

        }
    };
}

#endif //ALGORITHM_MERGETWOLISTS_H
