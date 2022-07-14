class Solution
{
public:
    bool is_possible(int row, int col, vector<string> &board)
    {

        for (int i = row - 1; i >= 0; i--)
        {
            if (board[i][col] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(int row, int n, vector<string> &board, vector<vector<string>> &res)
    {
        if (row == n)
        {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (is_possible(row, col, board))
            {
                board[row][col] = 'Q';
                solve(row + 1, n, board, res);
                board[row][col] = '.';
            }
        }

        return;
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;

        solve(0, n, board, res);

        return res;
    }
};