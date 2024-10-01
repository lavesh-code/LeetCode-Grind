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
    bool isSameTree(TreeNode* s, TreeNode* t) {
        // Both trees are empty
        if (s ==NULL && t==NULL) return true;

        // One tree is empty, and the other is not 
        if (s==NULL || t==NULL) return false;

        // Values do not match
        if (s->val != t->val) return false; 

        // Recursively check left and right subtrees
        return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // If root is null, subRoot cannot be a subtree
        if (root == NULL) return false; 

        // INORDER LIKE TRAVERSAL WITH CHECKING AT EACH NODE - 
        // Check if trees are identical
        if(isSameTree(root, subRoot)) return true; 

        // Recursively check left and right subtrees
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};