class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;
        if(s.size()==0) return ans;
        vector<int> freq(26,0);
        for(char temp:p){
            freq[temp-'a']++;
        }
        
        int first=0;
        int last=0;
        int count=p.size();
        //Time:O(N)
        while(last<s.size()){
            
            if(freq[s[last++]-'a']-->=1) count--;
            if(count==0) ans.push_back(first);
            if(last-first==p.size() && freq[s[first++]-'a']++>=0) count++;

        }
        
        return ans;
        
        
        
    }
};
