#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    const string lettermap[10] = {
    "","","abc","def","ghi","jkl",
        "mno","pqrs","tuv","wxyz"
    };

    vector<string> result;  //保存结果
    string s;   //保存每次得出的结果
    void backtracking(const string& digits, int index) {
        //如果回溯的层数等于数字字符串的size就停止
        if (index == digits.length()) {
            result.push_back(s);
            return;
        }

        //得出对应的数字编号
        int num = digits[index] - '0';
        string letter = lettermap[num];
        for (int i = 0;i < letter.length();i++) {
            s.push_back(letter[i]);     //加入新字母
            backtracking(digits, index + 1);    //进入下一层
            s.pop_back();   //取消然后回溯
        }
    }


    vector<string> letterCombinations(string digits) {
        s.clear();
        result.clear();
        if (digits.length() == 0) return result;
        backtracking(digits, 0);
        return result;
    }


};

int main() {


    return 0;
}