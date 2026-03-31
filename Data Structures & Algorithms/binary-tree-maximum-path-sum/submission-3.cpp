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

    int res = INT_MIN;

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);

        return res;
    }

    int dfs(TreeNode* root){

        if (!root){
            return 0;
        }

        int maxLeft = dfs(root->left);
        int maxRight = dfs(root->right);

        res = max(res, root->val + maxLeft + maxRight);

        return max(0, root->val + max(maxLeft, maxRight));


    }
};
