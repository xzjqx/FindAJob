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
    bool isSameTree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if(pRoot2 == NULL) return true;
        else if(pRoot1 == NULL) return false;
        if(pRoot1->val == pRoot2->val) {
            if (isSameTree(pRoot1->left, pRoot2->left) && isSameTree(pRoot1->right, pRoot2->right))
                return true;
            else
                return (isSameTree(pRoot1->left, pRoot2) || isSameTree(pRoot1->right, pRoot2));
        } else {
            return (isSameTree(pRoot1->left, pRoot2) || isSameTree(pRoot1->right, pRoot2));
        }
        return false;
    }
    
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2 == NULL) return false;
        return isSameTree(pRoot1, pRoot2);
    }
};