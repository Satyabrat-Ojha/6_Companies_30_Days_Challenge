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
    map<TreeNode*, int> m;
public:
    int maxPathSum(TreeNode* root) {
        ans = root->val;
        m.clear();
        pathSum(root);
        return ans;
    }

    int pathSum(TreeNode* root) {
        if(!root) return 0;
        if(m[root]) return m[root];
        ans = max(ans, max(0, pathSum(root->left)) + max(0, pathSum(root->right)) + root->val);
        return m[root] = max({0, pathSum(root->left), pathSum(root->right)})+ root->val;
    }
};