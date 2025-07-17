 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

 */

class Solution{
public:
    int solution(int n) {
        vector<int> dp(n+1);
        dp[2] = 1;
        for (int i = 3;i<=n;i++) {
            for (int j = 1;j<=i/2;j++) {
                dp[i] = max(dp[i],max(j*(i-j),j*dp[i-j]));
                /*
                 状态转移公式解释：
                要把i拆分为多个数使其乘积最大；
                首先考虑至少两个数的情况，遍历其中一个数到i/2即可；
                如果有三个及以上的数，则照常遍历第一个数，但是乘积第二部分为另一半的dp数值（即将另一个数拆分为两个及以上的数），
                这样就是三个及以上的数字；
                至于为什么还要和dp[i]比较大小，是因为dp[i]经过多次计算，所以每次要取最大的。
                 */
            }
        }
        return dp[n];
    }
};

int main(){
    Solution solution;
    cout<<solution.solution(2);
}