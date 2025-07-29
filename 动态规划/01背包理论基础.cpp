 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 题目描述：
有n件物品和一个最多能背重量为w 的背包。第i件物品的重量是weight[i]，得到的价值是value[i] 。
每件物品只能用一次，求解将哪些物品装入背包里物品价值总和最大。
 */

/*
 dp[i][j]含义：下标[0,i]的物品任取放进容量为j的背包里
 不放物品i：dp[i-1][j] ,即从0~i-1个物品任取，不取第i的物品，所以容量也为j;
 放物品i：dp[i-1][j-weight[i]]+value[i],即放入物品i，容量减去weight[i],同时加上i的价值，然后再从0~i-1的物品中任取
 递推公式：dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i])
 */

/*
 dp数组初始化：
第一列初始化为0，因为背包容量为0的时候能装的价值为0；
第一行根据背包能不能装下第一个物品来初始化；
 */

/*
 遍历顺序：第一层遍历物品，第二层遍历背包容量（反过来也行，和反过来能不能推出下一项有关）
 */

/*
 01背包问题的步骤总结:
 1.确定dp数组以及下标的含义
 2.确定递推公式
 3.完成dp数组的初始化
 4.确定遍历顺序
 5.举例推导dp数组
 */

class Solution{
public:
    int solution(const vector<int> &weight,const vector<int> &value,int bagsweight) {
        int dp[weight.size()][bagsweight];
        //初始化
        for (int i = 0; i < weight.size(); i++) {
         dp[i][0] = 0;
        }
        for (int i = 0; i < bagsweight; i++) {
         if (i >= weight[0]) dp[0][i] = value[0];
        }

        //开始递推
        for (int i = 0; i < weight.size(); i++) {  //遍历物品
            for (int j = 0; j <= bagsweight; j++) {   //遍历背包容量
                //判断背包是否装得下这个物品
                 if (j < weight[i]) dp[i][j] = dp[i-1][j];  //装不下就继承上一个的价值
                 else {
                  dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);   //最重要的递推公式
                 }
            }
        }

        cout<< dp[weight.size()-1][bagsweight] << endl;  //打印出右下角的价值（最大）
    }
    //使用滚动数组完成01背包问题
    int solution2(const vector<int> &weight,const vector<int> &value,int bagsweight) {
        int dp[bagsweight];
        //初始化
        for (int i = 0; i < bagsweight; i++) {
         if (i >= weight[0]) dp[i] = value[0];
        }

        //开始递推
        for (int i = 0; i < weight.size(); i++) {  //遍历物品
         for (int j = bagsweight; j >= weight[i]; j--) {   //遍历背包容量，这里只能用倒序，因为需要用到左边的格子，所以只能先更新右边的
          //另外由于在同一轮循环中j减小而weight[i]不变，所以当出现j<weight[i]时即可停止这一轮，减少讨论的次数
          dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);   //最重要的递推公式
         }
        }

        cout<< dp[bagsweight] << endl;  //打印出右下角的价值（最大）
    }
};

int main(){

}