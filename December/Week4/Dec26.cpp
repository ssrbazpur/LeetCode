
class Solution
{
public:
    //track[i] - no of ways to decode i length string. = track[i-1]+ track[i-2]
    //Time:O(N) | Space:O(N)
    int numDecodings(string s)
    {

        vector<int> track(s.size() + 1);
        track[0] = 1;
        track[1] = (int(s[0] - '0') >= 1) ? 1 : 0;

        for (int i = 2; i <= track.size(); i++)
        {

            int oneDigit = (int)(s[i - 1] - '0');
            int secondDigit = stoi(s.substr(i - 2, 2));

            if (oneDigit >= 1)
            {
                track[i] += track[i - 1];
            }
            if (secondDigit >= 10 && secondDigit <= 26)
            {
                track[i] += track[i - 2];
            }
        }

        return track[track.size() - 1];
    }
};