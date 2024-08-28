class Solution {
public:
    vector<int> generateRow(int row)
    {
        int n = 1;
        vector<int> triangleRow;
        triangleRow.push_back(1);
        
        for (int col = 1; col < row; col++)
        {
            n = (n * (row - col)) / col;
            triangleRow.push_back(n);
        }

        return triangleRow;
    }

    vector<vector<int>> generate(int numRows) 
    {
        int n = 1;
        vector<vector<int>> triangle;

        for (int i = 1; i <= numRows; i++)
        {
            triangle.push_back(generateRow(i));
        }

        return triangle;
    }
};