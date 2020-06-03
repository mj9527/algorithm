//
// Created by mjzheng on 2020/5/27.
//

#ifndef ALGORITHM_PARTITIONLIST_H
#define ALGORITHM_PARTITIONLIST_H


//给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
//
//你应当保留两个分区中每个节点的初始相对位置。
//
//示例:
//
//输入: head = 1->4->3->2->5->2, x = 3
//输出: 1->2->2->4->3->5

//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
//// [1, 1] 2
//
//class PartitionList {
//    ListNode* partition(ListNode* head, int x) {
//        if (head == NULL || head->next == NULL) {
//            return head;
//        }
//        ListNode* p1 = NULL;
//        ListNode* p2 = NULL;
//        ListNode* head1 = NULL;
//        ListNode* head2 = NULL;
//        ListNode *p = head;
//        while (p != NULL) {
//            if (p->val < x) {
//                if (p1 == NULL) {
//                    p1 = p;
//                    head1 = p1;
//                } else {
//                    p1->next = p;
//                    p1 = p;
//                }
//            } else {
//                if (p2 == NULL) {
//                    p2 = p;
//                    head2 = p2;
//                } else {
//                    p2->next = p;
//                    p2 = p;
//                }
//            }
//            p = p->next;
//        }
//        p1->next = head2;
//        p2->next = NULL;
//        return head1;
//
////        ListNode* pLastMin = NULL;
////        ListNode* pre = NULL;
////        ListNode* p = head;
////        ListNode* suf = NULL;
////        while (p != NULL) {
////            if (p->val < x) {
////                suf = p->next;
////                if (pre != NULL) {
////                    pre->next = p->next; // delete p
////                }
////                if (pLastMin != NULL) {
////                    if (p != pLastMin->next) {
////                        p->next = pLastMin->next;
////                        pLastMin->next = p;
////                    }
////                } else {
////                    if (head != p) {
////                        p->next = head;
////                        head = p;
////                    }
////                }
////                pLastMin = p;
////                p = suf;
////            } else {
////                pre = p;
////                p = p->next;
////            }
////        }
////        return head;
//    }
//
//
//};


#endif //ALGORITHM_PARTITIONLIST_H
