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
public:
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> g(1e5+1);
        dfs(root,g);
        return height(root,start,g);
    }

    int height(TreeNode* root, int start, vector<vector<int>>& g) {
        vector<int>v(1e5+1,-1);
        v[start]=0;
        queue<int>q;
        q.push(start);
        int m = 0;

        while(!q.empty()) {
            int i = q.front();
            q.pop();
            for(auto e:g[i]) {
                if(v[e]==-1) {
                    q.push(e);
                    m = v[e] = v[i]+1;
                }
            }
        }

        return m;
    }

    void dfs(TreeNode* root, vector<vector<int>>& g) {
        if(root->left!=NULL) {
            int x = root->val;
            int y = root->left->val;
            g[x].push_back(y);
            g[y].push_back(x);
            dfs(root->left,g);
        }
        if(root->right!=NULL) {
            int x = root->val;
            int y = root->right->val;
            g[x].push_back(y);
            g[y].push_back(x);
            dfs(root->right,g);
        }
    }
};