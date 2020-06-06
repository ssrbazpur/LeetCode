/*
Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]


1. Sort

[[7,0],[7,1],[6,1],[5,0],[5,2],[4,4]]

2. Iterate and Reaarange:

When loop comes on [6,1]
[[7,0],[6,1],[7,1]
when 5,0
[[5,0],[7,0],[6,1],

*/

//Time:O(nlogn) and Space:O(n)
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        vector<vector<int>> result;
        sort(people.begin(),people.end(),[](vector<int> a,vector<int> b){
            
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]>b[0];
        });
        
        
        for(vector<int> track:people){
            //vector.insert(pos,value);
            result.insert(result.begin()+track[1],track);
        }
        return result;
        
    }
};
