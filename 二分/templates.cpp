#include <iostream>

using namespace std;

//使用条件，数组升序、没有重复的数(左闭右闭)
int binary_serach(const int* arr,int start,int end,int key) {
    int ret = -1;
    int mid;
    while (start <= end) {  //左闭右开这里改为start < end
        mid = start + ((end - start) >> 1);  //防止溢出
        if (arr[mid] < key)
            start = mid + 1;
        else if (arr[mid] > key)
            end = mid - 1;  //左闭右开这里改为mid
        else {
            ret = mid;
            break;
        }
    }
    return ret;
}

//二分答案（luogu P1873）


//STL二分查找

int main() {

    int arr[] = {1,3,4,6,7,
        9,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 3;
    cout << binary_serach(arr, 0, n-1, key) << endl;

    return 0;
}