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
    int maxSumBST(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }

    vector<int> solve(TreeNode* node) {
        int sum = node->val, valid = 1, mx = node->val, mn = node->val;

        if(node->left != NULL) {
            vector<int> t = solve(node->left);
            sum += t[0];
            if(!t[1] || t[2]>=node->val) valid = 0;
            mx = max(mx,t[2]);
            mn = min(mn,t[3]);
        }
        if(node->right != NULL) {
            vector<int> t = solve(node->right);
            sum += t[0];
            if(!t[1] || t[3]<=node->val) valid = 0;
            mx = max(mx,t[2]);
            mn = min(mn,t[3]);
        }

        if(valid) ans = max(ans, sum);
        return {sum,valid,mx,mn};
    }
};