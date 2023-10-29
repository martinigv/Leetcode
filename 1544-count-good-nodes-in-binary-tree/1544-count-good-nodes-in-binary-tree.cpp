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
    int goodNodes(TreeNode* root) {
        //탐색 -> dfs
        //비교
        //1) 최고값 갱신
        //count
        //1) 최고값보다 크거나 같으면 +1
        return dfs(root, root->val);
    }
    int dfs(TreeNode* node, int m) {
        if (!node) {
            return 0;
        }
        int left = dfs(node->left, max(node->val, m));
        int right = dfs(node->right, max(node->val, m));
        int ans = left + right;
        if (node->val >= m) {
            ans++;
        }
        return ans;

    }
};