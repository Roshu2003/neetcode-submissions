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
    void solve(TreeNode* node,vector<int> &cnt){
        if(!node)return;

        solve(node->left,cnt);
        if(cnt[0] == 0)return;
        cnt[0]--;
        if(cnt[0] == 0){
            cnt[1] = node->val;
            return;
        }
        solve(node->right,cnt);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> cnt(2,0);
        cnt[0] = k;
        solve(root,cnt);
        return cnt[1];
    }
};
