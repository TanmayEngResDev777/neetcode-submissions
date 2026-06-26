class Solution {
private:
    int ROWS, COLS;
    void dfs(int r, int c, vector<vector<bool>>& reachable, int prev_height, vector<vector<int>>& heights) {
        if(r < 0 || c < 0 || r >= ROWS || c >= COLS || reachable[r][c] || heights[r][c] < prev_height) {
            return;
        }

        reachable[r][c] = true;

        dfs(r + 1, c, reachable, heights[r][c], heights);
        dfs(r, c + 1, reachable, heights[r][c], heights);
        dfs(r - 1, c, reachable, heights[r][c], heights);
        dfs(r, c - 1, reachable, heights[r][c], heights);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty() || heights[0].empty()) return {};
        ROWS = heights.size();
        COLS = heights[0].size();

        vector<vector<bool>> pacific_reachable(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atlantic_reachable(ROWS, vector<bool>(COLS, false));

        for(int c = 0; c < COLS; ++c) {
            //Pacific
            dfs(0, c, pacific_reachable, heights[0][c], heights);

            //Atlantic
            dfs(ROWS - 1, c, atlantic_reachable, heights[ROWS - 1][c], heights);
        }

        for(int r = 0; r < ROWS; ++r) {
            //Pacific
            dfs(r, 0, pacific_reachable, heights[r][0], heights);

            //Atlantic
            dfs(r, COLS - 1, atlantic_reachable, heights[r][COLS - 1], heights);
        }

        vector<vector<int>> result;
        for(int r = 0; r < ROWS; ++r) {
            for(int c = 0; c < COLS; ++c) {
                if(pacific_reachable[r][c] && atlantic_reachable[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;

    }
};
