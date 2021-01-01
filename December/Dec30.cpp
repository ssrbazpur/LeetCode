
/*

If alive:
1. getLiveNeighbours() <2 then die
2. getLiveNeighbours() >3 then die
If died:
3. getLiveNeighbours() ==3 then live

Time:O(n*m)
Space:Inplace

*/

class Solution
{
private:
    vector<vector<int>> direc = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {0, -1}, {1, 0}, {1, 1}, {1, -1}};

public:
    int getLiveNeighbours(vector<vector<int>> &board, int row, int col)
    {

        int ans = 0;
        for (int i = 0; i < direc.size(); i++)
        {
            int rowNo = row + direc[i][0];
            int colNo = col + direc[i][1];

            if (rowNo >= 0 && rowNo <= board.size() - 1 && colNo >= 0 && colNo <= board[0].size() - 1)
            {
                if (board[rowNo][colNo] == 1 || board[rowNo][colNo] == -2)
                    ans++;
            }
        }
        return ans;
    }

    void gameOfLife(vector<vector<int>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == 1 && (getLiveNeighbours(board, i, j) < 2 || getLiveNeighbours(board, i, j) > 3))
                {
                    board[i][j] = -2;
                }
                else if (board[i][j] == 0 && getLiveNeighbours(board, i, j) == 3)
                {
                    board[i][j] = -1;
                }
            }
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == -2)
                {
                    board[i][j] = 0;
                }
                else if (board[i][j] == -1)
                {
                    board[i][j] = 1;
                }
            }
        }
    }
};