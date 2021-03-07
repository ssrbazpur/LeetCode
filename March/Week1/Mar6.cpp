class TrieNode
{
public:
    char data;
    unordered_map<char, TrieNode *> children;
    TrieNode(char s)
    {
        data = s;
    }
};

class Trie
{
public:
    TrieNode *root;
    int ans;

    Trie()
    {
        root = new TrieNode('\0');
        ans = 0;
    }

    void insert(string s)
    {
        TrieNode *temp = root;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            char word = s[i];
            if (temp->children.find(word) != temp->children.end())
            {
                temp = temp->children[word];
            }
            else
            {
                TrieNode *node = new TrieNode(word);
                temp->children.insert({word, node});
                temp = temp->children[word];
            }
        }
    }

    void new_words()
    {
        for (auto i : root->children)
        {
            dfs(i.second, 1);
        }
    }

    void dfs(TrieNode *t, int count)
    {

        cout << t->data << " " << count;
        if (t->children.size() == 0)
        {
            ans++;
            ans += count;
        }

        for (auto hm : t->children)
        {
            dfs(hm.second, count + 1);
        }
    }
};

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {

        Trie t;
        for (int i = 0; i < words.size(); i++)
        {
            t.insert(words[i]);
        }

        //DFS

        t.new_words();
        return t.ans;
    }
};