//TC:O(N) SC: O(n)
/*
Conceptual Overview:
1. Iterate through the array and Store the freq of the elements in map.
2. Iterate through map and get (freq of the element + freq of element + 1) if present. 
*/

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {

        unordered_map<int, int> freq;
        for (int n : nums)
        {
            freq[n]++;
        }

        int ans = 0;
        for (auto it : freq)
        {

            int element = it.first;
            int second = element + 1;
            int temp = 0;
            if (freq.find(second) != freq.end())
            {
                temp = it.second + freq[second];
                ans = max(ans, temp);
            }
        }

        return ans;
    }
};