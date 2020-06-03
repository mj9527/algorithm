//
// Created by mjzheng on 2020/5/29.
//

#ifndef ALGORITHM_BINARYSORTEDTREE_H
#define ALGORITHM_BINARYSORTEDTREE_H

#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* lchild;
    TreeNode* rchild;
    TreeNode(int value) {
        val = value;
        lchild = NULL;
        rchild = NULL;
    }
};

class BinarySortedTree {
public:
    // f 是T的双亲
    bool Search(TreeNode* t, int key, TreeNode* f, TreeNode** p) {
        if (t == NULL) {
            *p = f;
            return false;
        }
        if (key == t->val) {
            *p = t;
            return true;
        } else if (key > t->val) {
            return Search(t->rchild, key, t, p);
        } else if (key < t->val) {
            return Search(t->lchild, key, t, p);
        }
    }

    bool Insert(TreeNode** t, int val) {
        TreeNode* p = NULL;
        if (!Search(*t, val, NULL, &p)) {
            TreeNode* s = new TreeNode(val);
            if (p == NULL) {
                *t = s;
                //std::cout << "root" << std::endl;
            } else if (val < p->val) {
                p->lchild = s;
                //std::cout << "left" << std::endl;
            } else {
                p->rchild = s;
                //std::cout << "right" << std::endl;
            }
            return true;
        } else {
            return false; // 已经存在
        }
    }

    bool Delete(TreeNode*t, int val) {
        if (t == NULL) {
            return false;
        }
        if (t->val == val) {
            return DeleteNode(t);
        } else if (val < t->val) {
            return Delete(t->lchild, val);
        } else {
            return Delete(t->rchild, val);
        }
    }

    bool DeleteNode(TreeNode* t) {
        TreeNode* q = NULL;
        if (t->lchild == NULL) {
            q = t;
            *t = *t->rchild;
        } else if (t->rchild == NULL) {

        } else {

        }
        return false;
    }
};

//TreeNode** pos = NULL;
//if (f != NULL) {
//if (f->lchild == t) {
//pos = &f->lchild;
//} else {
//pos = &f->rchild;
//}
//}
//
//if (t->lchild == NULL && t->rchild == NULL) {
//// leaf node
//if (pos != NULL) {
//*pos = NULL;
//}
//delete t;
//} else if (t->lchild != NULL && t->rchild == NULL) {
//// 左子树不为空，右子树为空
//if (pos != NULL) {
//*pos = t->lchild;
//}
//delete t;
//} else if (t->lchild == NULL && t->rchild != NULL) {
//if (pos != NULL) {
//*pos = t->rchild;
//}
//delete t;
//} else {
//TreeNode* q = t;
//TreeNode* s = t->lchild;
//
//while (s->rchild != NULL) {
//q = s;
//s = s->rchild;
//}
//s->lchild = t->lchild;
//s->rchild = t->rchild;
//if (pos != NULL) {
//*pos = s;
//}
//
//q->rchild = s->lchild;
//}
//return false;

void MidSearch(TreeNode* t) {
    if (t == NULL) {
        return ;
    }
    MidSearch(t->lchild);
    std::cout << t->val << std::endl;
    MidSearch(t->rchild);
}


void TestSort() {
    BinarySortedTree tree;
    TreeNode* root = NULL;
    int nodes[] = {45, 24, 53, 45, 12, 24, 90};
    int count = sizeof(nodes) / sizeof(int );
    for (int i=0; i<count; i++) {
        tree.Insert(&root, nodes[i]);
    }

    TreeNode* p = NULL;
    tree.Search(root, 45, NULL, &p);
    if (p != NULL) {
        if (p->lchild != NULL) {
            std::cout << "left " << p->lchild->val << " ";
        }
        std::cout << "root " << p->val << " ";
        if (p->rchild != NULL) {
            std::cout << "right " << p->rchild->val << " ";
        }
        std::cout << std::endl;
    }

    MidSearch(root);

    tree.Delete(root, 45);

    MidSearch(root);

    //tree.Search(NULL, 10, NULL, NULL);
}

#endif //ALGORITHM_BINARYSORTEDTREE_H
