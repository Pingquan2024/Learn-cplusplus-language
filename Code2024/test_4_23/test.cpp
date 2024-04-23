#include <iostream>
using  std::cout;

int main()
{

	char str1[] = "leetcode";
	//char str2[] = {"leetcode"};
	cout << str1 << endl;

	str1[3]++;
	cout << str1 << endl;

	str1[1]++;
	cout << str1 << endl;

	str1[5]--;
	cout << str1 << endl;
}