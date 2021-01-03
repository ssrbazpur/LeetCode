//Very Hard

//Time:O(N^3)

/*
0    0    0    0    0    0
0    3    30   159  167  0
0    0    15   135  159  0
0    0    0    40   48   0
0    0    0    0    40   0
0    0    0    0    0    0

*/
class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));

        for (int len = 1; len <= n; ++len)
            for (int left = 1; left <= n - len + 1; ++left)
            {
                int right = left + len - 1;
                for (int k = left; k <= right; ++k)
                    dp[left][right] = max(dp[left][right], nums[left - 1] * nums[k] * nums[right + 1] + dp[left][k - 1] + dp[k + 1][right]);
            }
        return dp[1][n];
    }
};

// class Solution {
// public:
//     vector<vector<int>> memo;
//     int dp(vector<int>& nums,int left, int right)
//     {
// 	    if(left<0||right>=nums.size()||left>right)
// 		    return 0;
// 	    if(memo[left][right]!=-1)
// 		return memo[left][right];
//         int q=INT_MIN;
//         for(int i=left;i<=right;++i)
//         {
//             cout<<left<<" "<<right<<" ";
//             int lval=left-1<0?1:nums[left-1];
//             int rval=right+1>=nums.size()?1:nums[right+1];
//             cout<<lval<<" "<<rval<<endl;
//             q=max(q,nums[i]*lval*rval+dp(nums,left,i-1)+dp(nums,i+1,right));
//             cout<<q<<endl;
//         }
//         memo[left][right]=q;
// 	    return q;
//     }
//     int maxCoins(vector<int>& nums)
//     {
//         memo.resize(nums.size(),vector<int>(nums.size(),-1));
//         return dp(nums,0,nums.size()-1);
//     }
// };