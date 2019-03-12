/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty() || vin.empty()) return NULL;
        TreeNode* root = new TreeNode(pre[0]);
        vector<int> p1, v1, p2, v2;
        int i;
        for(i = 0; i < vin.size(); i ++)
            if(vin[i] == pre[0]) break;
        for(int j = 0; j < i; j ++) {
            p1.push_back(pre[j+1]);
            // p1[j] = pre[j+1] // 错误，vector的下标只能获取已存在的数，不能作为数组初始化来使用
            v1.push_back(vin[j]);
        }
        for(int j = i+1; j < vin.size(); j ++) {
            p2.push_back(pre[j]);
            v2.push_back(vin[j]);
        }
        root->left = reConstructBinaryTree(p1, v1);
        root->right = reConstructBinaryTree(p2, v2);
        return root;
    }
};