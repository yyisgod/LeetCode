#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*这个写法虽然土，但是全面*/ 
class TrieNode {

	
public:
    // Initialize your data structure here.
	char content;
	bool isend;
	int count;
	vector<TrieNode*> children;
	
    TrieNode():content(' '),isend(false),count(0) {}
	TrieNode(char ch):content(ch), isend(false), count(0) {}
	TrieNode* findNode(char ch) {
		if (!children.empty()) {
			for (auto child:children)
				if (child->content == ch)
					return child;
		}
		return nullptr;
	}
	~TrieNode() {
		for (auto child:children)
			delete child;
	}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
		if (search(word)) return;
		TrieNode* curr = root;
		for (auto ch : word) {
			TrieNode* child = curr->findNode(ch);
			if (child != NULL)
				curr = child;
			else {
				TrieNode* newNode = new TrieNode(ch);
				curr->children.push_back(newNode);
				curr = newNode;
			}
			++curr->count;
		}
		curr->isend = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
		TrieNode* curr = root;
		for (auto ch:word) {
			curr = curr->findNode(ch);
			if(curr == NULL)
				return false;
		}
		return curr->isend == true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
       TrieNode* curr = root;
		for (auto ch:prefix) {
			curr = curr->findNode(ch);
			if(curr == NULL)
				return false;
		}
		return true;
    }
	~Trie() {
		delete root;
	}

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
//
int main() {
	Trie trie;
	trie.insert("somestring");
	trie.insert("key");
	cout << trie.search("key") << endl;
	cout << trie.startsWith("some") << endl;
	trie.insert("a");
	cout << trie.search("a") << endl;
}
