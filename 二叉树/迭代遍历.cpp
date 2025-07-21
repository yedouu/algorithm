#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
迭代法思路说明：使用栈来进行非递归的前中后序遍历
1.前序遍历:
访问顺序和处理顺序一样，所以只要处理当前节点（中间节点），
然后依次压入右节点和左节点再在下一个循环中弹出处理就行。
2.中序遍历：
访问顺序和处理顺序不一样，但易知中序先处理左边节点再处理右边节点，
所以先将左边节点全部压入栈，直到为空时再依次弹出处理并将节点的右节点压入栈，
此时cur不为空并重新开始处理左边节点
3.后序遍历：
已知后序遍历为左右中，所以可以将前序遍历的中左右改为中右左，并将结果vector反转得到左右中

 */


vector<int> preorderTraversal(TreeNode* root) {     //迭代法-前序遍历
    stack<TreeNode*> st;
    vector<int> result;
    if (root == NULL) return result;
    st.push(root);      //提前把root压入栈
    while (!st.empty()) {
        //先处理中间节点
        TreeNode* node = st.top();                       // 中
        st.pop();
        result.push_back(node->val);

        //因为打印时是先左后右，所以把右边先压入栈以便先访问左边节点
        if (node->right) st.push(node->right);           // 右（空节点不入栈）
        if (node->left) st.push(node->left);             // 左（空节点不入栈）
    }
    return result;
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur != NULL || !st.empty()) {
        if (cur != NULL) { // 指针来访问节点，访问到最底层
            st.push(cur); // 将访问的节点放进栈
            cur = cur->left;                // 左
        } else {
            cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
            st.pop();
            result.push_back(cur->val);     // 中
            cur = cur->right;               // 右
        }
    }
    return result;
}

vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    vector<int> result;
    if (root == NULL) return result;
    st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        result.push_back(node->val);
        if (node->left) st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
        if (node->right) st.push(node->right); // 空节点不入栈
    }
    reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
    return result;
}


int main() {

}
