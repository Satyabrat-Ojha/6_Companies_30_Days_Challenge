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
    int countPairs(TreeNode* root, int distance) {
        ans = 0;
        dfs(root,distance);
        return ans;
    }

    vector<int> dfs(TreeNode* root, int distance) {
        if(root==nullptr) return {};

        auto l = dfs(root->left,distance);
        auto r = dfs(root->right,distance);

        if(l.empty() && r.empty()) return {1};

        for(auto i:l)
            for(auto j:r)
                if(i+j <= distance)
                    ans++;

        vector<int> v;
        for(auto i:l) v.push_back(i+1);
        for(auto j:r) v.push_back(j+1);
        return v;
    }
};