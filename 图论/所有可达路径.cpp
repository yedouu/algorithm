//邻接矩阵做法
// #include <iostream>
// #include <vector>
//
// using namespace std;
//
// /*
//  题目描述：
// 给定一个有 n 个节点的有向无环图，节点编号从 1 到 n。请编写一个程序，找出并返回所有从节点 1 到节点 n 的路径。
// 每条路径应以节点编号的列表形式表示。
//
// 第一行包含两个整数 N，M，表示图中拥有 N 个节点，M 条边，
// 后续 M 行，每行包含两个整数 s 和 t，表示图中的 s 节点与 t 节点中有一条路径。
//
// 输出所有的可达路径，路径中所有节点的后面跟一个空格，每条路径独占一行，存在多条路径，路径输出的顺序可任意。
// 如果不存在任何一条路径，则输出 -1。
// 注意输出的序列中，最后一个节点后面没有空格！ 例如正确的答案是 1 3 5,而不是 1 3 5， 5后面没有空格！
//  */
//
// vector<vector<int>> result; //收集符合条件的路径
// vector<int> path;
//
// void dfs(const vector<vector<int>>& graph,int x,int n) {
//     //1.结束条件
//     if (x == n) {
//         result.push_back(path);
//         return ;
//     }
//
//     //2.处理节点
//     for (int i = 1; i <= n; i++) {
//         if (graph[x][i] == 1) { //确认是否有连接
//             path.push_back(i);  //将该节点加入路径中
//             dfs(graph,i,n);   //进入下一层遍历
//             path.pop_back();    //回溯
//         }
//     }
// }
//
// int main() {
//     int n,m,s,t;
//     cin>>n>>m;
//
//     // 节点编号从1到n，所以申请 n+1 这么大的数组
//     vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
//
//     while (m--) {
//         cin >> s >> t;
//         // 使用邻接矩阵 表示无线图，1 表示 s 与 t 是相连的
//         graph[s][t] = 1;
//     }
//
//     path.push_back(1); // 无论什么路径已经是从0节点出发
//     dfs(graph, 1, n); // 开始遍历
//
//     // 输出结果
//     if (result.size() == 0) cout << -1 << endl;
//     for (const vector<int> &pa : result) {
//         for (int i = 0; i < pa.size() - 1; i++) {
//             cout << pa[i] << " ";
//         }
//         cout << pa[pa.size() - 1]  << endl;
//     }
//
//     return 0;
// }


//邻接表做法
#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<vector<int>> result;
vector<int> path;

void dfs(const vector<list<int>>& graph,int x,int n) {
    //1.结束条件
    if (x == n) {
        result.push_back(path);
        return;
    }

    for (int i : graph[x]) {
        path.push_back(i);
        // cout<<i<<endl;
        dfs(graph,i,n);
        path.pop_back();
    }
}

int main() {
    int n,m,s,t;
    cin>>n>>m;

    vector<list<int>> graph(n+1);   //申请了n+1个列表
    while (m--) {
        cin>>s>>t;
        //使用邻接表 ，表示 s -> t 是相连的
        graph[s].push_back(t);
    }

    path.push_back(1);  //从节点1开始出发
    dfs(graph,1,n); //开始遍历

    // 输出结果
    if (result.size() == 0) cout << -1 << endl;
    for (const vector<int> &pa : result) {
        for (int i = 0; i < pa.size() - 1; i++) {
            cout << pa[i] << " ";
        }
        cout << pa[pa.size() - 1]  << endl;
    }

    return 0;

}