114. Flatten Binary Tree to Linked List
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        
        flatten(root->left);
        flatten(root->right);
        if (root->left != NULL) {
            cout << "root->left " << root->left->val << std::endl;
            TreeNode * left_bottom_right_ptr = getBottomRigth(root->left);
            cout << "left_bottom_right_ptr " <<left_bottom_right_ptr->val << std::endl;
            TreeNode * right_bak = root->right;
            root->right = root->left;
            left_bottom_right_ptr->right = right_bak;
        }
    }
    
    TreeNode * getBottomRigth(TreeNode * root) {  // root is not null
        while (root->right != NULL) {
            root = root->right;
        }
        return root;
    }
};