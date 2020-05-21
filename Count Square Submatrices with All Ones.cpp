//Time:O(n^2) and Space:O(n^2)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        vector<vector<int>> store=matrix;
        for(int i=1;i<store.size();i++){
            
            for(int j=1;j<store[0].size();j++){
                if(store[i][j]==1){
                    
                    store[i][j]=min(store[i-1][j],min(store[i][j-1],store[i-1][j-1]))+1;
                    
                }
            }
            
        }
        
        int ans=0;
        for(vector<int> i:store){
            
            for(int j:i){
                ans+=j;
                
            }
        }
        
        return ans;
    }
};
