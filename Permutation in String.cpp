class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       
        vector<int> ans;
        if(s2.size()==0 || s1.size()==0) return false;
        vector<int> freq(26,0);
        for(char temp:s1){
            freq[temp-'a']++;
        }
        
        int first=0;
        int last=0;
        int count=s1.size();
        //Time:O(N)
        while(last<s2.size()){
            
            if(freq[s2[last++]-'a']-->=1) count--;
            if(count==0) return true;;
            if(last-first==s1.size() && freq[s2[first++]-'a']++>=0) count++;

        }
        
        return false;
        
        
        
    }
};
