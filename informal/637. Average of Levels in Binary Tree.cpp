637. Average of Levels in Binary Tree


class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        if (root == NULL) {
            return ret;
        }
        typedef std::pair<TreeNode*, int> pair_t;  // <node, floor>
        deque<pair_t> queue;
        queue.push_back(std::make_pair(root, 1));
        int pre_floor = -1;
        double pre_sum = 0;
        int pre_count = 0;
        while (!queue.empty()) {
            pair_t data = queue.front();
            queue.pop_front();
            if (data.second != pre_floor) {
                if (pre_floor >= 1) {  // 首次时 pre_floor = -1 时, 不会产生结果.
                    ret.push_back(pre_sum / pre_count);
                }
                pre_floor = data.second;
                pre_sum = data.first->val;
                pre_count = 1;
            } else {
                pre_sum += data.first->val;
                pre_count += 1;
            }

            if (data.first->left != NULL) {
                queue.push_back(std::make_pair(data.first->left, data.second + 1));
            }

            if (data.first->right != NULL) {
                queue.push_back(std::make_pair(data.first->right, data.second + 1));
            }
        }

        ret.push_back(pre_sum / pre_count);
        return ret;
    }

};
