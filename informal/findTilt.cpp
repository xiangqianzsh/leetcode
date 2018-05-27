# 每一次, 有问题
class Solution {
public:
    int findTilt(TreeNode* root) {
        int ret = 0;
        std::deque<TreeNode *> queue;
        queue.push_back(root);
        while (!queue.empty()) {
            TreeNode * data = queue.front();
            queue.pop_front();
            if (data != NULL) {
                int left = data->left == NULL ? 0 : data->left->val;
                int right = data->right == NULL ? 0 : data->right->val;
                int abs_diff = (left >= right) ? (left - right) : (right - left);
                ret += abs_diff;

                queue.push_back(data->left);
                queue.push_back(data->right);
            }
        }

        return ret;
    }
};


# 再一次, 计算量较大
class Solution {
public:
    int findTilt(TreeNode* root) {
        int ret = 0;
        std::deque<TreeNode *> queue;
        queue.push_back(root);
        while (!queue.empty()) {
            TreeNode * data = queue.front();
            queue.pop_front();
            if (data != NULL) {
                int left = sumTree(data->left);
                int right = sumTree(data->right);
                int abs_diff = (left >= right) ? (left - right) : (right - left);
                ret += abs_diff;
            }
        }

        return ret;
    }


    int sumTree(TreeNode* root) {
        int ret = 0;
        std::deque<TreeNode *> queue;
        queue.push_back(root);
        while (!queue.empty()) {
            TreeNode * data = queue.front();
            queue.pop_front();
            if (data != NULL) {
                ret += data->val;
            }
        }

        return ret;
    }
};



# 深度优先
struct NodeRet {
    int tree_sum;
    int tilt;
    int cum_tilt;
    NodeRet(int tree_sum_, int tilt_, int cum_tilt_): tree_sum(tree_sum_), tilt(tilt_), cum_tilt(cum_tilt_) {}
};

class Solution {
public:
    int findTilt(TreeNode* root) {
        NodeRet ret = helper(root);
        return ret.cum_tilt;
    }


    NodeRet helper(TreeNode * root) {
        if (root == NULL) {
            return NodeRet(0, 0, 0);
        }

        if (root->left == NULL && root->right == NULL) {
            return NodeRet(root->val, 0, 0);
        }

        NodeRet left = helper(root->left);
        NodeRet right = helper(root->right);
        int tree_sum = left.tree_sum + right.tree_sum + root->val;
        int tilt = std::abs(left.tree_sum - right.tree_sum)
        int cum_tilt = tilt + left.cum_tilt + right.cum_tilt;
        return NodeRet(tree_sum, tilt, cum_tilt);
    }
};

