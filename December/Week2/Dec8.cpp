/*
Conceptual Ovierview:

Time:O(n) | SPace:O(1)
*/

class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        vector<int> hm(60, 0);
        int ans = 0;
        for (int t : time)
        {
            if (t % 60 == 0)
            {
                ans += hm[0];
            }
            else
            {
                ans += hm[60 - t % 60];
            }
            hm[t % 60]++;
        }

        return ans;
    }
};