class Solution
{
public:
    //Time:O(N) | Space:O(N)
    vector<int> sortedSquares(vector<int> &A)
    {

        vector<int> res(A.size());

        int p = A.size() - 1;
        int front = 0;
        int last = A.size() - 1;

        while (front <= last)
        {
            if (abs(A[front]) > A[last])
            {
                res[p] = A[front] * A[front];
                front++;
            }
            else
            {
                res[p] = A[last] * A[last];
                last--;
            }
            p--;
        }

        //  vector<int> res(A.size());
        // int l = 0, r = A.size() - 1;
        // for (int k = A.size() - 1; k >= 0; k--) {
        //     if (abs(A[r]) > abs(A[l])) res[k] = A[r] * A[r--];
        //     else res[k] = A[l] * A[l++];
        // }
        return res;
    }
};