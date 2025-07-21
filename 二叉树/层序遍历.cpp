#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> que;
    //根节点先入队
    if (root != NULL) que.push(root);
    vector<vector<int>> result;
    //循环判断队列是否为空
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        //依次取出队列中的节点，并将他们的左右子节点入队
        // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            vec.push_back(node->val);
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
        result.push_back(vec);
    }
    return result;
}

int main() {

}
