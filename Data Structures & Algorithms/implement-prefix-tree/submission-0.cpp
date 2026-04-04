class TrieNode
{
    public:
        TrieNode* children[26];
        bool isLeaf;
        TrieNode()
        {
            isLeaf = false;
            for(int i = 0; i < 26; i++)
            {
                children[i] = nullptr;
            }
        }
};

class PrefixTree {
public:
    TrieNode* head = nullptr;

    PrefixTree() {
        head = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = head;
        for(char c : word)
        {
            if(curr->children[c-'a'] == nullptr)
            {
                TrieNode* newNode = new TrieNode();
                curr->children[c-'a'] = newNode;
            }
            curr = curr->children[c-'a'];
        }
        curr->isLeaf = true;
    }
    
    bool search(string word) {
        TrieNode* temp = head;
        for(char c : word)
        {
            if(temp->children[c-'a'] == nullptr) return false;
            temp = temp->children[c-'a'];
        }
        return temp->isLeaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = head;
        for(char c : prefix)
        {
            if(temp->children[c-'a'] == nullptr) return false;
            temp = temp->children[c-'a'];
        }
        return true;
    }
};
