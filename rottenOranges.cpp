class Solution 
{
    public:
        int orangesRotting(vector<vector<int>>& grid) 
        {
            int n = grid.size();
            int m = grid[0].size();
            queue<pair<pair<int, int>, int>> q;
            int visited[n][m];
            int res = 0;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (grid[i][j] == 2)
                    {
                        q.push({{i, j}, 0});
                        visited[i][j] = 2;
                    }
                    else
                    {
                        visited[i][j] = 0;
                    }
                }
            }


            int drow[] = {-1, 0, +1, 0};
            int dcol[] = {0, +1, 0, -1};

            while (!q.empty())
            {
                int row = q.front().first.first;
                int col = q.front().first.second;
                int time = q.front().second;
                res = max(time, res);

                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
                    {
                        q.push({{nrow, ncol}, time + 1});
                        visited[nrow][ncol] = 2;
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (grid[i][j] == 1 && visited[i][j] != 2)
                    {
                        return -1;
                    }
                }
            }

            return res;
        }
};
