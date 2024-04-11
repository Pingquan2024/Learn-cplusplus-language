//#include <stdio.h>
//#include <stdbool.h>
//#include <string.h>
//
//bool cmpp(char a)
//{
//    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
//    {
//        return true;
//    }
//    return false;
//}
//
//int vowelStrings(char** words, int wordsSize, int left, int right)
//{
//    int i, j;
//    int len;
//    int output = 0;
//
//    for (i = left; i <= right; ++i)
//    {
//        len = strlen(words[i]);
//        if (cmpp(words[i][0]) && cmpp(words[i][len - 1]))
//        {
//            output++;
//        }
//    }
//
//    return output;
//}
//
//int main()
//{
//    char* word[][1] = { "are","amy","u" };
//    vowelStrings(&word, 2, 1, 100);
//    return 0;
//}

#include <iostream>
//#include <string>
using namespace std;

class Solution
{
public:
	
	int firstUniqChar(string s)
	{
		int countA[26] = { 0 };

		//出现次数就统计出来了
		for (auto ch : s)
		{
			countA[ch - 'a']++;
		}

		for (int i = 0; i < s.size(); i++)
		{
			if (countA[s[i] - 'a'] == 1)
				return 1;
		}
		return -1;
	}
};



int main()
{
	Solution solution;
	string input = "leetcode";
	int result = solution.firstUniqChar(input);
	cout << "First unique character index: " << result <<endl;
	return 0;
}