/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *t = q.front();
            ans.push_back(t->val);
            if(t->left != NULL)
                q.push(t->left);
            if(t->right != NULL)
                q.push(t->right);
            q.pop();
        }
        return ans;
    }
};