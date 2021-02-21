/*
Conceptual Overview:

[1, 2, 3, 4]



*/

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &A)
    {

        int curr = 0;
        int prev = 0;
        int sum = 0;
        for (int i = 2; i < A.size(); i++)
        {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
            {
                curr = prev + 1;
                prev = curr;
                //dp[i]=dp[i-1]+1;
                sum += curr;
            }
            else
            {
                prev = 0;
            }
        }
        return sum;
    }

    //     int numberOfArithmeticSlices(vector<int>& A) {

    //         vector<int> dp(A.size(),0);
    //         int sum=0;
    //         for(int i=2;i<A.size();i++){
    //             if(A[i]-A[i-1]==A[i-1]-A[i-2]){
    //                 dp[i]=dp[i-1]+1;
    //                 sum+=dp[i];
    //             }

    //         }
    //         return sum;

    //     }
};