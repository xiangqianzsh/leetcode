# 总结
## 数组中几种常见的解法
1. Brute Force
2. Using Sorting
3. Using Map
4. Using Extra Array
    如英文字母类, 总共26个, 一般可以此解法
5. Using Constant Space
6. Using XOR
    这类一般比较特殊

## 重点示例, :
可以使用sort/map/Using Extra Array/Using Constant Space/XOR ( ??? 后两个没仔细看, 还没看太明白)
https://leetcode.com/problems/set-mismatch/solution/
sort/map
https://leetcode.com/problems/two-sum


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


# 有问题的

220. Contains Duplicate III
有overflow问题, 无法提交成功
```cpp

// 此答案时间O(1), 空间O(1)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        for (int i = 0; i < nums.size(); ++i) {
            int value = nums[i];
            for (int j = 1; j <= k; ++j) {
                int pos = i + j;
                if (pos >= nums.size()) {
                    break;
                }
                int new_value = nums[pos];
                if (abs(new_value - value) <= t) {
                    return true;
                }
            }
        }
        return false;
    }
};
```


56. Merge Intervals
解法无法提交成功
```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        if (intervals.size() == 0) {
            return ret;
        }

        struct Comp {
            bool operator() (const vector<int> & lhs, const vector<int> & rhs) {
                return lhs[0] <= rhs[0];
            }
        };

        std::sort(intervals.begin(), intervals.end(), Comp());

        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            int this_start = intervals[i][0];
            int this_end = intervals[i][1];
            if (this_start > end) {  // 无交集
//                [    ]
//                        [    ]
                ret.push_back({start, end});
                start = this_start;
                end = this_end;
            } else if (this_start <= end) {
                if (this_end <= end) {  // 是上一个的子集
//                    [         ]
//                       [   ]
                } else {  // 重叠部分
//                    [         ]
//                          [             ]
                    end = this_end;
                }
            }
        }
        ret.push_back({start, end});
        return ret;
    }
};

```

