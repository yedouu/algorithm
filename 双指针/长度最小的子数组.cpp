#include <iostream>
using namespace std;

int test(int s,int arr[],int size) {
    int p1 = 0,p2 = 0;
    int result = INT_MAX;
    int sum = 0;
    for (;p2<size;p2++) {   //移动窗口末端
        sum+=arr[p2];
        while (sum>=s) {    //满足子串条件
            int length = p2 - p1 + 1;
            result = result < length ? result : length;
            sum -= arr[p1++];   //移动窗口左端
        }
    }
    return result == INT_MAX ? 0 : result;
}

int main(){

    int num[] = {2,3,1,2,4,3};
    cout<<test(7,num,6);
    return 0;

}