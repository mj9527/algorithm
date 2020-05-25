//
// Created by mjzheng on 2020/5/25.
//

#ifndef ALGORITHM_CYCLIST_H
#define ALGORITHM_CYCLIST_H


class CycList {
    public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                break;
            }
        }
        if (fast == slow) {
            ListNode* p = head;
            while (p != slow) {
                p = p->next;
                slow = slow->next;
            }
            return p;
        } else {
            return NULL;
        }

    }
};


#endif //ALGORITHM_CYCLIST_H
