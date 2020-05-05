class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char,int> hm;
        for(char a:s){
            
            
            if(hm.find(a)!=hm.end()){
                
                hm[a]++;
            }
            else{
                hm.insert({a,1});
            }
        }
        
        
       for(int i=0;i<s.size();i++){
           
           if(hm[s[i]]==1){
               return i;
           }
       }
        
        
    return -1;
    }
};
