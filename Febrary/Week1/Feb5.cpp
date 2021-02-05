class Solution
{
public:
    vector<string> makePoints(string path)
    {

        vector<string> points;
        while (path.find("/") != string::npos)
        {
            int pos = path.find("/");
            string temp = path.substr(0, pos);
            if (temp != "")
            {
                points.push_back(temp);
            }
            path = path.substr(pos + 1);
        }

        if (path.size() > 0)
        {
            points.push_back(path);
        }

        return points;
    }

    //TC:O(n) || SC: O(N)
    string simplifyPath(string path)
    {

        // vector<string> points=makePoints(path);

        stringstream ss(path);

        // vector<string> points=getline(ss,path);

        vector<string> ans;

        string temp;
        while (getline(ss, temp, '/'))
        {
            if (temp == "")
                continue;

            if (temp == ".")
            {
                continue;
            }
            else if (temp == "..")
            {
                if (ans.size() != 0)
                {
                    ans.pop_back();
                }
            }
            else
            {
                ans.push_back(temp);
            }
        }

        //Stack

        //         for(string temp:points){
        //             if(temp=="."){
        //                 continue;
        //             }else if(temp==".."){
        //                 if(ans.size()!=0){
        //                     ans.pop_back();
        //                 }
        //             }else{
        //                 ans.push_back(temp);
        //             }
        //         }

        string result = "/";
        for (string a : ans)
        {
            result += a;
            result = result + "/";
        }

        if (result.size() > 1)
        {
            result = result.substr(0, result.size() - 1);
        }
        return result;
    }
};