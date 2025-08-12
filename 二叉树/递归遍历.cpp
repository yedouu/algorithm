#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void traversal(TreeNode* cur,vector<int>& vec) {    //前序遍历
    if(cur==nullptr) return;   //递归结束条件

    vec.push_back(cur->val);    // 中
    traversal(cur->left, vec);  // 左
    traversal(cur->right, vec); // 右
}

void traversal2(TreeNode* cur,vector<int>& vec) {   //中序遍历
    if(cur==nullptr) return;

    traversal(cur->left, vec);  // 左
    vec.push_back(cur->val);    // 中
    traversal(cur->right, vec); // 右

}

void traversal3(TreeNode* cur,vector<int>& vec) {
    if(cur==nullptr) return;

    traversal(cur->left, vec);  // 左
    traversal(cur->right, vec); // 右
    vec.push_back(cur->val);    // 中

}


int main() {

}
