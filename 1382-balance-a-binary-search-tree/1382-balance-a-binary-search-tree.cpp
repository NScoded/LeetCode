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

    vector<int>inorder;

    TreeNode* Array(TreeNode* root){
        if(root==nullptr)return nullptr;
        
        Array(root->left);
        inorder.push_back(root->val);
        Array(root->right);
        return nullptr;
    }

    TreeNode* MakeTree(int l,int r){
        if(l>r) return nullptr;
        int mid=(l+r)/2;
        TreeNode* root=new TreeNode(inorder[mid]);
        root->left=MakeTree(l,mid-1);
        root->right=MakeTree(mid+1,r);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        Array(root);
        return MakeTree(0,inorder.size()-1);
        
    }
};