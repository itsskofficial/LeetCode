class Solution 
{
    public:
        int minPathSum(vector<vector<int>>& grid) 
        {
            int rows = grid.size();
            int cols = grid[0].size();
            vector<vector<int>> res(rows + 1, vector<int>(cols + 1, 9999));
            res[rows][cols - 1] = 0;

            for (int i = rows - 1; i > -1; i--)
            {
                for (int j = cols - 1; j > -1; j--)
                {
                    res[i][j] = grid[i][j] + min(res[i + 1][j], res[i][j + 1]);
                }
            }

            return res[0][0];
        }
};