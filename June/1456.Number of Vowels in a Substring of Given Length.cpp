class Solution {
public:
    int maxVowels(string s, int k) { 
        int count=0;
        bool vowels[26]={false};
        vowels[0]=vowels[4]=vowels[8]=vowels[14]=vowels[20]=true;
        int track=0;
        for(int i=0;i<s.size();i++){
            if(i>=k && vowels[s[i-k]-'a']){
                count--;
            }
            if(vowels[s[i]-'a']){
                count++;
            }
            track=max(count,track); //if index is printed then it indicate end point
        }
        return track;
    }
};
