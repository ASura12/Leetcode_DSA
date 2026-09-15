class Solution {
public:
    // Helper function to find the index of a value in the postorder array
    int search(vector<int>& postorder, int left, int right, int val) {
        for (int i = left; i <= right; i++) {
            if (postorder[i] == val) {
                return i;
            }
        }
        return -1; // Fixed the syntax error here
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& postorder, int &preIdx, int left, int right) {
        // Base case 1: Out of bounds
        if (left > right || preIdx >= preorder.size()) return nullptr;
        
        // Create the current root node
        TreeNode* root = new TreeNode(preorder[preIdx]);
        preIdx++;
        
        // Base case 2: Leaf node reached (no children to process)
        if (left == right) return root;

        // Peak at the next element in preorder, which is the root of the left subtree
        int nextVal = preorder[preIdx];
        
        // Search for this left child in the postorder array
        int postIdx = search(postorder, left, right, nextVal);
        
        // Everything up to postIdx belongs to the left subtree
        root->left = helper(preorder, postorder, preIdx, left, postIdx);
        
        // Everything after postIdx (excluding the current root at 'right') belongs to the right subtree
        root->right = helper(preorder, postorder, preIdx, postIdx + 1, right - 1);
        
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preIdx = 0;
        return helper(preorder, postorder, preIdx, 0, postorder.size() - 1);
    }
};
