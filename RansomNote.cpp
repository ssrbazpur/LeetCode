class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char,int> hm;
        for(char a: ransomNote){
            if(hm.find(a)!=hm.end()){
                hm[a]++;
            }else{
                hm.insert({a,1});
            }
        }
        
       for(char a:magazine){
           
           if(hm.find(a)!=hm.end() && hm[a]>1) hm[a]--;
           else if(hm.find(a)!=hm.end() && hm[a]==1) {
               hm[a]--;
               hm.erase(a);
           }
           
       }
        
        if(hm.size()==0) return true;
        return false;
    }
};
