class Solution
{
public:
    /*
    Concept Ovierview:
    a e i o u
    1 1 1 1 1
    5 4 3 2 1     

    Starting with i: i + Total(ou)

    Formula: a[i][j]=a[i-1]+a[j+1]
    */
    //TC:O(N) sc:o(1)
    int countVowelStrings(int n)
    {

        vector<int> dp(5, 1);

        for (int i = 2; i <= n; i++)
        {

            for (int j = 3; j >= 0; j--)
            {
                dp[j] = dp[j] + dp[j + 1];
            }
        }

        int ans = 0;
        for (int a : dp)
        {
            ans += a;
        }

        return ans;
    }
};