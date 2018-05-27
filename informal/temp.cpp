
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        struct DataType {
            TreeNode * tree;
            string path;
            DataType(TreeNode * tree_, string path_): tree(tree_), path(path_) {}
        };
        
        std::deque<DataType> queue;
        queue.push_back(DataType(root, ""));
        while (!queue.empty()) {
            DataType data = queue.front();
            queue.pop_front();
            if (data.tree != NULL) {
                if (data.tree->left == NULL && data.tree->right == NULL) {
                    data.path += std::to_string(data.tree->val);
                    ret.push_back(data.path);
                } else {
                    data.path += std::to_string(data.tree->val) + "->";
                    queue.push_back(DataType(data.tree->left, data.path));
                    queue.push_back(DataType(data.tree->right, data.path)); 
                }
            }
        }
        return ret;
    }
};
