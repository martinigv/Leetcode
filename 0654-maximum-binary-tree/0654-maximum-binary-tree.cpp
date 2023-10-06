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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size());
    }
    
private:
    TreeNode* construct(const vector<int>& nums, int l, int r) {
        if (l == r) return nullptr;

        int maxi = l;
        for (int i = l + 1; i < r; i++) {
            if (nums[maxi] < nums[i]) {
                maxi = i;
            }
        }

        TreeNode* root = new TreeNode(nums[maxi]);
        root->left = construct(nums, l, maxi);
        root->right = construct(nums, maxi + 1, r);

        return root;
    }
};



