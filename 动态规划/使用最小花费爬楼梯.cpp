 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

 */

class Solution{
public:
    int solution(vector<int>& cost) {
        //初始化dp数组
        int dp[cost.size()+1];
        dp[0] = 0;  //到达第0、1个台阶不用体力
        dp[1] = 0;

        for (int i = 2; i<=cost.size(); i++) {
            dp[i] = min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[cost.size()];
    }
};

int main(){

}