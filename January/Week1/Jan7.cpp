class Solution
{
public:
    //Time:O(n) | SPace:O(N)
    int lengthOfLongestSubstring(string s)
    {

        int n = s.length(), ans = 0;
        unordered_map<int, int> hm;
        // try to extend the range [start, end]
        int start = 0;
        for (int end = 0; end < n; end++)
        {

            //1. Update Start
            if (hm.find(s[end]) != hm.end())
                start = max(start, hm[s[end]] + 1);

            //2. Update ans
            ans = max(ans, end - start + 1);

            //3. Update index of element
            hm[s[end]] = end;
        }
        return ans;

        //         if(s.size()<=1) return s.size();
        //         int start=0;
        //         int end=0;
        //         int ans=0;
        //         unordered_set<int> hm;
        //         while(start<s.size() && end<s.size()){

        //             char a=s[end];

        //             if(hm.find(a)==hm.end()){
        //                 end++;
        //                 hm.insert(a);
        //                 if(end-start > ans) ans=end-start;
        //                 continue;
        //             }

        //             while(hm.find(a)!=hm.end()){
        //                 char b=s[start];
        //                 hm.erase(b);
        //                 start++;
        //             }

        //         }
        //         return ans;
    }
};