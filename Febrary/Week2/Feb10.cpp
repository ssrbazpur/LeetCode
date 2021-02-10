/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

/*
Other Approach:
1. Make a duplicate 1->1->2->2->3->3
2. Then set the random pointer. 
3. Separate the duplicate links 1->2->3
*/

//TC:O(N) | SC:O(N)
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        if (head == NULL)
            return NULL;

        unordered_map<Node *, Node *> hm;

        Node *it = head;
        while (it != NULL)
        {
            Node *itcopy = new Node(it->val);
            hm.insert({it, itcopy});
            it = it->next;
        }

        Node *track = head;
        while (track != NULL)
        {
            Node *copyNode = hm[track];
            Node *copyNodeNext = hm[track->next];
            copyNode->next = copyNodeNext;
            Node *copyNodeRandom = NULL;
            if (hm.find(track->random) != hm.end())
            {
                copyNodeRandom = hm[track->random];
            }
            copyNode->random = copyNodeRandom;
            track = track->next;
        }

        return hm[head];
    }
};