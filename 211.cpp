/*208的基础上，逢'.'就遍历递归*/ 
class TrieNode {
public:

    TrieNode(bool end=false) {
        isEnd = end;
        memset(children, 0, sizeof(children));
    }
    bool isEnd;
    TrieNode* children[26];
};

class WordDictionary {
public:

    // Buildup the constructor
    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *node = root;
        for (int i=0; i<word.size(); i++)
        {
            if (node->children[word[i]-'a'])
            {
                node = node->children[word[i]-'a'];
                if (i == word.size()-1)
                    node->isEnd = true;
            }
            else {
                TrieNode *child = new TrieNode(i==word.size()-1?true:false);
                node->children[word[i]-'a'] = child;
                node = child;
            }
        }
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchHelper(word, 0, root);
    }

private:

    TrieNode *root;
    // i: the current processing index
    // node: the node that might contain the character word[i]
    bool searchHelper(string &word, int i, TrieNode *node) {
        if (!node) 
            return false;
        if (i == word.size())
            return node->isEnd; 
        if (word[i] == '.')
        {
            for (int j=0; j<26; j++)
            {
                if (searchHelper(word, i+1, node->children[j]))
                    return true;
            }
            return false;
        }
        else {
            return searchHelper(word, i+1, node->children[word[i]-'a']);
        }
    }
};
