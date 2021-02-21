/*

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.


*/

class Solution
{
public:
    int romanToInt(string s)
    {

        int ans = 0;
        int i = 0;
        while (i < s.size())
        {
            // for(int i=0;i<s.size();i++){

            cout << ans << endl;
            if (i < s.size() - 1 && s[i] == 'I' && s[i + 1] == 'V')
            {
                ans += 4;
                i = i + 2;
                continue;
            }
            else if (i < s.size() - 1 && s[i] == 'I' && s[i + 1] == 'X')
            {
                ans += 9;
                i = i + 2;
                continue;
            }
            else if (i < s.size() - 1 && s[i] == 'X' && s[i + 1] == 'L')
            {
                ans += 40;
                i = i + 2;
                continue;
            }
            else if (i < s.size() - 1 && s[i] == 'X' && s[i + 1] == 'C')
            {
                ans += 90;
                i = i + 2;
                continue;
            }
            else if (i < s.size() - 1 && s[i] == 'C' && s[i + 1] == 'D')
            {
                ans += 400;
                i = i + 2;
                continue;
            }
            else if (i < s.size() - 1 && s[i] == 'C' && s[i + 1] == 'M')
            {
                ans += 900;
                i = i + 2;
                continue;
            }
            else if (s[i] == 'I')
            {
                ans += 1;
            }
            else if (s[i] == 'V')
            {
                ans += 5;
            }
            else if (s[i] == 'X')
            {
                ans += 10;
            }
            else if (s[i] == 'L')
            {
                ans += 50;
            }
            else if (s[i] == 'C')
            {
                ans += 100;
            }
            else if (s[i] == 'D')
            {
                ans += 500;
            }
            else if (s[i] == 'M')
            {
                ans += 1000;
            }

            i = i + 1;
        }

        return ans;
    }
};