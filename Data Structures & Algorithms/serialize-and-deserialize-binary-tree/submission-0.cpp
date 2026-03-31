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
        if (!root) {
            return "N";
        }
        queue<TreeNode*> q;
        string res;

        q.push(root);

        while (!q.empty()){
            TreeNode* current = q.front();
            q.pop();

            if (!current){
                res += "N,";
            }
            else{
                res += to_string(current->val) + ",";
                q.push(current->left);
                q.push(current->right);
            }
        }

        return res;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        getline(ss, val, ',');

        if (val == "N"){
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        while(getline(ss, val, ',')) {
            TreeNode* current = q.front();
            q.pop();

            if (val != "N"){
                current->left = new TreeNode(stoi(val));
                q.push(current->left);
            }

            getline(ss, val, ',');
            if (val != "N"){
                current->right = new TreeNode(stoi(val));
                q.push(current->right);
            }
        }
        return root;
    }
};
