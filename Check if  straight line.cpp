class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        
        if(c.size()==0) return false;
        if(c.size()<=2) return true;
        
        vector<int> first=c[0];
        vector<int> second=c[1];
        
        int x=first[0]-second[0];
        int y=first[1]-second[1];
        float s=INT_MIN;
        if(x!=0) s=(float)y/x;
        
        for(int i=2;i<c.size();i++){
            int temp1=first[0]-c[i][0];
            int temp2=first[1]-c[i][1];
            float slope=INT_MIN;
            if(temp1!=0){
                slope=(float)temp2/temp1;
                cout<<slope;
            }
            
            if(slope!=s) return false;
            
        }
        return true;
        
    }
};
