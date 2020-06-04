//Time:O(n) and Space:O(1)
class Solution {
public:
    void reverseString(vector<char>& s) {
        int start=0;
        int last=s.size()-1;
        while(start<last){
            char temp=s[start];
            s[start]=s[last];
            s[last]=temp;
            start++;
            last--;
        }
    }
};
