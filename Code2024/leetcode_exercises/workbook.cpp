//代码段集合

#include <iostream>
using namespace std;

//字符串相加

class Solution {
public:
    string addStrings(string num1, string num2)
    {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int carry_bit = 0;  //进位

        string strRet;

        //提前算出大小
        strRet.reserve(num1.size() > num2.size() ? num1.size() + 1 : num2.size() + 1);

        while (end1 >= 0 || end2 >= 0)
        {
            int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
            int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
            int ret = val1 + val2 + carry_bit;
            carry_bit = ret / 10;
            ret = ret % 10;

            strRet += ('0' + ret);

            --end1;
            --end2;
        }
        if (carry_bit == 1)
        {
            strRet += '1';
        }

        reverse(strRet.begin(), strRet.end());

        return strRet;
    }
};

//统计范围内的元音字符串数
class Solution {

public:

    int vowelStrings(vector<string>& words, int left, int right) {

        unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u' };

        int ans = 0;

        for (int i = left; i <= right; ++i) {

            const string& word = words[i];

            if (vowels.count(word[0]) && vowels.count(word.back())) {

                ++ans;

            }

        }
        return ans;
    }
};


//仅仅反转字母
class Solution
{
public:

    bool isLetter(char ch)
    {
        if (ch >= 'a' && ch <= 'z')
            return true;
        if (ch >= 'A' && ch <= 'Z')
            return true;

        return false;
    }

    string reverseOnlyLetters(string s)
    {
        size_t begin = 0, end = s.size() - 1;
        while (begin < end)
        {
            while (begin < end && !isLetter(s[begin]))
                ++begin;

            while (begin < end && !isLetter(s[end]))
                --end;

            swap(s[begin], s[end]);
            ++begin;
            --end;
        }
        return s;
    }
};