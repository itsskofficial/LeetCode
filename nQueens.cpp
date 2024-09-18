// class Solution 
// {
//     bool isSafe(int row, int col, vector<string> board, int n)
//     {
//         int dupRow = row, dupCol = col;

//         while (row >= 0 && col >= 0)
//         {
//             if (board[row][col] == "Q")
//             {
//                 return false;
//             }

//             row--;
//             col--;
//         }

//         row = dupRow;
//         col = dupCol;

//         while (col >= 0)
//         {
//             if (board[row][col] == "Q")
//             {
//                 return false;
//             }

//             col--;
//         }

//         row = dupRow;
//         col = dupCol;

//         while (row < n && col >= 0)
//         {
//             if (board[row][col] == "Q")
//             {
//                 return false;
//             }

//             row++;
//             col--;
//         }

//         return true;
//     }
//     void solve(int col, vector<string>& board, vector<vector<string>>& res, int n)
//     {
//         if (col == n)
//         {
//             res.push_back(board);
//             return res;
//         }

//         for (int row = 0; row < n; row++)
//         {
//             if (isSafe(row, col, board, n))
//             {
//                 board[row][col] = "Q";
//                 solve(col + 1, board, res, n);
//                 board[row][col] = "-";
//             }
//         }
//     }

//     public:
//         vector<vector<string>> solveNQueens(int n) 
//         {
//             vector<vector<string>> res;
//             vector<string> board(n);
//             string s(n, "-");

//             for (int i = 0; i < n; i++)
//             {
//                 board[i] = s;
//             }

//             solve(0, board, res, n);
//             return res;
//         }
// };

class Solution 
{
  public:
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, vector < int > & leftrow, vector < int > & upperDiagonal, vector < int > & lowerDiagonal, int n) 
    {
      if (col == n) 
      {
        ans.push_back(board);
        return;
      }

      for (int row = 0; row < n; row++) 
      {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
          board[row][col] = 'Q';
          leftrow[row] = 1;
          lowerDiagonal[row + col] = 1;
          upperDiagonal[n - 1 + col - row] = 1;
          solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
          board[row][col] = '.';
          leftrow[row] = 0;
          lowerDiagonal[row + col] = 0;
          upperDiagonal[n - 1 + col - row] = 0;
        }
      }
    }

  public:
    vector <vector<string>> solveNQueens(int n) 
    {
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');

      for (int i = 0; i < n; i++) 
      {
        board[i] = s;
      }

      vector < int > leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
      solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
      return ans;
    }
};
