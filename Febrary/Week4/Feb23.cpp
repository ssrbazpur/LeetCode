class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        if (matrix.size() == 0)
        {
            return false;
        }

        int col = matrix[0].size() - 1;
        int row = 0;

        while (row <= matrix.size() - 1 && col >= 0)
        {
            cout << matrix[row][col] << endl;
            if (matrix[row][col] == target)
            {
                return true;
            }
            else if (matrix[row][col] < target)
            {
                row++;
            }
            else
            {
                col--;
            }
        }

        return false;
    }
};