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
    void convertTree(TreeNode* root, TreeNode* &pre) {
        if(root == NULL) return;
        convertTree(root->left, pre);
        root->left = pre;
        if(pre != NULL)
            pre->right = root;
        pre = root;
        convertTree(root->right, pre);
    }
    
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL) return NULL;
        if(pRootOfTree->left == NULL && pRootOfTree->right == NULL) return pRootOfTree;
        TreeNode* pre = NULL;
        convertTree(pRootOfTree, pre);
        TreeNode* ans = pRootOfTree;
        while(ans->left != NULL)
            ans = ans->left;
        return ans;
    }
};

class SolutionI {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL) return NULL;
        if(pRootOfTree->left == NULL && pRootOfTree->right == NULL) return pRootOfTree;
        TreeNode* left = Convert(pRootOfTree->left);
        TreeNode* p = left;
        if(p != NULL) {
            while(p->right != NULL) {
                p = p->right;
            }
            p->right = pRootOfTree;
            pRootOfTree->left = p;
        }
        TreeNode* right = Convert(pRootOfTree->right);
        if(right != NULL) {
            right->left = pRootOfTree;
            pRootOfTree->right = right;
        }
        return (left == NULL) ? pRootOfTree : left;
    }
};