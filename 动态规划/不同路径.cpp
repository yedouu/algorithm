 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

 */

class Solution{
public:
    int solution(int m,int n) {
        int path[m][n];
        path[0][0] = 1; //初始化起点
        for (int i=0;i<m;i++) path[i][0] = 1;//初始化只有一种路径的情况
        for (int j=1;j<n;j++) path[0][j] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                path[i][j] = path[i-1][j] + path[i][j-1];
            }
        }
        return path[m-1][n-1];
    }
};

int main(){
    Solution s;
    cout<<s.solution(3,3);
}