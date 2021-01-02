/*

Concept
1. if(n%i==0) then Two Factor : n and n/i
2. Iterate till i=1 to i<sqrt(n) then from i=sqrt(n) to i>=1.

Time Complexity:O(sqrt(n))
Space : O(1)
*/
class Solution
{
public:
    int kthFactor(int n, int k)
    {

        for (int i = 1; i < sqrt(n); i++)
        {
            if (n % i == 0)
            {
                k--;
                if (k == 0)
                    return i;
            }
        }

        for (int i = sqrt(n); i >= 1; i--)
        {
            if (n % i == 0)
            {
                k--;
                if (k == 0)
                {
                    return n / i;
                }
            }
        }

        return -1;

        //         int track=0;

        //         for(int i=1;i<=n;i++){
        //             if(n%i!=0) continue;
        //             track++;
        //             if(track==k) return i;
        //         }

        //         return -1;
    }
};

/*
Two Factor: d and n/d.
    int d = 1;
    //Check till sqrt(n)
    for (; d * d <= n; ++d)
        if (n % d == 0 && --k == 0)
            return d;
    
    for (d = d - 1; d >= 1; --d) {
        //Elimate square because this is already covered.
        if (d * d == n)
            continue;
        if (n % d == 0 && --k == 0)
            return n / d;
    }
    return -1;
*/