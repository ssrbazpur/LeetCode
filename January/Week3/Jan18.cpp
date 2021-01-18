/*

[3,1,3,4,3], k = 6
3,0
1,1
4,1


*/

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {

        unordered_map<int, int> hm;

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {

            int second = k - nums[i];

            if (hm.find(second) != hm.end())
            {
                if (hm[second] > 0)
                {
                    ans++;
                    hm[second]--;
                }
                else
                {
                    hm[nums[i]]++;
                }
            }
            else
            {
                hm[nums[i]]++;
                //hm.insert({nums[i],1});
            }
        }
        return ans;
    }
};