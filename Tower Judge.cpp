
//Time:O(n) and Space:O(n)
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        unordered_map<int,bool> hm;
       
        if(trust.size()==0) return 1;
        for(int i=1;i<=N;i++){
            hm.insert({i,true});
        }
        
        unordered_set<int> can;
        for(int i=0;i<trust.size();i++){
            hm[trust[i][0]]=false;
           if(hm[trust[i][1]]==true){ can.insert(trust[i][1]);}
            if(can.find(trust[i][0])!=can.end()){
                can.erase(trust[i][0]);
            }
        }
        
        if(can.size()>1) return -1;
       
        for(vector<int> a:trust){
            if(can.find(a[1])!=can.end()){
                hm[a[0]]=true;
            }
        }
        
        for(auto a=hm.begin();a!=hm.end();a++){
            cout<<a->first<<" "<<a->second<<endl;
            if(a->second!=true){
                return -1;
            }
        }
        
        int value;
        for(int a:can){
            value=a;
        }
        
        return value;
        
    }
};
