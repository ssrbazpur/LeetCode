/*

[3,2,20,1,1,3], x = 10

range = TotalSum - x = 30-10 = 20

Prefix Sum
[3,5,25,26,27,30]


*/

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {

        //key:prefixSum and value:Index
        unordered_map<int, int> hm;

        int totalSum = 0;
        for (int x : nums)
        {
            totalSum += x;
        }

        int range = totalSum - x;

        hm.insert({0, -1});
        int trackPrefixSum = 0;
        int maxLengthInMiddle = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            trackPrefixSum += nums[i];
            hm[trackPrefixSum] = i;
            if (hm.find(trackPrefixSum - range) != hm.end())
            {
                maxLengthInMiddle = max(maxLengthInMiddle, i - hm[trackPrefixSum - range]);
            }
            // }else{
            //     hm.insert({trackPrefixSum,i});
            // }
        }

        return maxLengthInMiddle != -1 ? nums.size() - maxLengthInMiddle : maxLengthInMiddle;
    }
};