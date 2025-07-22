#include <iostream>
#include <vector>

/*
 题目描述：
给定一个由 1（陆地）和 0（水）组成的矩阵，你需要计算岛屿的数量。岛屿由水平方向或垂直方向上相邻的陆地连接而成，并且四周都是水域。你可以假设矩阵外均被水包围。

输入描述：

第一行包含两个整数 N, M，表示矩阵的行数和列数。

后续 N 行，每行包含 M 个数字，数字为 1 或者 0。

输出描述：

输出一个整数，表示岛屿的数量。如果不存在岛屿，则输出 0。
 */


/*
 思路：
 遍历地图中的陆地区域，如果遇到没有访问到的区域，就以此为起点使用dfs来标注与其相连的陆地区域，然后ans++
 */



using namespace std;

int dir[4][2]{0,1,1,0,-1,0,0,-1};   //四个方向
void dfs(const vector<vector<int>>& grid,vector<vector<bool>>&  visited,int x,int y) {
    for (int i = 0;i < 4;i++) {
        //获得新坐标
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];

        //检查坐标合法性
        if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) continue;

        //如果没有访问过且是陆地
        if (!visited[nx][ny] && grid[nx][ny] == 1) {
            visited[nx][ny] = true;
            dfs(grid,visited,nx,ny);
        }
    }
}

int main() {

    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,0));   //n*m的vector
    for (int i = 0;i<n;i++) {       //建立地图
        for (int j = 0;j<m;j++) {
            cin>>grid[i][j];
        }
    }

    //建立一个访问表
    vector<vector<bool>> visited(n,vector<bool>(m,false));

    //遍历地图中的所有陆地
    int result = 0;
    for (int i = 0;i<n;i++) {
        for (int j = 0;j<m;j++) {
            //如果没有访问过，而且是陆地
            if (!visited[i][j]&&grid[i][j]==1) {
                //设置为访问过
                visited[i][j] = true;
                result ++;  //没访问过的板块+1
                dfs(grid,visited,i,j);  //标记与其连通的陆地部分
            }
        }
    }

    cout<<result<<endl;

    return 0;
}
