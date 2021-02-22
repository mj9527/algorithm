//
// Created by mjzheng on 2021/2/22.
//

#ifndef ALGORITHM_ADDTWONUMBERS_H
#define ALGORITHM_ADDTWONUMBERS_H

namespace AddTwoNumbers {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* p1 = l1;
            ListNode* p2 = l2;
            ListNode* l3 = NULL;
            ListNode* p3 = NULL;
            int next = 0;
            int a = 0;
            int b = 0;

            while (p1 != NULL || p2 !=NULL) {
                if (p1 != NULL) {
                    a = p1->val;
                    p1 = p1->next;
                } else {
                    a = 0;
                }

                if (p2 != NULL) {
                    b = p2->val;
                    p2 = p2->next;
                } else {
                    b = 0;
                }

                int sum = a + b + next;
                next = sum / 10;
                if (l3 == NULL) {
                    l3 = new ListNode();
                    p3 = l3;
                } else {
                    p3->next = new ListNode();
                    p3 = p3->next;
                }
                p3->val = sum % 10;
            }
            if (next > 0) {
                p3->next = new ListNode();
                p3 = p3->next;
                p3->val = next;
            }

            return l3;
        }
    };

    void testAddTwoNumbers() {

    }
}

#endif //ALGORITHM_ADDTWONUMBERS_H
