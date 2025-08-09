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
int ans=0;
void solve(TreeNode* root,int step,bool mark){
    if(root==NULL)return;
    ans=max(ans,step);
    if(mark){
        solve(root->right,step+1,false);
        solve(root->left,1,true);
    }
    else{
        solve(root->left,step+1,true);
        solve(root->right,1,false);
    }
}
    int longestZigZag(TreeNode* root) {
        if(root==NULL)return 0;
        solve(root->left,1,true);
        solve(root->right,1,false);
        return ans;
    }
};
