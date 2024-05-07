#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        // 创建一个无序映射，将每个括号与一个整数映射起来，用于后面匹配括号
        unordered_map<char, int> m{ {'(',1},{'[',2},{'{',3},
                                {')',4},{']',5},{'}',6} };
        // 创建一个栈用于存储左括号
        stack<char> st;
        // 初始化一个布尔值，用于表示括号是否匹配
        bool istrue = true;
        // 遍历输入的字符串
        for (char c : s)
        {
            // 根据映射找到当前字符对应的整数
            int flag = m[c];
            // 如果是左括号，压入栈中
            if (flag >= 1 && flag <= 3)
                st.push(c);
            // 如果是右括号且栈中不为空，并且栈顶的左括号与当前右括号匹配，则将栈顶元素弹出
            else if (!st.empty() && m[st.top()] == flag - 3)
                st.pop();
            // 如果不是上述两种情况，则表示括号不匹配，将 istrue 设为 false 并跳出循环
            else
            {
                istrue = false;
                break;
            }
        }
        // 循环结束后，如果栈中还有剩余的左括号，则表示括号不匹配
        if (!st.empty())
            istrue = false;

        return istrue;
    }
};

int main()
{
    Solution sl;
    bool istrue=sl.isValid("{[(])]}");
    cout <<istrue<< endl;

    return 0;
}