class Solution {
public:
    int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int numIslands(vector<vector<char>>& grid)
    {
        int ROWS = grid.size(), COLS = grid[0].size();
        int islands = 0;
        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                if(grid[r][c] == '1')
                {
                    bfs(grid, r, c);
                    islands++;
                }
            }
        }
        return islands;
    }

    void bfs(vector<vector<char>>& grid, int r, int c)
    {
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = '0';

        while(!q.empty())
        {
            auto p = q.front(); q.pop();
            int row = p.first, col = p.second;
            for(int i = 0; i < 4; i++)
            {
                int nr = row + direction[i][0]; 
                int nc = col + direction[i][1];
                if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == '1')
                {
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
};
