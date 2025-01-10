// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curNode = q.front();
            q.pop();
            
            if (curNode == nullptr) {
                s.append("#,");
            } else {
                s.append(to_string(curNode->val) + ",");
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        
        if (!s.empty()) {
            s.pop_back();
        }
        
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty() || data == "#") return nullptr; 

        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Read the left child
            if (getline(s, str, ',')) {
                if (str == "#") {
                    node->left = nullptr;
                }
                else if (!str.empty()) {
                    TreeNode* leftNode = new TreeNode(stoi(str));
                    node->left = leftNode;
                    q.push(leftNode);
                }
            }

            // Read the right child
            if (getline(s, str, ',')) {
                if (str == "#") {
                    node->right = nullptr;
                } 
                else if (!str.empty()) {
                    TreeNode* rightNode = new TreeNode(stoi(str));
                    node->right = rightNode;
                    q.push(rightNode);
                }
            }
        }

        return root;
    }
};
