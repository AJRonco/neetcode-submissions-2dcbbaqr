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

private: 
    int res = INT_MIN;
    
public:
    int maxPathSum(TreeNode* root) {
        
        getMax(root);
        
        return res;

    }

    int getMax(TreeNode* root) {

        if (!root){
            return 0;
        }

        int left = getMax(root->left);
        int right = getMax(root->right);

        res = max(res, root->val + left + right);

        return max(0, root->val + max(left,right));

    }

    
};
