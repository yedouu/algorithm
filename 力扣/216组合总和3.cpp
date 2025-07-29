#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    // int sum = 0;
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(n,k,1,0);
        return result;
    }

    void backtrack(int n,int k,int index,int sum) {
        if (temp.size() == k) {
            if (sum == n) result.push_back(temp);
            // cout<<"quit"<<endl;
            return ;
        }

        for (int i = index; i <= 9 && sum < n && temp.size() < k; i++) {
            if (sum + i > n) break;
            sum+=i;
            temp.push_back(i);
            // cout<<"add:"<<i<<endl;
            backtrack(n,k,i+1,sum);
            sum-=i;
            temp.pop_back();
        }
    }
};

int main() {

    Solution s;
    vector<vector<int>> result = s.combinationSum3(9, 45);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}