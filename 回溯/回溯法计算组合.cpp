#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    //组合问题不需要标记选过的元素
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        //对可选择元素不足的情况进行剪枝
        //已经选择的元素个数：path.size();
        //还需要的元素个数为:k - path.size();
        //在集合n中至多要从该起始位置 :n - (k - path.size()) + 1，开始遍历
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) { // 优化的地方
            path.push_back(i); // 处理节点
            backtracking(n, k, i + 1);
            path.pop_back(); // 回溯，撤销处理的节点
        }
    }
public:

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};

int main() {

}
