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
    int solve(TreeNode* node,int mx){
        if(!node)return 0;
        // cout<< "node->"<<node->val<<" max ->" << mx<<endl;
        int ans = 0;
        if(node -> val >= mx)ans = 1;
        auto l = solve(node->left,max(mx,node->val));
        auto r = solve(node->right,max(mx,node->val));
        return ans + l + r;
    }
    int goodNodes(TreeNode* root) {
        return solve(root,INT_MIN);
    }
};
