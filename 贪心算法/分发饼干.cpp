#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int solution1(vector<int>& g,vector<int>& s){
        //给孩子的胃口和饼干尺寸排序
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int index = s.size()-1;
        int result  = 0;
        for (int i=g.size()-1;i>=0;i--) {
            if (index >= 0 && s[index] >= g[i]) {
                result++;
                index--;
            }
        }
        return result;
    }

    int solution2(vector<int>& g,vector<int>& s) {  //这种写法在最后一个人胃口很大时会导致双方一直匹配不上
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int result = 0;
        int index = g.size()-1;
        for (int i=s.size()-1;i>=0;i--) {
            if (index >= 0 && s[i] >= g[index]) {
                result++;
                index--;
            }
        }
    }
};

int main(){

}