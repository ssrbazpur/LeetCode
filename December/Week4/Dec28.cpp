class Solution
{
public:
    /*
    Hard Logic:
    1. 1+2+3+4....steps = n(n+1)/2 > target
       sum > target
    2. delta=(sum-target)%2
    3. If delta==0 then steps is the answer
    4. Else check steps%2==0 then steps + 1 else steps + 2.

    */
    int reachNumber(int target)
    {

        int sum = 0;
        int steps = 0;
        target = abs(target);
        while (sum < target)
        {
            steps++;
            sum += steps;
        }
        int delta = sum - target;
        return (sum - target) % 2 == 0 ? steps : steps + 1 + steps % 2;
    }
};