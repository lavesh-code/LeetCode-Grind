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
    vector<int> postorderTraversal(TreeNode* root) {
        // Vector to store postorder traversal
        vector<int> postorder;

        // If the tree is empty, return an empty traversal
        if (root == NULL) {
            return postorder;
        }

        // Stack for iterative traversal
        stack<TreeNode*> st1;

        // Push the root node onto the stack
        st1.push(root);

        // Iterative traversal to populate the vector
        while (!st1.empty()) {
            // Get the top node from st1
            root = st1.top();
            st1.pop();

            // Push the node's data directly into the vector
            postorder.push_back(root->val);

            // Push left child onto st1 if it exists
            if (root->left != NULL) {
                st1.push(root->left);
            }

            // Push right child onto st1 if it exists
            if (root->right != NULL) {
                st1.push(root->right);
            }
        }

        // Reverse the vector to get the correct postorder traversal
        reverse(postorder.begin(), postorder.end());

        // Return the postorder traversal
        return postorder;
    }
};