class Solution {
void sinkIsland(vector<vector<char>>& grid, int r, int c) {
    int rows = grid.size();
    int cols = grid[0].size();

    if(r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0') {
        return;
    }

    grid[r][c] = '0';

    sinkIsland(grid, r + 1, c);
    sinkIsland(grid, r, c + 1);
    sinkIsland(grid, r - 1, c);
    sinkIsland(grid, r, c - 1);
}

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int islandCount = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c] == '1') {
                    islandCount++;
                    sinkIsland(grid, r, c);
                }
            }
        }

        return islandCount;
    }
};
