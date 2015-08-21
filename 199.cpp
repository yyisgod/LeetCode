#include<iostream>
#include<vector>
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
    vector<int> rightSideView(TreeNode* root) {
		if(root == NULL)
			return vector<int>();
		vector<int> result;
		int mLevel = 0;
		rightSide(root, 0, mLevel, result);
		return result;
        
    }
	void rightSide(TreeNode* p, int cLevel, int& mLevel, vector<int>& result) {
		cLevel++;
		if(mLevel < cLevel) {
			result.push_back(p->val);
			mLevel++;
		}
		if(p->right) rightSide(p->right,cLevel, mLevel, result);
		if(p->left) rightSide(p->left,cLevel,mLevel,result);
		return;
	}
};

int main() {
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(3);
	root->right->right = new TreeNode(4);
	root->right->left = new TreeNode(5);
	root->left = new TreeNode(2);
	root->left->right = new TreeNode(6);
	root->left->right->left = new TreeNode(7);
	Solution s;
	auto r = s.rightSideView(root);
	for (auto i:r)
		cout << i << "->";

}
