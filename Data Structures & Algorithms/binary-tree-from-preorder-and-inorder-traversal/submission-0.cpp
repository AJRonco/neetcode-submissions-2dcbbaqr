class Solution {
public:

    TreeNode* helper(vector<int>& preorder, int& preIdx, int inStart, int inEnd, unordered_map<int, int>& mp) {
        if (inStart > inEnd) return nullptr;

        int val = preorder[preIdx++];
        TreeNode* root = new TreeNode(val);
        int pivot = mp[val];

        root->left = helper(preorder, preIdx, inStart, pivot - 1, mp);
        root->right = helper(preorder, preIdx, pivot + 1, inEnd, mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        std::unordered_map<int, int> nodeIndex;
        for (int i = 0; i < inorder.size(); i++) {
            nodeIndex[inorder[i]] = i;
        }

        int preIdx = 0;
        return helper(preorder, preIdx, 0, preorder.size() - 1, nodeIndex);
    }
};