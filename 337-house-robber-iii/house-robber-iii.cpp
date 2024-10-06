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
    unordered_map<TreeNode*, int> dp;
    int f(TreeNode* node){
        if(node == NULL) return 0;
        if(dp.find(node) != dp.end()) return dp[node]; 

        if(node->left == NULL && node->right == NULL) return node-> val; 

        // ki mai agar node ko le raha hu;
        int take = node->val;
        int take_left = 0, take_right = 0; 
        if (node-> left != NULL) {
            take_left = f(node->left->left) + f(node->left->right);
        }
        if(node-> right !=NULL){
            take_right = f(node->right->left)+ f(node->right->right);
        }
        take += (take_left + take_right);  

        // agar mai node ko nahi le raha hu
        int not_take = f(node-> left) + f(node-> right);
        dp[node] = max(take, not_take); 
        return dp[node];  
    }
    int rob(TreeNode* root) {
        return f(root); 
    }
};