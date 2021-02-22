class Solution
{
public:
    int brokenCalc(int X, int Y)
    {

        int step = 0;
        while (X != Y)
        {

            //Odd
            if (Y >= X && Y % 2 == 0)
            {
                int div = Y / 2;
                Y = div;
            }
            else
            {

                Y = Y + 1;
            }

            step++;
        }
        return step;
    }
};