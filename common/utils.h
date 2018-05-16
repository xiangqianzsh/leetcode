#include <iostream>
#include <vector>
#include <map>
#include <set>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 按层遍历
std::string tree2str(TreeNode * root);
void deleteTree(TreeNode * root);