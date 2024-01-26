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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        while(root!=NULL && (root->val < low || root->val > high)) {
            if(root->val < low) root=root->right;
            else root=root->left;
        }
        if(root==NULL) return root;

        trim(root->left,root,0,low,high);
        trim(root->right,root,1,low,high);

        return root;
    }

    void trim(TreeNode* root, TreeNode* parent, int c, int low, int high) {
        if(root==NULL) return;
        while(root!=NULL && (root->val < low || root->val > high)) {
            if(root->val < low) root=root->right;
            else root=root->left;
        }
        if(!c) parent->left = root;
        else parent->right = root;

        if(root==NULL) return;
        
        trim(root->left,root,0,low,high);
        trim(root->right,root,1,low,high);
    }
};