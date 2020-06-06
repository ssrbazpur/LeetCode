//Time:O(n) where n is number of strings and Space:O(n)
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    unordered_map<string,int> hm;
    for(string temp:strings){
        hm[temp]++;
    }
    vector<int> ans;
    for(string temp:queries){
        if(hm.find(temp)!=hm.end()){
            ans.push_back(hm[temp]);
        }else{
            ans.push_back(0);
        }
    }
    return ans;
}
