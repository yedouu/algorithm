#include <iostream>
#include <vector>

/*
 题目描述：
现有一个 N × M 的矩阵，每个单元格包含一个数值，这个数值代表该位置的相对高度。矩阵的左边界和上边界被认为是第一组边界，而矩阵的右边界和下边界被视为第二组边界。

矩阵模拟了一个地形，当雨水落在上面时，水会根据地形的倾斜向低处流动，但只能从较高或等高的地点流向较低或等高并且相邻（上下左右方向）的地点。我们的目标是确定那些单元格，从这些单元格出发的水可以达到第一组边界和第二组边界。

输入描述：

第一行包含两个整数 N 和 M，分别表示矩阵的行数和列数。

后续 N 行，每行包含 M 个整数，表示矩阵中的每个单元格的高度。

输出描述：

输出共有多行，每行输出两个整数，用一个空格隔开，表示可达第一组边界和第二组边界的单元格的坐标，输出顺序任意。
 */


/*
 暴力思路：
遍历每个点，然后看这个点 能不能同时到达第一组边界和第二组边界
整体时间复杂度 就是 O(m^2 * n^2) ，这是一个四次方的时间复杂度

 优化思路：
从第一组边界上的节点 逆流而上，将遍历过的节点都标记上;同样从第二组边界的边上节点 逆流而上，将遍历过的节点也标记上;
然后两方都标记过的节点就是既可以流向第一组边界也可以流向第二组边界的节点。
时间复杂度粗略计算是： (m * n) * (m + n)
但是在firstBorder和secondBorder中，每个节点只会被访问一次，所以实际上是2*n*m，所以最终时间复杂度是O(n * m)，
即利用所求节点应该是能从第一和第二边界到达的特性，减少了第一层循环的复杂度。
 */


using namespace std;

int n,m;
int dir[4][2]{-1,0,0,-1,1,0,0,1};
void dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int x,int y) {
    if (visited[x][y]) return; //这个点已经访问过了

    visited[x][y]=true; //将这个点标记

    for (int i = 0;i < 4;i++) {
     int nx = x + dir[i][0];
     int ny = y + dir[i][1];
     //检查坐标合法性
     if (nx < 0 || nx >= n ||ny < 0 || ny >= m) continue;
     //从低到高遍历
     if (grid[x][y] > grid[nx][ny]) continue;

     dfs(grid,visited,nx,ny);
    }
}



int main() {

    cin >> n >> m;
    vector<vector<int>> grid(n,vector<int>(m,0));

    for (int i = 0;i<n;i++) {
     for (int j = 0;j<m;j++) {
      cin >> grid[i][j];
     }
    }

    //标记从第一边界出发可以到达的点
    vector<vector<bool>> firstBorder(n,vector<bool>(m,false));

    //标记从第二边界出发可以到达的点
    vector<vector<bool>> secondBorder(n,vector<bool>(m,false));

    //从最上面和最下面的节点出发遍历
    for (int i = 0;i<n;i++) {
        dfs(grid,firstBorder,i,0); //最左边的一列
        dfs(grid,secondBorder,i,m-1); //最右边的一列
    }

    //从最左边和最右边的节点出发遍历
    for (int i = 0;i<m;i++) {
        dfs(grid,firstBorder,0,i);
        dfs(grid,secondBorder,n-1,i);
    }

    //寻找同时被标记的节点
    for (int i = 0;i<n;i++) {
     for (int j = 0;j<m;j++) {
      if (firstBorder[i][j] && secondBorder[i][j]) cout<< i <<" "<<j<<endl;
     }
    }


    return 0;
}