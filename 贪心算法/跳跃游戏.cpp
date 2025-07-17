#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int solution(vector<int>& nums) {
        int cover = 0;  //目前跳跃能够覆盖到的范围
        if (nums.size() == 1) return true;
        for (int i = 0;i<= cover;i++) {     //在目前能够到的范围内遍历，所以范围限制为cover
            cover = max(i+nums[i],cover);   //更新覆盖范围，取当前范围和目前格子大小与最大跳跃距离之和的更大的那一个
            if (cover >= nums.size() - 1) return true;
        }
        return false;
    }
};

int main(){

}