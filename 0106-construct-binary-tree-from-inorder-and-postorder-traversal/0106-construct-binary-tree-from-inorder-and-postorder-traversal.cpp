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
    TreeNode* buildTree(vector<int> inorder, vector<int> postorder) {
        if(inorder.empty()) return nullptr;
        int val = postorder.back();
        int i = find(inorder.begin(),inorder.end(), val) - inorder.begin();
        TreeNode* left = buildTree(vector<int>(inorder.begin(), inorder.begin()+i), vector<int>(postorder.begin(), postorder.begin()+i));
        TreeNode* right = buildTree(vector<int>(inorder.begin()+i+1, inorder.end()), vector<int>(postorder.begin()+i, postorder.end()-1));
        return new TreeNode(val, left, right);
    }
};