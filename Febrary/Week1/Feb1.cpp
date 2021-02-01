class Solution
{
public:
    //Time:O(1) as N is 32 bits | Space:O(1)
    int hammingWeight(uint32_t n)
    {
        int ans = 0;
        while (n)
        {
            int lastBit = n & 1;
            ans = ans + lastBit;
            n = n >> 1;
        }
        return ans;
    }
};