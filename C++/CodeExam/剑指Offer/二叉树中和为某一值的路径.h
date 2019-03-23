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
    void dfs(TreeNode * node, int sum, vector<vector<int> > &ans, vector<int> &trace) {
        trace.push_back(node->val);
        if(node->left == NULL && node->right == NULL) {
            if(sum == node->val) {
                ans.push_back(trace);
            }
        }
        sum -= node->val;
        if(node->left != NULL) {
            dfs(node->left, sum, ans, trace);
        }
        if(node->right != NULL) {
            dfs(node->right, sum, ans, trace);
        }
        trace.pop_back();
    }
    
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > ans;
        if(root == NULL) return ans;
        vector<int> trace;
        dfs(root, expectNumber, ans, trace);
        return ans;
    }
};