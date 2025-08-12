#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main() {

    /*
     满二叉树：只有度为0和2的节点的二叉树，深度为k，有2^(k-1)个节点

     完全二叉树：除了最后一层以外所有层都填满了，最后一层的节点都集中在该层最左边

     二叉搜索树：有序树，若左子树不空，则左子树上所有节点都小于它根节点的值（右子树也是一样）

     平衡二叉搜索树：一颗空树或者左右子树的高度差的绝对值不超过1，且左右子树都是一颗平衡二叉树
     */
}
