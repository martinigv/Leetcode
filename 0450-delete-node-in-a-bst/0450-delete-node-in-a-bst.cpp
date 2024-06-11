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
    TreeNode* search(TreeNode* root, int key)
    {
        if (root == nullptr || root->val == key)
            return root;
        if (key < root->val)
            return search(root->left, key);
        else
            return search(root->right, key);
    }
    TreeNode* findParent(TreeNode* root, TreeNode* node) {
        if (root == nullptr || root == node) {
            return nullptr;
        }
        if ((root->left && root->left == node) || (root->right && root->right == node)) {
            return root;
        }
        if (node->val < root->val) {
            return findParent(root->left, node);
        } else {
            return findParent(root->right, node);
        }
    }
     TreeNode* transplant(TreeNode* root, TreeNode* u, TreeNode* v)
    {
        TreeNode* u_p = findParent(root, u);
        if (u_p == nullptr)
            return v;
        else if (u == u_p->left)
            u_p->left = v;
        else
            u_p->right = v;
        return root;
    }
    TreeNode* minimum(TreeNode* root)
    {
        while(root->left != nullptr)
        {
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        
        TreeNode* z = search(root, key);
        if (z == nullptr) // Add this check to ensure z is not null
            return root;
        if (z->left == nullptr)
            root = transplant(root, z, z->right);
        else if (z->right == nullptr)
            root = transplant(root, z, z->left);
        else
        {
            TreeNode* y = minimum(z->right);
            if (y != z->right)
            {
                root = transplant(root, y, y->right);
                y->right = z->right;
            }
            root = transplant(root, z, y);
            y->left = z->left;
        }
        return root;
    }
};