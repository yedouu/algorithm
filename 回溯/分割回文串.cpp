#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> result;
vector<string> path;

bool check(string s,int startIndex,int i) {
    //思路：
    /*
     使用双指针，一个指向字符串头部，一个指向字符串尾部（不一定是指针，也可以是下标）
     */
    //先截取这一部分字符
    string str = s.substr(startIndex,i - startIndex + 1);
    //计算字符串长度
    int len = str.length();
    int l = 0,r = len - 1;
    while (l <= r) if (str[l++] != str[r--]) return false;
    return true;
}

void solve(const string& s,int startIndex) {
    //起始位置大于字符串大小时退出
    if (startIndex >= s.length()) {
        //将结果加入result
        result.push_back(path);
        return ;
    }
    for (int i=startIndex; i<s.length(); i++) {
        //先判断从startIndex到i的字符字串是否是回文串
        if (check(s,startIndex,i)) {
            //截取这一部分字符串
            string str = s.substr(startIndex,i-startIndex+1);   //第二个参数是截取个数
            path.push_back(str);
        } else {    //不是回文串
            continue;
        }
        //找到回文串后，以下一个位置为起始点继续寻找
        solve(s,i+1);
        path.pop_back();    //回溯，弹出本次添加的子串
    }

}

int main()
{
    string s;
    getline(cin,s);
    solve(s,0);

    for (auto i:result) {
        for (auto j:i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;

}