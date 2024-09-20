class Solution 
{
    bool isSafe(int garden, vector<int> &res, vector<vector<int>> &paths, int flower) 
    {
        for (const auto& path : paths) 
        {
            int adjGarden = (path[0] == garden + 1) ? path[1] - 1 : (path[1] == garden + 1) ? path[0] - 1 : -1;
            if (adjGarden != -1 && res[adjGarden] == flower) 
            {
                return false;
            }
        }
        return true;
    }
    
    bool choose(int garden, vector<int> &res, int m, int n, vector<vector<int>> &paths) {
        if (garden == n) 
        {
            return true;
        }
        
        for (int flower = 1; flower <= m; flower++) 
        {
            if (isSafe(garden, res, paths, flower)) 
            {
                res[garden] = flower;
                if (choose(garden + 1, res, m, n, paths)) 
                {
                    return true;
                }
                res[garden] = 0;
            }
        }
        
        return false;
    }

    public:
        vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) 
        {
            int m = 4;
            vector<int> res(n, 0);
            choose(0, res, m, n, paths);
            return res;
        }
};
