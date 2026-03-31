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



 /*
 add root true
 !queue.empty()
    curr
    if true pushback vec
    if node->right


 
 
 
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> res;
        dfs(root, 0, res);
        return res;

    }

    void dfs(TreeNode* node, int depth, std::vector<int>& res) {
        if (!node) return;

        if (res.size() == depth){
            res.push_back(node->val);
        }

        dfs(node->right, depth +1,  res);
        dfs(node->left, depth+1,  res);
    }
};
