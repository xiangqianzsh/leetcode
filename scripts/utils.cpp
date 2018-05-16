#include "utils.h"
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <sstream> 

std::string tree2str(TreeNode * root) {
    std::stringstream ss;
    std::deque<TreeNode * > que;
    que.push_back(root);
    while (!que.empty()) {
        TreeNode * head = que.front();
        que.pop_front();
        if (head != NULL) {
            ss << std::to_string(head->val)  << ",";
            if (head->left != NULL || head->right != NULL) {
                que.push_back(head->left);
                que.push_back(head->right);
            }
        } else {
            ss << "NULL,";
        }
    }
    return ss.str();
}

void deleteTree(TreeNode * root) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        delete root;
        return;
    }

    if (root->left != NULL) {
        deleteTree(root->left);
    }

    if (root->right != NULL) {
        deleteTree(root->right);
    }
}