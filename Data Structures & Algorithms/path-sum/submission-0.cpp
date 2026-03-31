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

    bool hasPath = false;
    bool hasPathSum(TreeNode* root, int targetSum) {
        

        dfs(root, targetSum, 0);
        return hasPath;
    }

    void dfs(TreeNode* root, int targetSum, int currentSum) {
        if (!root) {
            return;
        }

        currentSum+=root->val;


        if (currentSum == targetSum && !root->left && !root->right) {
            hasPath = true;
        }
        
        dfs(root->right, targetSum, currentSum);
        dfs(root->left, targetSum, currentSum);
    }
};