#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> result;
vector<string> path;
int num = 0;
void solve(const string& s,int startIndex) {
    //如果超过了4段就返回
    if (path.size() >4) return ;
    //如果是4段IP就可以通过
    if (path.size() == 4 && startIndex >= s.length()) {
        cout<<"find!"<<endl;
        string str = path[0] + "." + path[1] + "." + path[2] + "." + path[3];
        result.push_back(str);
        return ;
    }

    for (int i = startIndex; i < s.size(); i++) {
        //先截取一段字符串
        //处理前导0的情况,单独成一段
        // cout<< s.substr(startIndex,i - startIndex + 1) << endl;
        if (i - startIndex + 1 >=2 && s[startIndex] == '0') return ;
        //然后处理三位数的情况
        else {
            if ( i - startIndex + 1 == 3) {
                //判断是否大于255
                if (s.substr(startIndex, 3) > "255") return ;
                else {
                    string str = s.substr(startIndex,3);
                    path.push_back(str);
                }
            }
            else if ( i - startIndex +1 > 3) return ;
            else {
                // cout<<"size < 2"<<endl;
                string str = s.substr(startIndex, i + 1 - startIndex);
                path.push_back(str);
            }
        }
        solve(s,i + 1);
        path.pop_back();
    }
}

int main()
{
    string s;
    cin >> s;
    solve(s, 0);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;

}