 #include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
 using namespace std;

/*
 问题描述：
给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。
假设每一种面额的硬币有无限个。
 */

/*
 解题思路：
 1.首先确定dp数组及其下标的含义：
 dp[i][j]表示使用0~i的硬币凑成总金额j有dp[i][j]种方法
 2.递推公式推导:
 dp[i][j]有两种情况，一种是不取第i个硬币，然后是取第i个硬币
 dp[i][j] = dp[i-1][j] + dp[i][j - coin[i]];
 即dp[i][j]是两种方法的总和
 */

class Solution{
public:
    int solution(int amount,const vector<int>& coin,int W) {
        int dp[amount][W+1];

        //初始化最上面那一行
        //如果j可以整除coin[0]，就只有一种方法，其他情况方法为0
        for (int j = 0;j<=W;j++) {
         if (j%coin[0] == 0) dp[0][j] = 1;
        }

        //初始化最左边一行，即背包容量为0的情况（这个要根据题目条件具体分析）
        //装满背包容量为0的方法就是不装，所以为1
        for (int i = 0;i<amount;i++) {
            dp[i][0] = 1;
        }

        for (int i = 0;i<coin.size();i++) {
            for (int j = 0;j<=W;j++) {
                if (coin[i] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i][j-coin[i]];
            }
        }
        return dp[amount-1][W];
    }

    //一维dp的做法
    int solution2(int amount,const vector<int>& coin,int W) {
        vector<uint64_t> dp(amount + 1,0);
        dp[0] = 1;  //初始化，容量为0是方法数为1
        //这里确定遍历顺序的依据是，对两种情况进行分析，只有先遍历物品再遍历容量得到的是组合数
        //否则会得到排列数
        for (int i = 0;i<coin.size();i++) {     //遍历物品
            for (int j = coin[i];j<=amount;j++) {    //遍历容量
                d[j] += dp[i-coin[i]];
            }
        }
        return dp[amount];
    }
};

int main(){

}