/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans;
public:
    int maxPathSum(TreeNode* root) {
        ans = root->val;
        pathSum(root);
        return ans;
    }

    int pathSum(TreeNode* root) {
        if(!root) return 0;
        int a = max(0, pathSum(root->left)), b = max(0, pathSum(root->right));
        ans = max(ans, a + b + root->val);
        return max(a, b)+ root->val;
    }
};