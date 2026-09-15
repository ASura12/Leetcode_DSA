class Solution {
private:
    unordered_map<int, int> postMap;

    TreeNode* helper(vector<int>& preorder, int& preIdx, int postLeft, int postRight) {
        // Base case: no elements left to process
        if (postLeft > postRight) return nullptr;

        // Create the current root node
        TreeNode* root = new TreeNode(preorder[preIdx++]);

        // If this was the last node in this subtree scope, return it
        if (postLeft == postRight) return root;

        // Find the index of the next preorder element (left child) in postorder array
        int leftChildPostIdx = postMap[preorder[preIdx]];

        // Recursively build left and right subtrees based on the split index
        root->left = helper(preorder, preIdx, postLeft, leftChildPostIdx);
        root->right = helper(preorder, preIdx, leftChildPostIdx + 1, postRight - 1);

        return root;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        // Map values to their indices for O(1) lookups
        for (int i = 0; i < postorder.size(); i++) {
            postMap[postorder[i]] = i;
        }
        
        int preIdx = 0;
        return helper(preorder, preIdx, 0, postorder.size() - 1);
    }
};
