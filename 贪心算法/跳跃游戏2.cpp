#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

 */

class Solution{
public:
    int solution(vector<int>& nums) {
        if (nums.size() == 1) return 0; //一步都不用走
        int cur = 0;    //当前覆盖最远距离
        int next = 0;   //下一步覆盖最远距离
        int ans = 0;    //结果
        for (int i = 0; i < nums.size(); i++) { //因为题目说一定可以到达终点，所以遍历范围可以设置为整个数组
            next = max(nums[i] + i,next);   //更新下一步覆盖最远距离
            if (i == cur) { //走到当前覆盖最远距离时需要往前走一步
                ans++;
                cur = next; //更新当前覆盖最远距离
                if (next >= nums.size() - 1) break; //已经走到终点了就结束
            }
        }
        return ans;
    }
};

int main(){

}