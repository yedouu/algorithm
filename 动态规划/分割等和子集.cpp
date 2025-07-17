 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
  题目描述：
    给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

    注意: 每个数组中的元素不会超过 100 数组的大小不会超过 200

    示例 1:

    输入: [1, 5, 11, 5]
    输出: true
    解释: 数组可以分割成 [1, 5, 5] 和 [11].
    示例 2:

    输入: [1, 2, 3, 5]
    输出: false
    解释: 数组不能分割成两个元素和相等的子集.
    提示：

    1 <= nums.length <= 200
    1 <= nums[i] <= 100
 */

/*
 本题的意义：
背包问题，不仅可以求背包能装的最大价值，还可以求这个背包是否可以装满。
 */


/*
 先确定重量和价值对应的含义：
本题要求集合里能否出现总和为 sum / 2 的子集,即 重量等于价值;
如果最大价值是 sum / 2，说明正好被商品装满了。
 */

/*

 */


class Solution{
public:
    bool solution(const vector<int>& nums) {
        //先计算总和
        int sum = 0;
        for (int i=0;i<nums.size();i++) {
         sum += nums[i];
        }
        if (sum % 2 == 1) return false;  //总和为奇数，不能平分
        int target = sum/2;

        int dp[100001];  //背包的容量和价值等价，所以取所有元素之和的一半；

        for (int i = 0;i < nums.size();i++) {
            for (int j = target;j >= nums[i];j--) {
             dp[j] = max(dp[j],dp[j-nums[i]]+nums[i]);
            }
        }
        if (dp[target] == target) return true;
        return false;
    }
};

int main(){

}