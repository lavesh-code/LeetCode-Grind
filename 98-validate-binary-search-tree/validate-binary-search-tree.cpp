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
    bool isValidBST(TreeNode* root) {
        return ValidateBST(root, LLONG_MIN, LLONG_MAX);
        
    }

    bool ValidateBST(TreeNode* root, long long minVal, long long maxVal){
        if(root == NULL) return true;
        if(root-> val >= maxVal || root-> val <= minVal) return false;
        else return ((ValidateBST(root->left, minVal, root-> val))
                   &&(ValidateBST(root->right, root->val, maxVal)));
    }
};