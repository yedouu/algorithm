#include <iostream>

using namespace std;

void test(int n) {
    int p = 1;
    int arr[n][n];
    for (int i = 0;i < (n+1)/2;i++) {
        if (i == (n+1)/2-1 && i%2==0) arr[n/2][n/2] = n*n;
        else {
            //上
            for (int j = 0+i;j < n-1-i;j++) {
                arr[i][j] = p++;
            }

            //右
            for (int j = 0+i;j < n-1-i;j++) {
                arr[j][n-i-1] = p++;
            }

            //下
            for (int j = n-1-i;j >=0+i+1;j--) {
                arr[n-i-1][j] = p++;
            }

            //左
            for (int j = n-1-i;j >=0+i+1;j--) {
                arr[j][0+i] = p++;
            }
        }
    }
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){

    test(12);
    return 0;
}