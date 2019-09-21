671. Second Minimum Node In a Binary Tree
# 每一次, 有问题
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        set<int> values;
        deque<TreeNode *> queue;
        queue.push_back(root);
        while (!queue.empty()) {
            TreeNode * data = queue.front();
            queue.pop_front();
            if (data != NULL && data->left != NULL && data->right != NULL) {
                queue.push_back(data->left);
                queue.push_back(data->right);
                values.add(data->val);
            }
        }

        if (values.size() < 2) {
            return -1;
        }

        int smaller = INT_MAX;
        int second_smaller = INT_MAX;
        for (auto it = values.begin(); it != values.end(); ++it) {
            

            int value = values[i];
            if (value < second_smaller && value < smaller) {
                second_smaller = smaller;
                smaller = value;
            } else if (value < second_smaller && value >= smaller) {
                second_smaller = value;
            }
        }
        return second_smaller;
    }
};