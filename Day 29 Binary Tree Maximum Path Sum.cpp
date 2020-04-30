/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
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
    int maxPath;

    int helper(TreeNode* root) {
        if (root==NULL)
            return 0;
        int leftMax = helper(root->left);
        int rightMax = helper(root->right);

        leftMax = max(0, leftMax);
        rightMax = max(0, rightMax);

        int merethrough = root->val + leftMax + rightMax;

        maxPath = max(maxPath, merethrough);
        return max(leftMax, rightMax) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        maxPath = INT_MIN;
        helper(root);
        return maxPath;
    }
};
