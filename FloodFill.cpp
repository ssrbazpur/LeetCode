class Solution {
public:
    bool outofbound(vector<vector<int>> image,int i,int j,int v){
        
        
        if(i<0 || i>image.size()-1 || j<0 || j>image[0].size()-1){
            return true;
        }
        return false;
    }
    
    void dfs(vector<vector<int>> &image,int i,int j,int color,int v){
        
        if(outofbound(image,i,j,v) || image[i][j]!=v){
            return;
        }
        
        cout<<v;
        image[i][j]=color;
        dfs(image,i+1,j,color,v);
        dfs(image,i-1,j,color,v);
        dfs(image,i,j+1,color,v);
        dfs(image,i,j-1,color,v);
        
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor) return image;
        dfs(image,sr,sc,newColor,image[sr][sc]);
        
        return image;
        
    }
};
