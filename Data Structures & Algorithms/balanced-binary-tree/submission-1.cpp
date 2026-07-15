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
    int find(TreeNode* node){
        if(!node)return 0;

        return 1 + max(find(node->left),find(node->right));
    }
    pair<bool,int> dfs(TreeNode* node){
        if(!node)return {true,0};

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        bool isB = (abs(left.second - right.second) <= 1 && left.first && right.first);
        int h = 1 + max(left.second,right.second);
        return {isB,h};
    }
    bool isBalanced(TreeNode* root) {
        if(!root)return true;

        // return (abs(find(root -> left) - find(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right));
        return dfs(root).first;
    }
};
