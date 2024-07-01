/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            if(!node) ans += "# ";
            if(!node) continue;
            ans += to_string(node->val);
            ans.push_back(' ');
            q.push(node->left);
            q.push(node->right);
        }
        cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        auto root = new TreeNode(stoi(nextWord(data)));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            string left = nextWord(data); 
            string right = nextWord(data);
            if(left != "#") {
                auto l = new TreeNode(stoi(left));
                node->left = l;
                q.push(l);
            }
            if(right != "#") {
                auto r = new TreeNode(stoi(right));
                node->right = r;
                q.push(r);
            }
        }
        return root;
    }

private:
    string nextWord(string& word) {
        string ans = "";
        for(auto c:word) {
            if (c == ' ') break;
            ans.push_back(c);
        }
        word = word.substr(ans.size() + 1);
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));