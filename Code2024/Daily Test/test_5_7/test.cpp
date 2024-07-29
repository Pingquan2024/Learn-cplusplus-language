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
        // ����һ������ӳ�䣬��ÿ��������һ������ӳ�����������ں���ƥ������
        unordered_map<char, int> m{ {'(',1},{'[',2},{'{',3},
                                {')',4},{']',5},{'}',6} };
        // ����һ��ջ���ڴ洢������
        stack<char> st;
        // ��ʼ��һ������ֵ�����ڱ�ʾ�����Ƿ�ƥ��
        bool istrue = true;
        // ����������ַ���
        for (char c : s)
        {
            // ����ӳ���ҵ���ǰ�ַ���Ӧ������
            int flag = m[c];
            // ����������ţ�ѹ��ջ��
            if (flag >= 1 && flag <= 3)
                st.push(c);
            // �������������ջ�в�Ϊ�գ�����ջ�����������뵱ǰ������ƥ�䣬��ջ��Ԫ�ص���
            else if (!st.empty() && m[st.top()] == flag - 3)
                st.pop();
            // �����������������������ʾ���Ų�ƥ�䣬�� istrue ��Ϊ false ������ѭ��
            else
            {
                istrue = false;
                break;
            }
        }
        // ѭ�����������ջ�л���ʣ��������ţ����ʾ���Ų�ƥ��
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