#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "../common/utils.h"

// compile: g++ ans114.cpp ../common/utils.cpp  -std=c++14

using namespace std;

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        
        flatten(root->left);
        flatten(root->right);
        if (root->left != NULL) {
            TreeNode * left_bottom_right_ptr = getBottomRight(root->left);
            TreeNode * right_bak = root->right;
            root->right = root->left;
            root->left = NULL;
            left_bottom_right_ptr->right = right_bak;
        }
    }
    
    TreeNode * getBottomRight(TreeNode * root) {  // root is not null
        while (root->right != NULL) {
            root = root->right;
        }
        return root;
    }
};

TreeNode * create114Tree() {
    TreeNode * t1 = new TreeNode(1);
    TreeNode * t2 = new TreeNode(2);
    TreeNode * t3 = new TreeNode(3);
    TreeNode * t4 = new TreeNode(4);
    TreeNode * t5 = new TreeNode(5);
    TreeNode * t6 = new TreeNode(6);

    t2->left = t3;
    t2->right = t4;
    t5->right = t6;
    t1->left = t2;
    t1->right = t5;

    return t1;
}


int main()
{
    TreeNode * root = create114Tree();
    std::cout << tree2str(root) << std::endl;

    Solution solution;
    solution.flatten(root);
    std::cout << tree2str(root) << std::endl;

    deleteTree(root);
    return 0;
}

// g++ ans114.cpp utils.cpp -std=c++14
