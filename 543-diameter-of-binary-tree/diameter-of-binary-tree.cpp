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
    int diameter = 0;
    int calculateHeight(TreeNode* root){
        if(root==nullptr) return 0;

        int leftheight = calculateHeight(root->left);
        int rightheight = calculateHeight(root->right);

        diameter = max(diameter, leftheight + rightheight);

        return 1 + max(leftheight, rightheight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        calculateHeight(root);

        return diameter;
    }
};