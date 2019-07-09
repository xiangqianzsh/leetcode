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