 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

 */

class Solution{
public:
    int solution(int n) {   //递归做法
        if (n == 0) return 0;
        if (n == 1) return 1;
        return solution(n-1)  + solution(n-2);
    }

    int solution2(int n) {
        int dp[30];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

int main(){
    Solution s;
    cout << s.solution(30) << endl;
    cout << s.solution(30) << endl;
}