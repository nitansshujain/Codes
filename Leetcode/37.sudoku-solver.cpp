class Solution
{
public:
    int row[9][10], col[9][10], cube[3][3][10];
    void solveSudoku(vector<vector<char>> &board)
    {
        // Approach 1
        // solve1(board, 0, 0);

        // Approach 2 - optimised
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(cube, 0, sizeof(col));

        // hash the already existing cell values
        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                if (board[r][c] != '.')
                {
                    int d = board[r][c] - '0';
                    row[r][d] = 1;
                    col[c][d] = 1;
                    cube[r / 3][c / 3][d] = 1;
                }
            }
        }

        solve2(board, 0, 0);
    }

    bool check(vector<vector<char>> &board, int i, int j, char val)
    {
        int row = i - i % 3, column = j - j % 3;
        for (int x = 0; x < 9; x++)
            if (board[x][j] == val)
                return false;
        for (int y = 0; y < 9; y++)
            if (board[i][y] == val)
                return false;
        for (int x = 0; x < 3; x++)
            for (int y = 0; y < 3; y++)
                if (board[row + x][column + y] == val)
                    return false;
        return true;
    }
    bool solve1(vector<vector<char>> &board, int i, int j)
    {
        if (i == 9)
            return true;
        if (j == 9)
            return solve1(board, i + 1, 0);
        if (board[i][j] != '.')
            return solve1(board, i, j + 1);

        for (char d = '1'; d <= '9'; d++)
        {
            if (check(board, i, j, d))
            {
                board[i][j] = d;
                if (solve1(board, i, j + 1))
                    return true;
                board[i][j] = '.';
            }
        }

        return false;
    }

    bool solve2(vector<vector<char>> &board, int i, int j)
    {
        if (i == 9)
            return true;
        if (j == 9)
            return solve2(board, i + 1, 0);
        if (board[i][j] != '.')
            return solve2(board, i, j + 1);

        // filling board row by row
        for (char d = '1'; d <= '9'; d++)
        {
            if (is_possible(board, i, j, d))
            {
                board[i][j] = d;
                row[i][d - '0'] = 1;
                col[j][d - '0'] = 1;
                cube[i / 3][j / 3][d - '0'] = 1; // hash the digit 'd'

                if (solve2(board, i, j + 1))
                    return true;

                board[i][j] = '.';
                row[i][d - '0'] = 0;
                col[j][d - '0'] = 0;
                cube[i / 3][j / 3][d - '0'] = 0; // unhash the digit 'd'
            }
        }

        return false;
    }

    bool is_possible(vector<vector<char>> &board, int r, int c, char val)
    {
        if (row[r][val - '0'] == 1)
            return false;
        if (col[c][val - '0'] == 1)
            return false;
        if (cube[r / 3][c / 3][val - '0'] == 1)
            return false;
        return true;
    }
};