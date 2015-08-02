#include <iostream>
#include <stack>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		stack<TreeNode*> st,st1,st2,sto;
		if(root && p && q) {
			st.push(root);
			while(!st.empty()) {
				TreeNode* e = st.top();
				st.pop();
				sto.push(e);
				if (e == p) {
					st1 = sto;
				}
				if (e == q)
					st2 = sto;
				if(!st1.empty() && !st2.empty())
					break;
				
				if(e->right) {
					st.push(e->right);
				}
				if(e->left) {
					st.push(e->left);
				}
				if(!e->left && !e->right) {
					sto.pop();
					
					while(sto.top()->right == e || !sto.top()->right) {
						e = sto.top();
						sto.pop();
					}
				}
			}

			while(!st.empty()) 
				st.pop();
			int len1 = st1.size();
			int len2 = st2.size();
			if (len1 > len2)
				while(st1.size() > len2)
					st1.pop();
			if (len2 > len1) 
				while (st2.size() > len1)
					st2.pop();
			len1 = st1.size();
			while(len1--) {
				if(st1.top() == st2.top()) {
					return st1.top();
				}
				st1.pop();
				st2.pop();
			}
			return NULL;
		}
		return NULL;
    }
};
int main() {
	TreeNode* root = new TreeNode(3);
	TreeNode* p1 = new TreeNode(5);
	TreeNode* q1 = new TreeNode(1);
	root->left = p1;
	root->right = q1;
	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2);
	root->left->right->left = new TreeNode(7);
	TreeNode* q2 = new TreeNode(4);
	root->left->right->right = q2;

	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);

	Solution s;
	TreeNode* result = s.lowestCommonAncestor(root,p1,q2);
	cout << result->val << endl;
	return 0;
}
