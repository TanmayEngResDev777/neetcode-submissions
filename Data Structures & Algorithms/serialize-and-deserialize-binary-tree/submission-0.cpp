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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        dfs_serialize(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return dfs_deserialize(data, i);
    }

private:
    void dfs_serialize(TreeNode* node, string& res) {
        if(!node) {
            res += "N,";
            return;
        }

        res += to_string(node -> val) + ",";
        dfs_serialize(node -> left, res);
        dfs_serialize(node -> right, res);
    }

    TreeNode* dfs_deserialize(const string& data, int& i) {
        int j = i;
        while(j < data.size() && data[j] != ',') j++;
        string token = data.substr(i, j - i);
        i = j + 1;

        if(token == "N") return nullptr;

        TreeNode* node = new TreeNode(stoi(token));
        node -> left = dfs_deserialize(data, i);
        node -> right = dfs_deserialize(data, i);
        return node;
    }
};
