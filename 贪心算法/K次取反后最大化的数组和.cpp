 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

 */

class Solution{
static bool cmp(int a,int b) {
    return abs(a) > abs(b);     //将数组按照绝对值大小从大到小排序，这样在反转所有负数后若K仍然>0时可以直接反转绝对值最小的数
}
public:
    int solution(vector<int>& A,int K) {
        sort(A.begin(),A.end(),cmp);
        for (int i=0;i<A.size();i++) {  //处理负数（按照绝对值从大到小）
            if (A[i] < 0 && K > 0) {
                A[i] *= -1;
                K--;
            }
        }

        if (K % 2 == 1) A[A.size()-1] *= -1;    //K很大的话，用来处理绝对值最小的数以保证和最大
        int result = 0;
        for (int a : A) result += a;
        return result;
    }
};

int main(){

}