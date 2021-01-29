```
//1. Tower of Hanoi

//n disk from first to second.
void tower(int n,int first,int second,int third){
    //first to third
    tower(n-1,first,third,second);
    //move to second
    cout<<n<<"from"<<first<<second;
    //third to second
    tower(n-1,third,second,first);
}

```

```
2. Subsequence

vector<string> gss(string s){

    if(s.size()==0){
vector<string> a;
a.push_back("");
        return a;
    }


    //1. Ayega
    //2.Nhi AYEGA
    char a=s[0];

    string sub=s.substr(1,s.size()-1);
    gss(sub);

    vector<string> ans={};
    for(char c:sub){
        string one=c;
        string two=a+c;
        ans.push_back(one);
        ans.push_back(two);
    }

    return ans;
}




```
24 Done