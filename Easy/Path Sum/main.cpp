/**
 * PROBLEM:
 * 
 * Given the root of a binary tree and an integer targetSum,
 * return true if the tree has a root-to-leaf path such that
 * adding up all the values along the path equals targetSum.
 * A leaf is a node with no children.
*/

/* defintion of tree node */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* my solution */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        if (root->val == targetSum && root->left == nullptr && root->right == nullptr) return true;
        int target = targetSum-root->val;
        if (root->left != nullptr) if (hasPathSum(root->left, target)) return true; 
        if (root->right != nullptr) if (hasPathSum(root->right, target)) return true;
        return false;
    }
};

