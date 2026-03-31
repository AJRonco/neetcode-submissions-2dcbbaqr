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
    int maxDepth(TreeNode* root) {

        int depth = dfs(root, 0);

        return depth;
    }

    int dfs(TreeNode* root, int count){

        if(!root){
            return count;
        }
        count++;
        return max(dfs(root->left,count), dfs(root->right,count));
    }

};