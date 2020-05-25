//Time:O(n*m) and Space:O(n*m)
//LCS
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    
        vector<vector<int>> store(A.size()+1,vector<int>(B.size()+1,0));
        
        for(int i=1;i<A.size()+1;i++){
            
            
            for(int j=1;j<B.size()+1;j++){
                if(A[i-1]==B[j-1]){
                    store[i][j]=store[i-1][j-1]+1;
                    
                }else{
                    store[i][j]=max(store[i-1][j],store[i][j-1]);
                }
            }
        }
        
        return store[store.size()-1][store[0].size()-1];
        
        
    }
    
};
