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


    TreeNode* findMinNode(TreeNode* root) {
        TreeNode* current = root;
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if (!root) {
            return nullptr;
        }


        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else {

            if (!root->left) {
                return root->right;
            }
            else if (!root->right) {
                return root->left;

            }
            else {
                TreeNode* minNode = findMinNode(root->right);
                root->val = minNode->val;
                root->right = deleteNode(root->right, minNode->val);
            }



        }
        return root;
    }
};