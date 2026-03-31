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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> orderVec;
        std::queue<TreeNode*> nodeQueue;

        if (!root) {
            return {};
        }
        
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {

            int length = nodeQueue.size();
            std::vector<int> row;

            for (int i = 0; i < length; i++) {
                TreeNode* curr = nodeQueue.front();
                nodeQueue.pop();
                row.push_back(curr->val);

                if (curr->left) {
                    nodeQueue.push(curr->left);
                }
                if (curr->right) {
                    nodeQueue.push(curr->right);
                }

            }
            orderVec.push_back(row);

        }

        return orderVec;


    }
};
