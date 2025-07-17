#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>
using namespace std;

/*
 思路：
 要选取出和最大的连续子序列，使用贪心思想的话就应该让前面的和尽量不为负的，不然会拖累后面的数；
 因此实现思路就是不断累加，如果和为负数就舍弃这段，以达到和最大的目的

 */

class Solution{
public:
    int solution(vector<int>& nums) {
        int result = INT32_MIN;
        int count = 0;
        for (int i = 0; i < nums.size() ; i++) {
            count += nums[i];
            if (count > result) {
                result = count;
            }

            if (count <= 0) {
                count = 0;
            }

        }
        return result;
    }
};

int main(){

}