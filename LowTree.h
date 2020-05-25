//
// Created by mjzheng on 2020/5/22.
//

#ifndef ALGORITHM_LOWTREE_H
#define ALGORITHM_LOWTREE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
//        TreeNode* left = lowestCommonAncestor(root->left, p, q);
//        TreeNode* right = lowestCommonAncestor(root->right, p, q);
//        if (left == NULL && right == NULL) {
//            return root
//        }
    }
};



#endif //ALGORITHM_LOWTREE_H
