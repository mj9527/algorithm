//
// Created by mjzheng on 2021/3/2.
//

#ifndef ALGORITHM_MERGEKLISTS_H
#define ALGORITHM_MERGEKLISTS_H

namespace MergeKLists {
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
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            if (lists.size() == 0) {
                return NULL;
            }

            mergeLists(lists, 0, lists.size());

            return lists[0];
        }

        // 不包括r
        void mergeLists(vector<ListNode*>& lists, int l, int r) {
            if (r-l<2) {
                return;
            }
            int m = (l+r)/2;
            mergeLists(lists, l, m);
            mergeLists(lists, m, r);
            lists[l]=mergeTwoLists(lists[l],lists[m]);
        }

        ListNode* mergeTwoLists(ListNode* p1, ListNode* p2) {
            if (p1 == NULL) {
                return p2;
            }
            if (p2 == NULL) {
                return p1;
            }
            ListNode* head = NULL;
            ListNode* p3 = NULL;
            ListNode* pre = NULL;
            while (p1!=NULL && p2!=NULL) {
                if (p1->val < p2->val) {
                    p3 = p1;
                    p1 = p1->next;
                } else {
                    p3 = p2;
                    p2 = p2->next;
                }
                if (head == NULL) {
                    head = p3;
                    pre = p3;
                } else {
                    pre->next = p3;
                    pre = pre->next;
                }
            }

            if (p1!=NULL) {
                pre->next = p1;
            }

            if (p2!=NULL) {
                pre->next = p2;
            }
            return head;
        }
    };
}

#endif //ALGORITHM_MERGEKLISTS_H
