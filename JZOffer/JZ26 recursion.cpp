/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool recur(TreeNode* A,TreeNode* B){
        if(!B) return true;
        if(!A||A->val!=B->val) return false;
        return recur(A->left,B->left)&& recur(A->right,B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return (A&&B) && (recur(A,B)||isSubStructure(A->left,B)||isSubStructure(A->right,B));
    }
};
