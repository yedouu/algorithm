#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;     //定义一个栈
        for (char c : s) {
            //遍历字符串里每个字符，如果是左括号就压入栈中
            if (c == '(' || c == '{' || c == '[') st.push(c);
            else {
                //如果是右括号就从栈中弹出一个字符并与新字符进行匹配
                //这里还要先判空，防止右括号先进入匹配
                if (st.empty()) return false;

                char p = st.top();
                st.pop();
                //匹配成功了就下一个
                if (p == '(' && c == ')') continue;
                if (p == '{' && c == '}') continue;
                if (p == '[' && c == ']') continue;
                //否则就返回false
                return false;
            }
        }
        if (!st.empty()) return false;
        return true;
    }
};


int main() {
    string s = "([)]";
    Solution test;
    if (test.isValid(s)) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}