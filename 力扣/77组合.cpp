#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<vector<int>> result;
    vector<int> temp;

    vector<vector<int>> combine(int n, int k) {
        result.clear();
        temp.clear();
        backtrack(n,k,1);
        return result;
    }

    void backtrack(int n,int k,int index) {
        if (temp.size() == k) {
            result.push_back(temp);
            return ;
        }
        //这里的循环做了剪枝，当元素个数不足时就放弃
        for (int i = index;i <= n - (k - temp.size()) + 1;i++) {
            temp.push_back(i);
            backtrack(n,k,i+1);
            temp.pop_back();
        }
    }
};

int main() {

}