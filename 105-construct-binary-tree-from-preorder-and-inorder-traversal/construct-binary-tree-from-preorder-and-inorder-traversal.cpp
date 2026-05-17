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

    int findpos(vector<int> inorder,int left,int right, int element){
        for(int i = left;i<=right;i++){
            if(inorder[i] == element){
                return i;
            }
        }
        return -1;
    }

    TreeNode* solve(vector<int>preorder,vector<int>inorder,int &index ,int inorderstart,int inorderend){
        // Base Case
        if(inorderstart > inorderend){
            return NULL;
        }
        // Creating root element and getting root element position
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int position = findpos(inorder,inorderstart,inorderend,element);
        
        // Recursive call

        root->left = solve(preorder,inorder,index,inorderstart,position-1);
        root->right = solve(preorder,inorder,index,position+1,inorderend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        TreeNode* ans = solve(preorder,inorder,preorderIndex,0,inorder.size()-1);
        return ans;
    }
};