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

    bool isIdentical(TreeNode* r1,TreeNode* r2){
        if(r1==NULL||r2==NULL)return r1==r2;
        bool isleftsub = isIdentical(r1->left,r2->left);
        bool isrightsub =isIdentical(r1->right,r2->right);
        return isleftsub && isrightsub && r1->val ==r2->val;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL || subRoot == NULL) return root == subRoot;
        if((root->val == subRoot->val) &&(isIdentical(root,subRoot)))return true;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};