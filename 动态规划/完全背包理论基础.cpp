 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
问题描述：
有N件物品和一个最多能背重量为W的背包。第i件物品的重量是weight[i]，
得到的价值是value[i] 。每件物品都有无限个（也就是可以放入背包多次），
求解将哪些物品装入背包里物品价值总和最大。
 */

/*
 1.dp数组含义：dp[i][j]表示从下标0~i的物品放入容量为j的背包中（每种物品数量无限）
 2.递推公式推导：
dp[i][j]有两种情况：1.放入物品i；2.不放入物品i
如果放入物品i，则有dp[i][j-weight[i]]+value[i]，因为可以重复取，所以第一个下标不减1
如果不放入物品i，则只考虑i之前的物品的情况，即dp[i-1][j];
所以dp[i][j]=max(dp[i-1][j],dp[i][j-weight[i]]+value[i])
 */

class Solution{
public:
    int solution(const vector<int>& weight,const vector<int>& value,int W) {

    }

};

int main(){

}