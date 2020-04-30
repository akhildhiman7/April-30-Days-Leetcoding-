/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \
      4   5
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    int mxx = 0;
    int helper(TreeNode *root) {
        if (!root)
            return 0-1;
        if (!root->left and !root->right) return 0;
        int left = -1, right = -1;
        if (root->left)
            left = helper(root->left);
        if (root->right)
            right = helper(root->right);

        int ttl = 0;
        if (left >= 0)
            ttl += left+1;
        if (right >= 0)
            ttl += right+1;

        mxx = max(mxx, ttl);

        return left > right ? left+1:right+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root or (!root->left and !root->right))
            return 0;
        mxx = 0;
        helper(root);
        return mxx;
    }
};
