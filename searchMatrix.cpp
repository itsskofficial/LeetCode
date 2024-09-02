class Solution 
{
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) 
        {
            int m = matrix.size();
            int n = matrix[0].size();
            int low = 0;
            int high = m * n - 1;
            int mid;

            while (low <= high)
            {
                mid = (low + high) / 2;
                int i = mid / n;
                int j = mid % n;

                if (matrix[i][j] == target) 
                    return true;
                else if (matrix[i][j] < target)
                    low = mid + 1;
                else 
                    high = mid - 1;
            }

            return false;
        }
};