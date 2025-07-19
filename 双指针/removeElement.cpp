#include <iostream>

//双指针

using namespace std;

int removes(int *arr,int val,int size) {
    int slow = 0;
    for (int fast = 0; fast < size; fast++) {
        //快指针值不等于val就赋值(val不属于新数组)
        if (arr[fast] != val ) {
            arr[slow++] = arr[fast];
        }
        //不相等fast会继续自增，直到找到符合新数组的值
    }
    return slow;//返回新数组的大小
}

void printResult(int *arr,int size) {
    for (int i=0 ; i<size ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int size = 0;
    int arr1[] = {3,2,2,3};
    size = removes(arr1,2,4);
    cout<<"size is:"<<size<<endl;
    printResult(arr1,size);

    int arr2[] = {0,1,2,3,3,0,4,2};
    size = removes(arr2,2,8);
    cout<<"size is:"<<size<<endl;
    printResult(arr2,size);
    return 0;
}