#include<iostream>
using namespace std;

/**
 * Definition for a binary tree node.*/
  struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    int countNodes(TreeNode* root) {
		TreeNode* p =root;
		int num = 0;

		if(root) {
			num = 1;

			int hh = 0;
			while(p) {
				hh++; 
				p = p->left;
			}

			if(hh == 1) 
				return num;

			while(root) {
				int hmid = 0;
				p = root->right;
				while(p) {
					hmid++;
					p = p->left;
				}
				if(2 == hh) {
					return (hmid)?((num<<1)+1):(num<<1);
				}
				if((hmid==(hh-1))&&(root->right))
					num = (num<<1)+1,   root = root->right;
				else if(root->left)
					num = (num<<1),     root = root->left;
			
				hh--;
			}
		}
		return num;
        
    }
};

int main() {
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	//root->right->right = new TreeNode(9);
	Solution s;
	cout << s.countNodes(root);
	return 0;
}
