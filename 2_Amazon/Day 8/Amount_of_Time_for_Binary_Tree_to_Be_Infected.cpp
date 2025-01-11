// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

class Solution {
public:

    TreeNode* createParentMapping(TreeNode* root, int start, map<TreeNode*, TreeNode*> &nodeToParent){

        TreeNode* res= NULL;

        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root] = NULL;

        while(!q.empty()){

            TreeNode* front = q.front();
            q.pop();

            if(front->val == start) res = front;

            if(front->left){
                q.push(front->left);
                nodeToParent[front->left] = front;
            }

            if(front->right){
                q.push(front->right);
                nodeToParent[front->right] = front;
            }
        }

        return res;
    }

    int solve(TreeNode* root, map<TreeNode*, TreeNode*> &mp){

        map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        q.push(root);
        visited[root] = true;
        int ans = 0;

        while(!q.empty()){
            int size = q.size();
            bool flag = false;

            for(int i=0; i<size; i++){
                TreeNode* front = q.front();
                q.pop();

                if(front->left && !visited[front->left]){
                    q.push(front->left);
                    visited[front->left] = true;
                    flag = true;
                }

                if(front->right && !visited[front->right]){
                    q.push(front->right);
                    visited[front->right] = true;
                    flag = true;
                }

                if(mp[front] && !visited[mp[front]]){
                    q.push(mp[front]);
                    visited[mp[front]] = true;
                    flag = true;
                }
            }

            if(flag == true) ans++;
        }

        return ans;
    }

    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> nodeToParent;
        TreeNode* startNode = createParentMapping(root, start, nodeToParent);
        int ans = solve(startNode, nodeToParent);
        return ans;
        
    }
};