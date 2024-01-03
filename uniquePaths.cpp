class Solution 
{
    public:
        int uniquePaths(int m, int n) 
        {
            vector<int> oldRow(n, 1);
            for (int i = 0; i < m - 1; i++)
            {
                vector<int> newRow(n, 1);
                
                for (int j = n - 2; j > -1; j--)
                {
                    newRow[j] = newRow[j + 1] + oldRow[j];
                }

                oldRow = newRow;
            }

            return oldRow[0];
        }
};