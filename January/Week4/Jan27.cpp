/*
0-0 size=1
1-1 size=1
2-10 size=2
3-11 size=3
4-100 size=4
5-101 size=5

*/

//Time:O(n) | Space:O(1)
class Solution
{
public:
    int concatenatedBinary(int n)
    {

        int size = 0;
        long long res = 0;
        int mod = 1e9 + 7;

        for (int i = 1; i <= n; i++)
        {
            //Get Last set Bit
            if ((i & (i - 1)) == 0)
                size++;
            res = (res << size | i) % mod;
        }
        return res;
    }
};