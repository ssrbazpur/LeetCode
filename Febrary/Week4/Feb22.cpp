class Solution
{
public:
    bool isPossible(string s, string d)
    {

        if (d.size() > s.size())
            return false;

        int p1 = 0;
        int p2 = 0;

        //"abpcplea", d = ["ale","apple","monkey","plea"]

        while (p2 < d.size() && p1 < s.size())
        {
            if (d[p2] == s[p1])
            {
                p2++;
                p1++;
            }
            else
            {
                p1++;
            }
        }

        return p2 == d.size();
    }

    //TC:O(N*X) SC:O(X)
    string findLongestWord(string s, vector<string> &d)
    {

        int size = 0;
        string ans = "";
        for (int i = 0; i < d.size(); i++)
        {

            if (isPossible(s, d[i]))
            {
                if (d[i].size() > size)
                {

                    size = d[i].size();
                    ans = d[i];
                }
                else if (d[i].size() == size && ans > d[i])
                {

                    ans = d[i];
                    //                     string test=d[i];
                    //                     int p1=0;
                    //                     int p2=0;

                    //                     while(p1<test.size() && p2<ans.size()){

                    //                         if(test[p1]<ans[p2]){
                    //                             ans=test;
                    //                             break;
                    //                         }else if(test[p1]==ans[p2]){
                    //                             p1++;
                    //                             p2++;
                    //                         }else{
                    //                             break;
                    //                         }
                    //                     }
                }
            }
        }

        return ans;
    }
};