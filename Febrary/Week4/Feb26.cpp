class Solution {
public:
    
    //Time:O(n+m) | Space:O(n+m)
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int p1=0,p2=0;
        
        stack<int> s;
        
        while(p1<pushed.size() && p2<popped.size()){
            
            int popValue=popped[p2];

            if(!s.empty() && s.top()==popValue){
                s.pop();
                p2++;
            }else{
                s.push(pushed[p1]);
                p1++;
            }
              
        }
        while(p2<popped.size()){
            if(!s.empty() && s.top()==popped[p2]){
                s.pop();
                p2++;
            }else{
                return false;
            }
            
        }
        
        return true;
        
    }
};