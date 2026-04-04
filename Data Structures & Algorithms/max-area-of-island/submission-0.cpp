class Solution {
public:
    int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int maxArea = 0;
        queue<pair<int, int>> q;
        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                int area =0;
                if(grid[r][c] == 1)
                {
                    q.push({r, c});
                    grid[r][c] = 0;
                    area ++;
                    while(!q.empty())
                    {
                        auto p = q.front(); q.pop();
                        int row = p.first, col = p.second;
                        for(int i = 0; i < 4; i++)
                        {
                            int nr = row + direction[i][0], nc = col + direction[i][1];
                            if(nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && grid[nr][nc] == 1)
                            {
                                q.push({nr, nc});
                                area++;
                                grid[nr][nc] = 0;
                            }
                        }
                    }
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};


