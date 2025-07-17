#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 思路：
 prices[3] - prices[0] = (prices[3] - proces[2])+(prices[2] - prices[1])+(prices[1] - prices[0])
 即可以将利润分割成每两天的后一天减去前一天的利润的总和，因此我们只要取每个利润为正的那一天进行买卖就行了
 */

class Solution{
public:
    int solution(vector<int>& prices) {
        int result = 0;
        for (int i=1;i < prices.size();i++) {
            result += max(prices[i] - prices[i-1], 0);
        }
        return result;
    }
};

int main(){

}