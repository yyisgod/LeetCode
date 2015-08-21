class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) { std::swap(p, q); }
        while (root->val < p->val || root->val > q->val) {
            while (root->val < p->val) { root = root->right; }
            while (root->val > q->val) { root = root->left; }
        }
        return root;
    }
};
