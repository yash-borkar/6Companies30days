// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/

class Solution {
    int res = 0;

public:
    vector<int> dfs(TreeNode* root, int distance) {
        vector<int> leafDist(11, 0);
        if (!root) {
            return leafDist;
        } else if (!root->left && !root->right) {
            leafDist[1] = 1;
            return leafDist;
        }

        vector<int> leftLeafDist = dfs(root->left, distance);
        vector<int> rightLeafDist = dfs(root->right, distance);

        for (int d1 = 1; d1 <= distance; ++d1) {
            for (int d2 = 1; d2 <= distance; ++d2) {
                if (d1 + d2 <= distance) {
                    res += leftLeafDist[d1] * rightLeafDist[d2];
                }
            }
        }

        for (int d = 1; d < 11; ++d) {
            leafDist[d] = leftLeafDist[d - 1] + rightLeafDist[d - 1];
        }

        return leafDist;
    }

    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return res;
    }
};