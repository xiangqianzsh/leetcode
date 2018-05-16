617 
Merge Two Binary Trees    

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // use new
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) {
            return NULL;
        }

        int t1_val = 0, t2_val = 0;
        TreeNode *t1_left = NULL, *t1_right = NULL, *t2_left = NULL, *t2_right = NULL;
        if (t1 != NULL) {
            t1_val = t1->val;
            t1_left = t1->left;
            t1_right = t1->right;
        }
        
        if (t2 != NULL) {
            t2_val = t2->val;
            t2_left = t2->left;
            t2_right = t2->right;
        }
        
        TreeNode * retPtr = new TreeNode(t1_val + t2_val);
        retPtr->left = mergeTrees(t1_left, t2_left);
        retPtr->right = mergeTrees(t1_right, t2_right);
        return retPtr;
    }
};



// not new
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL) {
            return t2;
        }
        if (t2 == NULL) {
            return t1;
        }
        // t1 != NULL && t2 != NULL
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};




https://leetcode.com/problems/merge-two-binary-trees/discuss/104298/C++-O(n)-space-iterative-solution-no-new-tree!

https://leetcode.com/problems/merge-two-binary-trees/discuss/121777/Getting-runtime-error-C++

https://leetcode.com/problems/merge-two-binary-trees/discuss/104429/Python-BFS-Solution
ßßß