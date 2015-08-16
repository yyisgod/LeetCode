#include<iostream>
#include<string>
#include<vector>
#include<sstream>
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
    vector<string> binaryTreePaths(TreeNode* root) {
    	if(root){
    

        vector<vector<int> > path;
		vector<string> result;
		vector<int> p;
		findPaths(root,p,path);
		for (auto i:path) {
			if(i.size() == 1) {
			ostringstream o;
			o << i[0];
			result.push_back(o.str());
			}				
			else
			{	
				string s;
				ostringstream o;
				for(auto j:i) {
					o << j << "->";
				}
				s = o.str();
				s.resize(s.length()-2);
				result.push_back(s);
			}
		}
		return result;
			}
    }
	void findPaths(TreeNode* root,vector<int>& p, vector<vector<int> >& result) {
		
		
		p.push_back(root->val);
		if(!root->left && !root->right)
		{
			result.push_back(p);
			return;
		}
		
		auto temp = p;
		if(root->left)
			findPaths(root->left,temp,result);
		temp = p;
		if(root->right)
			findPaths(root->right,temp,result);
		return;
	}
};
/*
void binaryTreePaths(vector<string>& result, TreeNode* root, string t) {
    if(!root->left && !root->right) {
        result.push_back(t);
        return;
    }

    if(root->left) binaryTreePaths(result, root->left, t + "->" + to_string(root->left->val));
    if(root->right) binaryTreePaths(result, root->right, t + "->" + to_string(root->right->val));
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    if(!root) return result;

    binaryTreePaths(result, root, to_string(root->val));
    return result;
}
*/
int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(5);
	root->left->left = new TreeNode(4);
	TreeNode *root1 = new TreeNode(1);;
	Solution s;
	auto r = s.binaryTreePaths(root1);
	for (auto i:r)
		cout << i << '$';
	return 0;
}
