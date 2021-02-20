class Solution
{
public:
    //Time:O(n) | Space:O(n)
    string minRemoveToMakeValid(string s)
    {
        stack<pair<char, int>> stack;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ')')
            {
                if (!stack.empty())
                {
                    char top = stack.top().first;
                    if (top == '(')
                    {
                        stack.pop();
                    }
                    else
                    {
                        stack.push({')', i});
                    }
                }
                else
                {
                    //code
                    stack.push({')', i});
                }
            }
            else if (s[i] == '(')
            {
                stack.push({'(', i});
            }
        }

        unordered_set<int> indicesToRemove;
        while (!stack.empty())
        {
            indicesToRemove.insert(stack.top().second);
            stack.pop();
        }

        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (indicesToRemove.find(i) != indicesToRemove.end())
            {
                continue;
            }
            ans += s[i];
        }

        return ans;
    }
};