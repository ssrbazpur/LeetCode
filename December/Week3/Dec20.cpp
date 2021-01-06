class Solution
{
public:
    //Time:O(N) | Space:O(1)
    string decodeAtIndex(string S, int K)
    {

        long size = 0;
        //Get size
        for (int i = 0; i < S.size(); i++)
        {
            if (isdigit(S[i]))
            {
                size = size * int(S[i] - '0');
            }
            else
            {
                size++;
            }
        }

        for (int i = S.size() - 1; i >= 0; i--)
        {

            K = K % size;
            if (K == 0 && isalpha(S[i]))
            {
                string ans = "";
                ans += S[i];
                return ans;
            }

            if (isdigit(S[i]))
                size = size / ((int)S[i] - '0');
            else
                size--;
        }

        return "";

        //         string ans="";
        //         string value="";
        //         for(int i=0;i<S.size();i++){
        //             if(ans.size()>=K) {
        //             value+=ans[K-1];
        //                 return value;
        //             }
        //             if(S[i]>='a' && S[i]<='z'){
        //                 ans+=S[i];
        //             }else{
        //                 int num=int(S[i]-'0');
        //                 string temp=ans.substr(0,ans.size());
        //                 while(num-1>0){
        //                     ans=ans+temp;
        //                     num--;
        //                 }
        //             }
        //         }

        //         value+=ans[K-1];
        //         return value;
    }
};