# 这个的解法有些不太好. https://leetcode.com/problems/matrix-cells-in-distance-order/submissions/
```cpp
// 相差0: (x相差0, y相差0)
// 相差1: (x相差0, y相差1), (x相差1, y相差0)
// 相差2: (x相差0, y相差2), (x相差1, y相差1), (x相差2, y相差0)
// 相差n: 

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> rets;
        int max_abs_delta_x = max(r0, R - 1 - r0);
        int max_abs_delta_y = max(c0, C - 1 - c0);
        int max_distance = max_abs_delta_x + max_abs_delta_y;
        for (int distance = 0; distance <= max_distance; distance++) {
            for (int abs_delta_x = 0; abs_delta_x <= distance; abs_delta_x++) {
                int abs_delta_y = distance - abs_delta_x;       
                if (abs_delta_x == 0 && abs_delta_y == 0) {
                    push_cell_if_valid(R, C, rets, r0 - abs_delta_x, c0 - abs_delta_y);
                } else if (abs_delta_x == 0 && abs_delta_y != 0) {
                    push_cell_if_valid(R, C, rets, r0 - abs_delta_x, c0 - abs_delta_y);
                    push_cell_if_valid(R, C, rets, r0 - abs_delta_x, c0 + abs_delta_y);
                } else if (abs_delta_x != 0 && abs_delta_y == 0) {
                    push_cell_if_valid(R, C, rets, r0 - abs_delta_x, c0 - abs_delta_y);
                    push_cell_if_valid(R, C, rets, r0 + abs_delta_x, c0 - abs_delta_y);
                } else {
                    push_cell_if_valid(R, C, rets, r0 - abs_delta_x, c0 - abs_delta_y);
                    push_cell_if_valid(R, C, rets, r0 + abs_delta_x, c0 - abs_delta_y);
                    push_cell_if_valid(R, C, rets, r0 - abs_delta_x, c0 + abs_delta_y);
                    push_cell_if_valid(R, C, rets, r0 + abs_delta_x, c0 + abs_delta_y);
                }
                
            }
            
        }
        return rets;
    }
    
    
    void push_cell_if_valid(int R, int C, vector<vector<int>> & rets, int x, int y) {
        if (0 <= x && x < R && 0 <= y && y < C) {
            rets.push_back({x, y});
        }
    }
};
```


# 这里考虑了顺序, 其它的好像并没有这样https://leetcode.com/problems/remove-outermost-parentheses/submissions/
```cpp
// 别人的更简单, 好像没有考虑顺序的问题.
// https://leetcode.com/problems/remove-outermost-parentheses/discuss/331159/Javascript-Solution-using-stacks-90
// https://leetcode.com/problems/remove-outermost-parentheses/discuss/330496/Rust-solution-0ms-beats-100


class Node {
public:
    char ch;
    int idx;
    Node(char ch_, int idx_): ch(ch_), idx(idx_) {}
};

class Solution {
public:
    string removeOuterParentheses(string S) {
        std::vector<int> rets_idx;
        stack<Node> mystack;
        for (int i = 0; i < S.size(); ++i) {
            char ch = S[i];
            if (ch == ')' && mystack.top().ch == '(') {
                rets_idx.push_back(i);
                rets_idx.push_back(mystack.top().idx);
                mystack.pop();
                if (mystack.empty()) {
                    rets_idx.resize(rets_idx.size() - 2);
                }
            } else {
                mystack.push(Node(ch, i));
            }
        }
    
        sort(rets_idx.begin(), rets_idx.end());
        string ret;
        for (int idx : rets_idx) {
            ret += S[idx];
        }
        return ret;
    }
};
```

