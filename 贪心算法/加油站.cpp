 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

 */

class Solution{
public:
    //暴力做法
    int solution1 (vector<int>& gas,vector<int>& cost) {
        for (int i = 0;i < cost.size();i++) {
            int rest = gas[i] - cost[i];    //先得到开头的初始油量
            int index = (i + 1) % cost.size();  //计算下一个下标
            while (rest > 0 && index != i) { //剩余油量不足或者已经到达了终点才停止循环
                rest += gas[index] - cost[index];   //计算总油量
                index = (index + 1) % cost.size();  //计算下一个下标
            }
            //如果跑到i了rest还>0，则回到了原点i
            if (rest >= 0 && index = i) return i;
        }
        return -1;
    }

    int solution2 (vector<int>& gas,vector<int>& cost) {

    }
};

int main(){

}