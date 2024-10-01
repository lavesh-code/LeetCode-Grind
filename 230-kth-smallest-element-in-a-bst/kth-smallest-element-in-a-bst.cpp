class Solution {
public:

    // Function to perform inorder traversal and save the nodes' values in a vector
    void inorderTraversal(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        inorderTraversal(root->left, result);
        result.push_back(root->val);
        inorderTraversal(root->right, result);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> result; 
        inorderTraversal(root, result);
        return result[k-1];
        
    }
};