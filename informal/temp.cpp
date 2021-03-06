# 每一次, 有问题
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> small_values;
        deque<TreeNode *> queue;
        queue.push_back(root);
        while (!queue.empty()) {
            TreeNode * data = queue.front();
            queue.pop_front();
            if (data != NULL && data->left != NULL && data->right != NULL) {
                queue.push_back(data->left);
                queue.push_back(data->right);
                small_values.push_back(data->val);
            }
        }

        if (small_values.size() < 2) {
            return -1;
        }

        int smaller = min(small_values[0], small_values[1]);
        int second_smaller = max(small_values[2], small_values[1]);
        for (unsigned int i = 3; i < small_values.size(); i++) {
            int value = small_values[i];

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


