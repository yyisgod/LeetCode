#include<iostream>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
		if(root == NULL)
			return NULL;
		TreeNode *temp;
		temp = root->right;
		root->right = root->left;
		root->left = temp;
		invertTree(root->right);
		invertTree(root->left);
		return root;
    }
};

int main() {
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);
	Solution s;
	TreeNode *r = s.invertTree(root);
	cout << root->val << ' '<< root->left->val << ' '<< root->right->val << ' '<< root->left->left->val << ' '
		<< root->left->right->val << ' ';
	return 0;
}
