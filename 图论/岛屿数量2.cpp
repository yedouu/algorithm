#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
 解题思路：
 把深搜换成广搜就行了
 */

int dir[4][2]{0,1,1,0,-1,0,0,-1};
void bfs(const vector<vector<int> > &grid,vector<vector<bool>>& visited,int x,int y) {
    //定义待处理节点队列
    queue<pair<int,int>> que;
    que.push(make_pair(x,y));   //加入最初的节点
    visited[x][y]=true; //只要加入队列了就要立马标记为访问过

    while (!que.empty()) {  //只要队列不为空就一直执行
        //取出队列中的元素
        pair<int,int> cur = que.front();
        que.pop();

        int curx = cur.first;
        int cury = cur.second;

        //向四个方向搜索
        for (int i = 0;i < 4;i++) {
            int nx = curx+dir[i][0];
            int ny = cury+dir[i][1];
            //检查坐标合法性
            if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) continue;

            //如果是没访问过的陆地就加入待处理队列，并标记为已处理
            if (!visited[nx][ny] && grid[nx][ny] == 1) {
                que.push(make_pair(nx,ny));
                visited[nx][ny]=true;
            }
        }
    }
}


int main() {    //主函数部分和《岛屿数量1》一样
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                result++; // 遇到没访问过的陆地，+1
                bfs(grid, visited, i, j); // 将与其链接的陆地都标记上 true
            }
        }
    }


    cout << result << endl;

    return 0;
}